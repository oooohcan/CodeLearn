package org.oooohcan.matchback.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import org.apache.commons.lang3.ArrayUtils;

import org.apache.commons.math3.util.Pair;
import org.oooohcan.matchback.common.ErrorCode;
import org.oooohcan.matchback.constant.UserConstant;
import org.oooohcan.matchback.exception.BusinessException;
import org.oooohcan.matchback.model.domain.User;
import org.oooohcan.matchback.service.UserService;
import org.oooohcan.matchback.mapper.UserMapper;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.StringUtils;
import org.oooohcan.matchback.utils.AlgorithmUtils;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;
import org.springframework.util.DigestUtils;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

import static org.oooohcan.matchback.constant.UserConstant.*;

/**
* @author oooohcan
* @description 针对表【user(用户)】的数据库操作Service实现
* @createDate 2022-07-04 21:19:45
*/
@Service
@Slf4j
public class UserServiceImpl extends ServiceImpl<UserMapper, User>
    implements UserService{

    @Resource
    private UserMapper userMapper;

    /**
     * 盐值，混淆原密码
     */
    private static final String SALT = "SydZh";

    @Override
    public long userRegister(String userAccount, String userPassword, String checkPassword,String inviteCode) {
        //1、校验
        if(StringUtils.isAnyBlank(userAccount,userPassword,checkPassword,inviteCode)){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"参数为空");
        }
        if(userAccount.length()<4){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"用户账号过短");
        }
        if(userPassword.length()<8 || checkPassword.length()<8){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"用户密码过短");
        }
        if(!ArrayUtils.contains(INVITE_CODE_LIST,inviteCode)){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"无效邀请码");
        }
        //账户不能包含特殊字符
        String validPattern = "[`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。，、？]";
        Matcher matcher = Pattern.compile(validPattern).matcher(userPassword);
        if(matcher.find()){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"账户包含特殊字符");
        }
        //账户不能重复
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("userAccount",userAccount);
        long count = this.count(queryWrapper);
        if(count > 0){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"账户重复");
        }
        //密码与校验密码相同
        if(!userPassword.equals(checkPassword)){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"两次密码不同");
        }
        //2、加密
        String encryptPassword = DigestUtils.md5DigestAsHex((SALT+userPassword).getBytes());
        //3、插入数据
        User user = new User();
        user.setUserAccount(userAccount);
        user.setUserPassword(encryptPassword);
        user.setInviteCode(inviteCode);
        boolean saveResult = this.save(user);
        if(!saveResult){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"数据插入失败");
        }
        return 1;
    }

    @Override
    public User userLogin(String userAccount, String userPassword,HttpServletRequest request) {
        //1、校验
        if(StringUtils.isAnyBlank(userAccount,userPassword))
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"账户或密码为空");
        if(userAccount.length() < 4)
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"账户长度小于4位");
        if(userPassword.length() < 8)
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"密码长度小于8位");
        //账户不能包含特殊字符
        String validPattern = "[`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~！@#￥%……&*（）——+|{}【】‘；：”“’。，、？]";
        Matcher matcher = Pattern.compile(validPattern).matcher(userPassword);
        if(matcher.find()){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"账户包含特殊字符");
        }
        //2、密码明文加密
        String encryptPassword = DigestUtils.md5DigestAsHex((SALT+userPassword).getBytes());
            //查询用户是否存，密码是否准确
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("userAccount",userAccount);
        queryWrapper.eq("userPassword",encryptPassword);
        User user = userMapper.selectOne(queryWrapper);
            //用户不存在
        if(user == null){
            log.info("user login failed, userAccount can not match userPassword ");
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"用户不存在");
        }
        //3、用户信息脱敏
        User saftyUser = getSafetyUser(user);

        //4、保存用户登录态
        request.getSession().setAttribute(USER_LOGIN_STATE,saftyUser);

        return saftyUser;
    }

    @Override
    public int userLogout(HttpServletRequest request) {
        //移除登录态
        request.getSession().removeAttribute(USER_LOGIN_STATE);
        return 1;
    }

    @Override
    public List<User> searchUser(String username, HttpServletRequest request) {
        if(!isAdmin(request)){
            throw new BusinessException(ErrorCode.NO_AUTH,"无管理员权限");
        }
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        if(StringUtils.isNotBlank(username)){
            queryWrapper.like("username",username);
        }
        List<User> userList = this.list(queryWrapper);
        return userList.stream().map(user -> getSafetyUser(user)).collect(Collectors.toList());
    }

    @Override
    public boolean deleteUser(long id,HttpServletRequest request) {
        if(!isAdmin(request)){
            throw new BusinessException(ErrorCode.NO_AUTH,"无管理员权限");
        }
        if(id < 0){
            throw new BusinessException(ErrorCode.PARAMS_ERROR,"Id小于0");
        }
        return this.removeById(id);
    }


    @Override
    public User getSafetyUser(User originUser){
        if(originUser == null){
            return null;
        }
        User saftyUser = new User();
        saftyUser.setId(originUser.getId());
        saftyUser.setUsername(originUser.getUsername());
        saftyUser.setUserAccount(originUser.getUserAccount());
        saftyUser.setAvatarUrl(originUser.getAvatarUrl());
        saftyUser.setGender(originUser.getGender());
        saftyUser.setPhone(originUser.getPhone());
        saftyUser.setEmail(originUser.getEmail());
        saftyUser.setUserStatus(originUser.getUserStatus());
        saftyUser.setUserRole(originUser.getUserRole());
        saftyUser.setCreateTime(originUser.getCreateTime());
        saftyUser.setInviteCode(originUser.getInviteCode());
        saftyUser.setTags(originUser.getTags());
        return saftyUser;
    }

    @Override
    public boolean isAdmin(HttpServletRequest request) {
        //用户鉴权，仅管理员可操作
        Object userObj = request.getSession().getAttribute(USER_LOGIN_STATE);
        User user = (User) userObj;
        return user != null && user.getUserRole() == ADMIN_ROLE;
    }

    /**
     * 是否为管理员
     *
     * @param loginUser
     * @return
     */
    @Override
    public boolean isAdmin(User loginUser) {
        return loginUser != null && loginUser.getUserRole() == UserConstant.ADMIN_ROLE;
    }


    @Override
    public List<User> searchUserByTagsByMemory(List<String> tagNameList){
        if(CollectionUtils.isEmpty(tagNameList)){
            throw new BusinessException(ErrorCode.PARAMS_ERROR);
        }
        // 1.先查询所有用户
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        List<User> userList = userMapper.selectList(queryWrapper);
        Gson gson = new Gson();
        // 2.在内存中判断是否包含要求的标签
        return userList.stream().filter(user -> {
            String tagStr = user.getTags();
            if(StringUtils.isBlank(tagStr)){
                return false;
            }
            // 反序列化：将json字节序列转为Set对象
            Set<String> userTagNameSet = gson.fromJson(tagStr,new TypeToken<Set<String>>(){}.getType());
            // 若有一个参数标签在用户标签中找不到，则该用户不符合
            for(String tagName : tagNameList){
                if(!userTagNameSet.contains(tagName)){
                    return false;
                }
            }
            return true;
        }).map(this::getSafetyUser).collect(Collectors.toList());
    }



    @Override
    public List<User> searchUserByTagsBySQL(List<String> tagNameList){
        if(CollectionUtils.isEmpty(tagNameList)){
            throw new BusinessException(ErrorCode.PARAMS_ERROR);
        }
        //数据库"and"查询：通过 like '%java%' and like '%hhh%'
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        for(String tagName : tagNameList){
            queryWrapper = queryWrapper.like("tags",tagName);
        }
        return userMapper.selectList(queryWrapper);
    }

    @Override
    public int updateUser(User user, User loginUser) {
        long userId = user.getId();
        if (userId <= 0) {
            throw new BusinessException(ErrorCode.PARAMS_ERROR);
        }
        // todo 补充校验，如果用户没有传任何要更新的值，就直接报错，不用执行 update 语句
        // 如果是管理员，允许更新任意用户
        // 如果不是管理员，只允许更新当前（自己的）信息
        if (!isAdmin(loginUser) && userId != loginUser.getId()) {
            throw new BusinessException(ErrorCode.NO_AUTH);
        }
        User oldUser = userMapper.selectById(userId);
        if (oldUser == null) {
            throw new BusinessException(ErrorCode.NULL_ERROR);
        }
        return userMapper.updateById(user);
    }

    @Override
    public User getLoginUser(HttpServletRequest request) {
        if (request == null) {
            return null;
        }
        Object userObj = request.getSession().getAttribute(USER_LOGIN_STATE);
        if (userObj == null) {
            throw new BusinessException(ErrorCode.NO_AUTH);
        }
        return (User) userObj;
    }

    @Override
    public List<User> matchUsers(long num, User loginUser) {
        QueryWrapper<User> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("id", "tags");
        queryWrapper.isNotNull("tags");
        List<User> userList = this.list(queryWrapper);
        String tags = loginUser.getTags();
        Gson gson = new Gson();
        List<String> tagList = gson.fromJson(tags, new TypeToken<List<String>>() {
        }.getType());
        // 用户列表的下标 => 相似度
        List<Pair<User, Long>> list = new ArrayList<>();
        // 依次计算所有用户和当前用户的相似度
        for (int i = 0; i < userList.size(); i++) {
            User user = userList.get(i);
            String userTags = user.getTags();
            // 无标签或者为当前用户自己
            if (StringUtils.isBlank(userTags) || user.getId() == loginUser.getId()) {
                continue;
            }
            List<String> userTagList = gson.fromJson(userTags, new TypeToken<List<String>>() {
            }.getType());
            // 计算分数
            long distance = AlgorithmUtils.minDistance(tagList, userTagList);
            list.add(new Pair<>(user, distance));
        }
        // 按编辑距离由小到大排序
        List<Pair<User, Long>> topUserPairList = list.stream()
                .sorted((a, b) -> (int) (a.getValue() - b.getValue()))
                .limit(num)
                .collect(Collectors.toList());
        // 原本顺序的 userId 列表
        List<Long> userIdList = topUserPairList.stream().map(pair -> pair.getKey().getId()).collect(Collectors.toList());
        QueryWrapper<User> userQueryWrapper = new QueryWrapper<>();
        userQueryWrapper.in("id", userIdList);
        // 1, 3, 2
        // User1、User2、User3
        // 1 => User1, 2 => User2, 3 => User3
        Map<Long, List<User>> userIdUserListMap = this.list(userQueryWrapper)
                .stream()
                .map(user -> getSafetyUser(user))
                .collect(Collectors.groupingBy(User::getId));
        List<User> finalUserList = new ArrayList<>();
        for (Long userId : userIdList) {
            finalUserList.add(userIdUserListMap.get(userId).get(0));
        }
        return finalUserList;
    }

}




