<template>
    <div class="playlist">
        <div class="playlistTop">
            <div class="play">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-bofang" />
                </svg>
                <span class="text">播放全部</span>
                <span class="count">(共{{ playlist.trackIds.length }}首)</span>
            </div>
            <div class="collect">
                <span>+ 收藏</span>
                <span>({{ changValue(playlist.subscribedCount) }})</span>
            </div>
        </div>
        <div class="list" v-for="(item, i) in playlist.tracks" :key="i">
            <div class="left">
                <div class="index">{{ i + 1 }}</div>
                <!-- 点击后改变vuex中store.state中的下标，实现切换歌曲 -->
                <div class="content"  @click="setPlayIndex(i)">
                    <div class="title">{{ item.name }}</div>
                    <div class="vicecontent">
                        <!-- 歌曲标签找不到，用歌单标签代替，css有些小bug没空修 -->
                        <!-- <div class="tagbox">
                        <div class="tag" v-for="(tag, j) in playlist.tags" :key="j">{{ tag }}</div>
                        </div> -->
                        <div class="al">{{ item.al.name }}</div>
                    </div>
                </div>
            </div>
            <div class="right">
                <svg class="icon " aria-hidden="true" v-if="item.mv != 0">
                    <use xlink:href="#icon-bofangqi" />
                </svg>
                <svg class="icon more" aria-hidden="true">
                    <use xlink:href="#icon-gengduo" />
                </svg>
            </div>
        </div>
    </div>
</template>

<script>
import { mapMutations } from 'vuex'

export default {
    methods: {
        // 还是vue2写法，解构方法后，让模板中元素绑定方法
        ...mapMutations(['setPlayIndex','setPaused'])
    },
    props: ['playlist'],
    setup() {
        const changValue = function (num) {
            let res = num
            if (num > 100000000) {
                res = num / 100000000
                // 保留小数点两位
                res = res.toFixed(2) + '亿'
            } else if (num > 10000) {
                res = num / 10000
                res = res.toFixed(2) + '万'
            }
            return res
        }
        return { changValue }
    }
}
</script>

<style lang="less" scoped>
.playlist {
    width: 7.5rem;
    padding: 0 0.4rem;
    height: auto;
    border-top-left-radius: 0.4rem;
    border-top-right-radius: 0.4rem;
    background-color: #fff;
}

.playlistTop {
    height: 1rem;
    display: flex;
    align-items: center;
    justify-content: space-between;

    .play {
        display: flex;
        align-items: flex-end;

        .icon {
            width: 0.4rem;
            height: 0.4rem;
        }

        .text {
            font-size: 0.35rem;
            margin-left: 0.3rem;
        }

        .count {
            color: #666;

        }
    }

    .collect {
        width: 2.5rem;
        height: 0.8rem;
        line-height: 0.8rem;
        text-align: center;
        color: #fff;
        font-size: 0.26rem;
        background-color: #ff4000;
        border-radius: 0.4rem;
    }
}

.list {
    display: flex;
    justify-content: space-between;
    align-items: center;

    .left {
        display: flex;
        align-items: center;
        height: 1.2rem;

        .index {
            width: 0.6rem;
            font-size: 0.4rem;
            color: #666;
        }

        .content {
            width: 4rem;
            display: flex;
            flex-direction: column;
            justify-content: space-between;
            .title {
                font-size: 0.35rem;
                font-weight: 600;
                overflow: hidden;
                text-overflow: ellipsis;
                display: -webkit-box;
                -webkit-line-clamp: 1;
                -webkit-box-orient: vertical;
            }
            .vicecontent{
                display: flex;
                margin-top: 0.05rem;
            }
            .tagbox{
                display: flex;
                justify-content: center;
            }
            .tag {
                width: 0.6rem;
                height: 0.3rem;
                font-size: 0.1rem;
                text-align: center;
                line-height: 0.3rem;
                color: #ff4000;
                border: 0.01rem solid #ff4000;
                border-radius: 0.1rem;
                margin-right: 0.1rem;
            }

            .al {
                width: 3rem;
                font-size: 0.25rem;
                color: #666;
                overflow: hidden;
                text-overflow: ellipsis;
                display: -webkit-box;
                -webkit-line-clamp: 1;
                -webkit-box-orient: vertical;
            }
        }
    }

    .right {
        .icon {
            width: 0.5rem;
            height: 0.5rem;
            fill: #ccc;
        }

        .more {
            margin-left: 0.3rem;
        }
    }
}
</style>