<template>
    <div class="listviewTop">
        <div class="listviewTopNav">
            <img class="bg" :src="playlist.coverImgUrl">
            <div class="back" @click="$router.go(-1)">
                <svg class="icon bk" aria-hidden="true">
                    <use xlink:href="#icon-zuojiantou" />
                </svg>
                <div class="title">歌单</div>
            </div>
            <div class="search">
                <svg class="icon sc" aria-hidden="true" @click="$router.push('/search')">
                    <use xlink:href="#icon-sousuo" />
                </svg>
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-gengduo" />
                </svg>
            </div>
        </div>
        <div class="content">
            <div class="contentLeft">
                <img :src="playlist.coverImgUrl">
                <div class="count">
                    <svg class="icon" aria-hidden="true">
                        <use xlink:href="#icon-bofang1"></use>
                    </svg>
                    {{ changValue(playlist.playCount) }}
                </div>
            </div>
            <div class="contentRight">
                <div class="header">{{ playlist.name }}</div>
                <div class="author">
                    <img :src="playlist.creator.avatarUrl">
                    <span>{{ playlist.creator.nickname }}</span>
                </div>
                <div class="description">{{ playlist.description }}</div>
            </div>
        </div>
        <div class="listviewTopBottom">
            <div class="item">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-pinglun" />
                </svg>
                <span>{{ playlist.commentCount }}</span>
            </div>
            <div class="item">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-fenxiang" />
                </svg>
                <span>{{ playlist.shareCount }}</span>
            </div>
            <div class="item">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-xiazai-wenjianxiazai-07" />
                </svg>
                <span>下载</span>
            </div>
            <div class="item">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-show_duoxuan" />
                </svg>
                <span>多选</span>
            </div>
        </div>
    </div>
</template>

<script>
export default {
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
.listviewTop {
    width: 7.5rem;
    height: 6rem;
    padding: 0 0.4rem;

    .bg {
        position: fixed;
        left: 0;
        top: 0;
        width: 7.5rem;
        height: auto;
        z-index: -1;
        filter: blur(40px);
    }

    // 导航栏
    .listviewTopNav {
        display: flex;
        justify-content: space-between;
        height: 1.2rem;
        align-items: center;
        font-size: 0.35rem;

        .icon {
            width: 0.5rem;
            height: 0.5rem;
            fill: #fff;
        }

        .title {
            margin-left: 0.4rem;
        }

        .sc {
            margin-right: 0.5rem;
        }

        .back,
        .search {
            display: flex;
            color: #fff;
        }

        .bk {
            cursor: pointer;
        }
    }

    // 介绍内容
    .content {
        width: 100%;
        display: flex;
        justify-content: space-between;

        .contentLeft {
            width: 3rem;
            position: relative;

            img {
                width: 100%;
                border-radius: 0.15rem;
            }

            .count {
                position: absolute;
                right: 0.1rem;
                top: 0.1rem;
                font-size: 0.25rem;
                color: #fff;
                display: flex;
                align-items: center;

                .icon {
                    fill: #fff;
                    width: 0.3rem;
                    height: 0.3rem;
                }
            }
        }

        .contentRight {
            width: 3.5rem;
            display: flex;
            flex-direction: column;
            justify-content: space-between;

            .header {
                color: #fff;
                font-weight: 900;
            }

            .author {
                display: flex;
                align-items: center;

                img {
                    width: 0.6rem;
                    border-radius: 0.3rem;
                }

                span {
                    font-size: 0.26rem;
                    color: #ccc;
                    margin-left: 0.1rem;
                }
            }

            .description {
                font-size: 0.24rem;
                color: #aaa;
                overflow: hidden;
                text-overflow: ellipsis;
                display: -webkit-box;
                -webkit-line-clamp: 2;
                -webkit-box-orient: vertical;
            }
        }
    }

    .listviewTopBottom{
        width: 100%;
        display: flex;
        justify-content: space-around;
        align-items: center;
        height: 1.7rem;

        .item{
            display: flex;
            flex-direction: column;
            align-items: center;
            .icon{
                width: 0.5rem;
                height: 0.5rem;
            }
            span{
                color: #fff;
                font-size: 0.2rem;
            }
        }
    }
}
</style>