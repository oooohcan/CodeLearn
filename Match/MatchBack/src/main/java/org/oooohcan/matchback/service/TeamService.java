package org.oooohcan.matchback.service;

import org.oooohcan.matchback.model.domain.Team;
import com.baomidou.mybatisplus.extension.service.IService;
import org.oooohcan.matchback.model.domain.User;
import org.oooohcan.matchback.model.dto.TeamQuery;
import org.oooohcan.matchback.model.request.TeamJoinRequest;
import org.oooohcan.matchback.model.request.TeamQuitRequest;
import org.oooohcan.matchback.model.request.TeamUpdateRequest;
import org.oooohcan.matchback.model.vo.TeamUserVO;

import java.util.List;

/**
* @author SydZh
* @description 针对表【team(队伍)】的数据库操作Service
* @createDate 2023-07-12 12:10:02
*/
public interface TeamService extends IService<Team> {

    /**
     * 创建队伍
     *
     * @param team
     * @param loginUser
     * @return
     */
    long addTeam(Team team, User loginUser);

    /**
     * 搜索队伍
     *
     * @param teamQuery
     * @param isAdmin
     * @return
     */
    List<TeamUserVO> listTeams(TeamQuery teamQuery, boolean isAdmin);

    /**
     * 更新队伍
     *
     * @param teamUpdateRequest
     * @param loginUser
     * @return
     */
    boolean updateTeam(TeamUpdateRequest teamUpdateRequest, User loginUser);

    /**
     * 加入队伍
     *
     * @param teamJoinRequest
     * @return
     */
    boolean joinTeam(TeamJoinRequest teamJoinRequest, User loginUser);

    /**
     * 退出队伍
     *
     * @param teamQuitRequest
     * @param loginUser
     * @return
     */
    boolean quitTeam(TeamQuitRequest teamQuitRequest, User loginUser);

    /**
     * 删除（解散）队伍
     *
     * @param id
     * @param loginUser
     * @return
     */
    boolean deleteTeam(long id, User loginUser);
}