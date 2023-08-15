<template>
    <div class="listView">
        <listview-top :playlist="state.playlist"></listview-top>
        <play-list :playlist="state.playlist"></play-list>
    </div>
</template>

<script>
import listviewTop from '@/components/listviewTop.vue'
import playList from '@/components/playList.vue'


import { getPlayListDetail } from '@/api/index'
import { onMounted, reactive } from 'vue'
import { useRoute } from 'vue-router'
import store from '@/store'
export default {
    setup() {
        const route = useRoute()
        let state = reactive({
            playlist: {
                creator: {},
                trackIds: [],
                tracks: []
            }
        })
        onMounted(async () => {
            let id = route.query.id
            let result = await getPlayListDetail(id)
            state.playlist = result.data.playlist
            // 不在模板中绑定方法，渲染后直接commit调用store中的方法
            store.commit('setPlayList', state.playlist.tracks)
            // 显示拿到的数据
            // console.log(result);
            // console.log(state.playlist.tracks);
        })
        return {
            state
        }
    },
    components: {
        listviewTop, playList
    }
}
</script>

<style lang="less" scoped>
.listView {
    // 可以让被底栏遮挡的内容scroll出现
    height: calc(100vh - 1.2rem);
    overflow: scroll;
}
</style>