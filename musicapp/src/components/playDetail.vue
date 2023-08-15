<template>
    <div class="playdetail">
        <div class="bg" :style="{ backgroundImage: `url(${playdetail.al.picUrl})` }"></div>
        <div class="playTop">
            <!-- 向父组件传递方法 -->
            <div class="back" @click="$emit('back')">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-zuojiantou" />
                </svg>
            </div>
            <div class="title">
                {{ playdetail.name }}
            </div>
            <div class="share">
                <svg class="icon" aria-hidden="true">
                    <use xlink:href="#icon-fenxiang" />
                </svg>
            </div>
        </div>
        <div class="playContent" v-show="!isLyric" @click="isLyric = !isLyric">
            <img class="needle" :class="{ active: !paused }" src="@/assets/img/needle-ab.png">
            <img class="disc" src="@/assets/img/d7e4e3a244701ee85fecb5d4f6b5bd57.png">
            <img class="playimg" :src="playdetail.al.picUrl">
        </div>
        <div class="playLyric" v-show="isLyric" @click="isLyric = !isLyric" ref="playLyric">
            <!-- 将歌词展示：数组转字符串，切割字符串，正则表达式匹配回车，updated更新字符串应注意初始化时空''字符串的情况 -->
            <!-- <p v-for="(item,i) in $store.state.lyric.split(/\n/igs)" :key="i">{{item}}</p> -->

            <!-- 用vuex管理getters处理数据后写法 -->
            <!-- 实现当前歌词显示,歌曲播放时间位于这句词与下句词起始时间之间则高亮 -->
            <p  :class="{active:(currentTime*1000 > item.time && currentTime*1000 < item.nextTime)}" v-for="(item,i) in $store.getters.lyricList" :key="i">{{item.lyric}}</p>

        </div>

        <div class="progress"></div>

        <div class="playfooter">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-xunhuan" />
            </svg>
            <svg class="icon" aria-hidden="true" @click="goPlay(-1),play()">
                <use xlink:href="#icon-shangyishoushangyige" />
            </svg>
            <svg class="icon play" aria-hidden="true" @click="play()">
                <use v-if="paused" xlink:href="#icon-bofang" />
                <use v-else xlink:href="#icon-zanting" />
            </svg>
            <svg class="icon" aria-hidden="true" @click="goPlay(1),play()">
                <use xlink:href="#icon-xiayigexiayishou" />
            </svg>
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-liebiao1" />
            </svg>
        </div>
    </div>
</template>

<script>
import { computed,watch } from 'vue'
import { mapState, mapMutations, useStore } from 'vuex'
export default {
    // 注册组件playdetail接受父组件的props，从父组件传过来的方法play
    props: ['playdetail', 'play'],
    data(){
        return {
            isLyric:false
        }
    },
    // vue2的vuex写法
    computed: {
        ...mapState(['paused','playlist','playCurrentIndex','lyric','currentTime']),
    },
    methods: {
        goPlay : function (num) {
            let index = this.playCurrentIndex+num
            // console.log(this.playdetail)

            // 歌单头尾曲子循环
            if(index<0){
                index = this.playlist.length-1
            }else if(index == this.playlist.length){
                index = 0
            }
            this.$store.commit('setPlayIndex',index)
        }
    },
     watch:{
        //  up主瞎写，把dom操作写进来搞得生命周期混乱拿不到数据
        //  currentTime:function(newValue){
        //     console.log(newValue)
        //     console.log([this.$refs.playLyric])
        //     let p = document.querySelector('p.active')
        //     console.log([p])
        //     let pOffsetTop = p.offsetTop
        //     this.$refs.playLyric.scrollTop = pOffsetTop
        // }
     }

    // vue3写法bug多
    // setup() {
    //     // vue3的vuex写法
    //     const store = useStore()
    //     const playlist = computed(() => store.state.playlist)
    //     const playCurrentIndex = computed(() => store.state.playCurrentIndex)

    //     const goPlay = function (num) {
    //         console.log(num)
    //         console.log(playlist)
    //         console.log(playCurrentIndex)
    //         let index = playCurrentIndex+num
    //         if(index<0){
    //             index = playlist.length-1
    //         }else if(index == playlist.length){
    //             index = 0
    //         }
    //         store.commit('setPlayIndex',index)
    //     }
    //     return {
    //         goPlay,playCurrentIndex,playlist
    //     }
    // }
}
</script>

<style lang="less" scoped>
.playdetail {
    position: fixed;
    left: 0;
    top: 0;
    width: 100vw;
    height: 100vh;
    background-color: #fff;

    .bg {
        position: absolute;
        left: 0;
        top: 0;
        z-index: 1;
        width: 100vw;
        height: 100vh;
        background-size: auto 100%;
        background-position: center;
        filter: blur(60px);
    }

    .playTop {
        width: 7.5rem;
        height: 1rem;
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 0 0.4rem;
        position: absolute;
        top: 0;
        left: 0;
        z-index: 3;

        .icon {
            fill: #fff;
            width: 0.5rem;
            height: 0.45rem;
            margin-top: 0.1rem;
        }

        .title {
            color: #fff;
            font-size: 0.35rem;
            width: 5rem;
            height: 1rem;
            line-height: 1rem;
        }
    }

    .playContent {
        position: absolute;
        width: 7.5rem;
        height: 7.5rem;
        left: 0;
        top: 1.5rem;

        .needle {
            width: 2rem;
            height: auto;
            position: absolute;
            left: 45%;
            z-index: 10;
            transform-origin: 0.26rem 0.26rem;
            transform: rotate(-25deg);
            transition: all 1s;
        }

        .active {
            transform: rotate(0deg);
        }

        .disc {
            width: 5.5rem;
            height: auto;
            position: absolute;
            left: calc(50% - 2.75rem);
            top: 2rem;
            z-index: 5;
        }

        .playimg {
            width: 3.4rem;
            height: auto;
            border-radius: 1.7rem;
            position: absolute;
            left: calc(50% - 1.7rem);
            top: 3.06rem;
            z-index: 3;
        }
    }
    .playLyric{
        position: absolute;
        width: 7.5rem;
        height: 7.5rem;
        left: 0;
        top: calc(50% - 4.5rem);
        text-align: center;
        color: #fff;
        z-index: 3;
        padding: 0.4rem 0;
        overflow: scroll;
        .active{
            color:aqua;
            font-size: 0.4rem;
        }
        p{
            font-size: 0.3rem;
            line-height: 1rem;
            transition: all 0.5s;
        }
    }

    .playfooter {
        width: 7.5rem;
        height: 1.5rem;
        position: absolute;
        left: 0;
        bottom: 0;
        z-index: 3;
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 0 0.4rem;

        .icon {
            width: 0.5rem;
            height: 0.5rem;
            fill: #fff;
        }

        .play {
            width: 1rem;
            height: 1rem;
        }
    }
}
</style>