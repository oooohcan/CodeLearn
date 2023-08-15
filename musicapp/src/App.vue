<template>
  <div>
    <router-view />
    <play-controller></play-controller>
  </div>
</template>

<script>
import playController from "@/components/playController.vue";
export default{
  components:{
    playController
  },
  mounted(){
    // 将缓存中的登录状态数据存入vuex
    let userData =localStorage.userData? JSON.parse(localStorage.userData):{}
    this.$store.commit('setUser',userData)
    console.log(this.$store.state.user);
  }
}
</script>

<style lang="less">
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

.icon {
  width: 0.3rem;
  height: 0.3rem;
}

a {
  color: #333;
  text-decoration: none;
}
</style>
