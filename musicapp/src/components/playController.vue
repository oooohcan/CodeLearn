<template>
    <div class="playController">
        <!-- 判断数据取到与否再去渲染 -->
        <div class="left" @click="show = !show">
            <img :src="playlist[playCurrentIndex].al.picUrl">
            <div class="content">
                <div class="title">{{ playlist[playCurrentIndex].name }}</div>
                <div class="tips">点击此处进入播放页面~</div>
            </div>
        </div>
        <div class="right">
            <!-- 判断音乐播放状态显示相应图标 -->
            <svg class="icon" aria-hidden="true" @click="play()">
                <use v-if="paused" xlink:href="#icon-bofang1" />
                <use v-else xlink:href="#icon-zanting" />
            </svg>
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-liebiao" />
            </svg>
        </div>
        <play-detail :play="play" @back="show = !show" v-show="show" :playdetail="playlist[playCurrentIndex]">
        </play-detail>
        <div class="ifplay">
            <audio ref="audio"
                :src="`https://music.163.com/song/media/outer/url?id=${playlist[playCurrentIndex].id}.mp3`"></audio>
        </div>
    </div>
</template>

<script>
// 解构$store.state
import { mapState, mapMutations, useStore } from 'vuex'
import { ref, onMounted, onUpdated } from 'vue'
import playDetail from '@/components/playDetail.vue'
export default {
    computed: {
        ...mapState(['playlist', 'playCurrentIndex', 'paused']),
    },
    setup() {
        // 用ref获取模板元素或组件实例引用
        const audio = ref(null)
        let show = ref(false)
        let store = useStore()
        const updateTime = function () {
            store.state.intervalId = setInterval(() => {
                // 间隔1秒将元素当前的歌曲时间更新到store中
                store.commit('setCurrentTime', audio.value.currentTime)
            }, 1000)
        }
        const play = function () {
            console.log([audio.value])
            console.log([store.state.lyric]);
            // h5元素点击播放暂停
            if (audio.value.paused) {
                audio.value.play()
                store.commit('setPaused', audio.value.paused)
                updateTime()
            } else {
                audio.value.pause()
                store.commit('setPaused', audio.value.paused)
                clearInterval(store.state.intervalId)
            }
        }
        onMounted(() => {
        })
        onUpdated(() => {
            // 触发store的方法，传入id获取歌词
            store.dispatch('requestLyric', { id: store.state.playlist[store.state.playCurrentIndex].id })
        })
        return {
            audio, play, show
        }
    },
    components: {
        playDetail
    }
}
</script>

<style lang="less" scoped>
.playController {
    width: 7.5rem;
    height: 1.2rem;
    padding: 0 0.2rem;
    position: fixed;
    left: 0;
    bottom: 0;
    z-index: 10;
    display: flex;
    justify-content: space-between;
    align-items: center;
    background-color: #fff;
    border-top: 1px solid #ccc;

    .left {
        display: flex;
        align-items: center;
        width: 6rem;
        height: 1rem;

        img {
            width: 0.8rem;
            height: 0.8rem;
            border-radius: 0.4rem;
        }

        .content {
            padding: 0 0.2rem;

            .title {
                font-size: 0.3rem;
                font-weight: 600;
            }

            .tips {
                font-size: 0.2rem;
                color: #ccc;
            }
        }
    }

    .right {
        width: 1.2rem;
        height: 1rem;
        display: flex;
        justify-content: space-between;
        align-items: center;

        .icon {
            width: 0.4rem;
            height: 0.4rem;
        }
    }

    .ifplay {
        display: none;
    }
}
</style>