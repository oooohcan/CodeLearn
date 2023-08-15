package org.oooohcan.matchback.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.oooohcan.matchback.model.domain.Tag;
import org.oooohcan.matchback.service.TagService;
import org.oooohcan.matchback.mapper.TagMapper;
import org.springframework.stereotype.Service;

/**
* @author SydZh
* @description 针对表【tag(标签)】的数据库操作Service实现
* @createDate 2023-06-11 15:59:19
*/
@Service
public class TagServiceImpl extends ServiceImpl<TagMapper, Tag>
    implements TagService{

}




