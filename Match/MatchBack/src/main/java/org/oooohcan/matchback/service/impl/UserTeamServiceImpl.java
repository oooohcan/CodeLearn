package org.oooohcan.matchback.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.oooohcan.matchback.model.domain.UserTeam;
import org.oooohcan.matchback.service.UserTeamService;
import org.oooohcan.matchback.mapper.UserTeamMapper;
import org.springframework.stereotype.Service;

/**
* @author SydZh
* @description 针对表【user_team(用户队伍关系)】的数据库操作Service实现
* @createDate 2023-07-12 12:10:14
*/
@Service
public class UserTeamServiceImpl extends ServiceImpl<UserTeamMapper, UserTeam>
    implements UserTeamService{

}




