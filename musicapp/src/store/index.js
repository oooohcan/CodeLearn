import { createStore } from 'vuex'
import api from '@/api/index.js'

export default createStore({
  state: {
    playlist: [{
      name: "卡农（经典钢琴版）",
      id: 478507889,
      al: {
        id: 35308023,
        name: "卡农Canon in D",
        pic: 109951165175371070,
        picUrl: "http://p3.music.126.net/fL7FAeRby1s7JreBqoOKjg==/109951165175371079.jpg",
        pic_str: "109951165175371079"
      }
    }],
    playCurrentIndex: 0,
    paused: true,
    lyric: '',
    currentTime: 0,
    intervalId: 0,
    user:{
      isLogin:false,
      account:{},
      userDetail:{}
    }
  },
  getters: {
    lyricList: function (state) {
      let arr = state.lyric.split(/\n/igs).map((item, i) => {
        let min = parseInt(item.slice(1, 3))
        let sec = parseInt(item.slice(4, 6))
        let mill = parseInt(item.slice(7, 9))
        // 把时间和歌词存入数组，注意切割位置的下标
        return {
          min, sec, mill,
          lyric: item.slice(11, item.length),
          time: mill + sec * 1000 + min * 60 * 1000,
          content: item
        }
      })

      arr.forEach((item,i)=>{
        if(i == arr.length-1)
          item.nextTime = arr.length-1
          else
          item.nextTime = arr[i+1].time
      })
      return arr
    }
  },
  mutations: {
    setPlayList: function (state, value) {
      state.playlist = value
    },
    pushPlayList:function(state,value) {
      state.playlist.push(value)
    },
    setPlayIndex(state, value) {
      state.playCurrentIndex = value
    },
    setPaused(state, value) {
      state.paused = value
    },
    setLyric(state, value) {
      state.lyric = value
    },
    setCurrentTime(state, value) {
      state.currentTime = value
    },
    setUser(state,value){
      state.user = value 
    }
  },
  actions: {
    async requestLyric(content, payload) {
      let result = await api.getLyric(payload.id)
      content.commit('setLyric', result.data.lrc.lyric)
    },
    async phoneLogin(content,payload){
      // console.log('payload: ', payload)
      let result = await api.phoneLogin(payload.phone,payload.password)
      if(result.data.code==200){
        // 取出登录接口后的初步用户数据
        // 更改true后路由守卫才让跳转next
        content.state.user.isLogin = true     
        content.state.user.account = result.data.account
        // 取出对应uid的详细用户数据
        let userDetail = await api.userDetail(result.data.account.id)
        content.state.user.userDetail = userDetail.data
        // 存入缓存
        localStorage.userData = JSON.stringify(content.state.user)
        // 将上面那些全部存入vuex的state
        content.commit('setUser', content.state.user)

        console.log('userDetail : ', userDetail);

      }
      console.log('result: ', result)
      return result
    }
  },
  modules: {
  }
})
