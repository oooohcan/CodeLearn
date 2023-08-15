<template>
    <div class="musicList">
        <div class="musicList-top">
            <div class="title">发现好歌单</div>
            <div class="more">查看更多</div>
        </div>
        <div class="mlist">
            <swiper :slides-per-view="3" :space-between="10">
                <swiper-slide v-for="(item, i) in state.musicList" v-bind:key="i">
                <!-- 实现路由：跳转、查询 -->
                    <router-link :to="{ path: '/list', query:{id:item.id} }">
                        <div class="count">
                            <svg class="icon" aria-hidden="true">
                                <use xlink:href="#icon-bofang1"></use>
                            </svg>
                            <!-- 用方法实现数字过滤 -->
                            {{ changValue(item.playCount) }}
                        </div>
                        <img :src="item.picUrl" :alt="item.name">
                        <div class="name">{{ item.name }}</div>
                    </router-link>
                </swiper-slide>
            </swiper>
        </div>
    </div>
</template>

<script>

import { Swiper, SwiperSlide } from 'swiper/vue'
import 'swiper/css'

import { getMusicList } from '@/api/index.js'
import { reactive, onMounted } from 'vue'

export default {
    components: {
        Swiper,
        SwiperSlide
    },
    setup() {
        let state = reactive({ musicList: [] })
        const changValue = function (num) {
            let res = 0
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
        const getApiMusicList = async function(){
            state.musicList = (await getMusicList()).data.result
        }
        onMounted(getApiMusicList)
        return { state, changValue }
    }
}


// vue2写法
// export default {
//     components: {
//         Swiper,
//         SwiperSlide,
//     },
//     data() {
//         return {
//             musicList: []
//         }
//     },
//     methods: {
//         changValue: function (num) {
//             let res = 0
//             if (num > 100000000) {
//                 res = num / 100000000
//                 // 保留小数点两位
//                 res = res.toFixed(2) + '亿'
//             } else if (num > 10000){
//                 res = num/10000
//                 res = res.toFixed(2) + '万'
//             }
//             return res
//         }
//     },
//     mounted: async function () {
//         let result = await getMusicList()
//         this.musicList = result.data.result
//     }
// }
</script>

<style lang="less" scoped>
.musicList {
    width: 7.5rem;
    padding: 0 0.4rem;

    .musicList-top {
        display: flex;
        justify-content: space-between;
        align-items: center;
        height: 1rem;

        .title {
            font-size: 0.35rem;
            font-weight: 700;
        }

        .more {
            border: 1px solid #ccc;
            border-radius: 0.2rem;
            font-size: 0.24rem;
            height: 0.5rem;
            width: 1.2rem;
            text-align: center;
            line-height: 0.5rem;
        }
    }

    .mlist {
        .swiper {
            width: 100%;
            height: 3rem;
        }

        .swiper-slide {
            position: relative;

            img {
                width: 100%;
                border-radius: 0.15rem;
            }

            .count {
                position: absolute;
                right: 0.1rem;
                top: 0.1rem;
                font-size: 0.1rem;
                color: #fff;
                display: flex;
                align-items: center;

                .icon {
                    fill: #fff;
                    width: 0.25rem;
                    height: 0.25rem;
                }
            }

            .name {
                font-size: 0.25rem;
                line-height: 0.4rem;
            }
        }
    }
}
</style>