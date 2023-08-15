<template>
  <div id="swipercom">
    <swiper
    :modules="modules"
    :slides-per-view="1"
    :space-between="50"
    :pagination="{ clickable: true }"
    :autoplay="{ delay: 2500, disableOnInteraction: false }"
    :loop="true"
  >
    <swiper-slide v-for="(item, i) in imgs" v-bind:key="i">
      <img v-bind:src="item.pic" alt="adimg" />
    </swiper-slide>
  </swiper>
  </div>
</template>
<script>
// setup中用到的东西需要引入
import { ref, onMounted} from 'vue'

// Import Swiper
import { Pagination, Autoplay } from 'swiper'
import { Swiper, SwiperSlide } from 'swiper/vue'
import 'swiper/css'
import 'swiper/css/pagination'
import 'swiper/css/autoplay'

//导入获取后端api方法
import { getBanner } from '@/api/index.js'

export default {
  components: {
    Swiper,
    SwiperSlide,
  },
  setup() {
    // vue3中用ref传内部参，this用不了，注意变量被包裹，value才是实际值
    let imgs = ref([])

    // 异步获得轮播图，在渲染后，用两个关键字说明异步
    onMounted(async () => {
      let result = await getBanner(1)
      imgs.value = result.data.banners
    })
    return {
      modules: [Pagination, Autoplay],
      imgs
    }
  },
}
</script>

<style scoped>
#swipercom{
  width:7.5rem;
}
.swiper {
  width: 6.48rem;
  height: 2.52rem;
  border-radius: 5px;
}
.swiper-slide img {
  width: 100%;
}
</style>