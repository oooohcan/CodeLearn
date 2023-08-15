package org.oooohcan.matchback.service;

import com.baomidou.mybatisplus.core.toolkit.Assert;
import org.oooohcan.matchback.model.domain.User;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.util.DigestUtils;

import javax.annotation.Resource;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.List;

/**
 *  用户服务测试
 *
 *  @author oooohcan
 */
@SpringBootTest
class UserServiceTest {
    @Resource
    private UserService userService;

    @Test
    void testAddUser(){
        User user = new User();
        user.setUsername("hahatest");
        user.setUserAccount("11111111");
        user.setAvatarUrl("https://i0.hdslb.com/bfs/archive/5b8cfd2c03e653106b1c9c37ba2025e39afc0ad1.png");
        user.setGender(0);
        user.setUserPassword("12345678");
        user.setPhone("110");
        user.setEmail("120");
        boolean result = userService.save(user);
        System.out.println(user.getId());
        Assertions.assertTrue(result);
    }

    @Test
    void testDigest(){
        final String SALT = "SydZh";
        String encryptPassword = DigestUtils.md5DigestAsHex((SALT+"myPassword").getBytes());
        System.out.println(encryptPassword);
    }

    @Test
    void userRegister() {
        String userAccount = "haha";
        String userPassword = "";
        String checkPassword = "12345678";
        String inviteCode="x123";
        long result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        userAccount = "ha";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        userPassword = "123456";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        userAccount = "ha ha";
        userPassword = "12345678";
        //空格未过滤
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        checkPassword = "123456789";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        userAccount = "hahaha";
        checkPassword = "12345678";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);

        userAccount = "wdnmd";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1, result);
        //Assertions.assertTrue(result > 0);
        }

    @Test
    void userRegisterInviteTest(){
        String userAccount = "giegie";
        String userPassword = "12345678";
        String checkPassword = "12345678";
        String inviteCode = "hhhh";
        long result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1,result);

        inviteCode = "ha002";
        result = userService.userRegister(userAccount, userPassword, checkPassword,inviteCode);
        Assertions.assertEquals(-1,result);
//        Assertions.assertTrue(result > 0);
        }

    @Test
    void searchUserByTags() {
        List<String> tagNameList = Arrays.asList("java","hhh");
        List<User> userListByMemory = userService.searchUserByTagsByMemory(tagNameList);
        List<User> userListBySQL = userService.searchUserByTagsBySQL(tagNameList);
        Assertions.assertNotNull(userListByMemory);
        Assertions.assertNotNull(userListBySQL);
    }
}