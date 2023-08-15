<template>
  <div>
    <top-nav></top-nav>
    <swiper-ad></swiper-ad>
    <icon-list></icon-list>
    <music-list></music-list>
    
  </div>
</template>

<script>
// @ is an alias to /src
import topNav from '@/components/topNav.vue'
import swiperAd from '@/components/swiperAd.vue'
import iconList from '@/components/iconList.vue'
import musicList from '@/components/musicList.vue'
import MusicList from '@/components/musicList.vue'



export default {
  name: 'HomeView',
  components: {
    topNav,
    swiperAd,
    iconList,
    musicList,
    MusicList
}
}
</script>