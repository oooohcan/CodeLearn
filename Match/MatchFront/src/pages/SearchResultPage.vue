<template>
  <user-card-list :user-list="userList" :loading="userList.length < 0" />
  <van-empty v-if="!userList || userList.length < 1" description="搜索结果为空" />
</template>

<script setup lang="ts">
import { onMounted, ref } from 'vue';
import { useRoute } from "vue-router";
import myAxios from "../plugins/myAxios";
import { Toast } from "vant";
import qs from 'qs';
import UserCardList from "../components/UserCardList.vue";

const route = useRoute();
const { tags } = route.query;

const userList = ref([]);

onMounted(async () => {
  const userListData = await myAxios.get('/user/search/tags', {
    params: {
      tagNameList: tags
    },
    paramsSerializer: params => {
      return qs.stringify(params, { indices: false })
    }
  })
    .then(function (response) {
      console.log('/user/search/tags succeed', response);
      return response?.data;
    })
    .catch(function (error) {
      console.error('/user/search/tags error', error);
      Toast.fail('请求失败');
    })
  console.log(userListData)
  if (userListData) {
    userListData.forEach(user => {
      if (user.tags) {
        user.tags = JSON.parse(user.tags);
      }
    })
    userList.value = userListData;
  }
})


// const mockUser = {
//   id: 12345,
//   username: '鱼皮',
//   userAccount: '12314',
//   profile: '一名精神小伙，目前还有头发，谢谢大家，阿爸爸阿爸爸阿巴阿巴阿巴',
//   avatarUrl: 'http://pic.imeitou.com/uploads/allimg/230213/7-2302131A430-50.jpg',
//   gender: 0,
//   phone: '13113113111',
//   email: '592342843721987@xzcxzczxcz.com',
//   userRole: 0,
//   inviteCode: '1234',
//   tags: ['java', 'emo', '打工中', 'emo', '打工中'],
//   createTime: new Date(),
// }


</script>

<style scoped></style>
