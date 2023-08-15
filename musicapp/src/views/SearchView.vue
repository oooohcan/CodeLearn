<template>
    <div class="searchview">
        <div class="searchviewNav">
            <div class="back">
                <svg class="icon" aria-hidden="true" @click="$router.go(-1)">
                    <use xlink:href="#icon-zuojiantou" />
                </svg>
            </div>
            <div class="searchinput">
                <input type="text" v-model="searchKeyWord" :placeholder="placeholder" @keydown.enter="saveKeyWord">
            </div>
        </div>
        <div class="history" v-show="searchSongs.length == 0">
            <div class="left">历史</div>
            <div class="right">
                <div @click="historySearch(item)" class="item" v-for="(item, i) in keywordlist.value" :key="i">{{ item
                }}</div>
            </div>
        </div>

        <div class="searchSongs" v-show="searchSongs.length != 0">
            <div class="searchSongsTop">
                <div class="play">
                    <svg class="icon" aria-hidden="true">
                        <use xlink:href="#icon-bofang" />
                    </svg>
                    <span class="text">播放全部</span>
                    <span class="count">(共{{ searchSongs.length }}首)</span>
                </div>
            </div>
            <div class="list" v-for="(item, i) in searchSongs" :key="i">
                <div class="left">
                    <div class="index">{{ i + 1 }}</div>
                    <!-- 点击后改变vuex中store.state中的下标，实现切换歌曲 -->
                    <div class="content" @click="setPlay(item,i)">
                        <div class="title">{{ item.name }}</div>
                        <div class="vicecontent">
                            <div class="ar" v-for="(aritem, j) in item.ar">{{ aritem.name }}</div>
                        </div>
                    </div>
                </div>
                <div class="right">
                    <svg class="icon " aria-hidden="true" v-if="item.mvid != 0">
                        <use xlink:href="#icon-bofangqi" />
                    </svg>
                    <svg class="icon more" aria-hidden="true">
                        <use xlink:href="#icon-gengduo" />
                    </svg>
                </div>
            </div>
        </div>
    </div>


</template>

<script>
import api from '@/api/index.js'
import { ref, reactive, onBeforeMount } from 'vue'
import { mapMutations,useStore } from 'vuex'

export default {
    methods: {
        // 还是vue2写法，解构方法后，让模板中元素绑定方法
        ...mapMutations(['setPlayIndex', 'setPaused'])
    },
    setup() {
        let placeholder = ref("徐秉龙")
        // 用reactive创建数组，在onBeforeMount中直接赋值会解构reactive对象并失去响应性,可以用ref([])或reactive创建有数组熟悉的对象
        // let keywordlist = ref([])
        let keywordlist = reactive({ value: [] })
        let searchKeyWord = ref("")
        let searchSongs = ref([])
        let store = useStore()
        const saveKeyWord = async function () {
            // 将搜索记录存进本地缓存，注意json格式转化
            keywordlist.value.push(searchKeyWord.value)
            localStorage.keywordlist = JSON.stringify(keywordlist.value)
            // 返回搜索结果
            let result = await api.searchMusic(searchKeyWord.value)
            searchSongs.value = result.data.result.songs
            // 清空搜索栏关键词，更改备选词
            placeholder.value = searchKeyWord.value
            searchKeyWord.value = null

            console.log([searchSongs.value]);
        }
        const historySearch = function (keyword) {
            searchKeyWord.value = keyword
            saveKeyWord()
        }
        const setPlay = function(item,i){
            // 后端接口属性命名不同，稍微修一下
            // item.al = item.album
            store.commit('pushPlayList', item)
            store.commit('setPlayIndex', store.state.playlist.length-1)
            // console.log(store.state.playlist);   
        }
        onBeforeMount(() => {
            // 要初始化，否则parse无输入会报错
            // localStorage.setItem('keywordlist',null)可以用这个初始化本次缓存
            // 或者用下面这个方法先跳过第一次本地缓存
            keywordlist.value = localStorage.keywordlist ? JSON.parse(localStorage.keywordlist) : []
            // 去掉重复的搜索记录
            keywordlist.value = Array.from(new Set(keywordlist.value))
            // 保留最新十个记录
            if (keywordlist.value.length > 10) {
                keywordlist.value = keywordlist.value.slice(keywordlist.value.length - 10, keywordlist.value.length)
            }
        })
        return {
            placeholder, keywordlist, saveKeyWord, searchKeyWord, searchSongs, historySearch, setPlay
        }

    }
}
</script>

<style lang="less" scoped>
.searchview {
    width: 7.5rem;
    height: calc(100vh - 1.2rem);
    overflow: scroll;
    padding: 0 0.4rem;

    .searchviewNav {
        display: flex;
        align-items: center;
        font-size: 0.35rem;
        width: 100%;
        height: 1.2rem;
        padding: 0 0.4rem;
        position: fixed;
        top: 0;
        left: 0;
        background-color: #fff;

        .icon {
            width: 0.5rem;
            height: 0.5rem;
            cursor: pointer;
        }

        .searchinput {
            padding: 0 0 0 0.4rem;
            // 占满剩余的宽度
            flex: 1;

            input {
                border: none;
                outline: none;
                border-bottom: 1px solid #666;
                width: 100%;
                height: 0.5rem;
            }
        }
    }

    .history {
        display: flex;
        margin-top: 1.2rem;

        .left {
            width: 1rem;
            height: 0.5rem;
            line-height: 0.5rem;
            font-weight: 900;
            margin: 0.1rem 0;
            font-size: 0.3rem;
        }

        .right {
            color: #666;
            font-size: 0.2rem;
            display: flex;
            flex-wrap: wrap;
            flex: 1;

            .item {
                background-color: #eee;
                height: 0.5rem;
                padding: 0 0.2rem;
                border-radius: 0.4rem;
                line-height: 0.5rem;
                margin: 0.1rem 0.1rem;
                cursor: pointer;
            }
        }
    }
}

.searchSongs {
    width: 100%;
    height: auto;
    margin-top: 1.2rem;

}

.searchSongsTop {
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

            .vicecontent {
                display: flex;
                margin-top: 0.05rem;
            }

            .ar {
                width: 1rem;
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