<template>
  <form action="/">
    <van-search v-model="searchText" show-action placeholder="请输入要搜索的标签" @search="onSearch" @cancel="onCancel" />
  </form>
  <van-divider content-position="left">已选标签</van-divider>
  <div v-if="activeIds.length === 0">请选择标签</div>
  <van-row gutter="16" style="padding: 0 16px">
    <van-col v-for="tag in activeIds">
      <van-tag closeable size="small" type="primary" @close="doClose(tag)">
        {{ tag }}
      </van-tag>
    </van-col>
  </van-row>
  <van-divider content-position="left">选择标签</van-divider>
  <van-tree-select v-model:active-id="activeIds" v-model:main-active-index="activeIndex" :items="tagList" />
  <div style="padding: 12px">
    <van-button block type="primary" @click="doSearchResult">搜索</van-button>
  </div>
</template>

<script setup lang="ts">
import { ref } from 'vue';
import { useRouter } from "vue-router";

const router = useRouter()

const searchText = ref('');

const originTagList = [
  {
    text: '年级',
    children: [
      { text: '大一', id: '大一' },
      { text: '大二', id: '大二' },
      { text: '大三', id: '大三' },
      { text: '大四', id: '大四' },
    ],
  },
  {
    text: '专业',
    children: [
      { text: '哲学', id: '哲学' },
      { text: '经济学', id: '经济学' },
      { text: '法学', id: '法学' },
      { text: '教育学', id: '教育学' },
      { text: '文学', id: '文学' },
      { text: '历史学', id: '历史学' },
      { text: '理学', id: '理学' },
      { text: '工学', id: '工学' },
      { text: '农学', id: '农学' },
      { text: '医学', id: '医学' },
      { text: '管理学', id: '管理学' },
      { text: '艺术学', id: '艺术学' }
    ],
  },
  {
    text: '行业',
    children: [
      { text: '政治', id: '政治' },
      { text: '金融', id: '金融' },
      { text: '科技', id: '科技' },
      { text: '文艺', id: '文艺' },
      { text: '互联网', id: '互联网' },
      { text: '传媒', id: '传媒' },
      { text: '教育', id: '教育' },
      { text: '医疗', id: '医疗' },
      { text: '法律', id: '法律' },
      { text: '工程', id: '工程' },
    ],
  },
  {
    text: '技能',
    children: [
      { text: '编程', id: '编程' },
      { text: '数据分析', id: '数据分析' },
      { text: '剪辑', id: '剪辑' },
      { text: '写作', id: '写作' },
      { text: '小语种', id: '小语种' },
      { text: 'CPA', id: 'CPA' },
      { text: 'CFA', id: 'CFA' },
      { text: '法考', id: '法考' },
      { text: '摄影', id: '摄影' },
      { text: '舞蹈', id: '舞蹈' },

    ],
  },
]

// 标签列表
let tagList = ref(originTagList);

/**
 * 搜索过滤
 * @param val
 */
const onSearch = (val) => {
  tagList.value = originTagList.map(parentTag => {
    const tempChildren = [...parentTag.children];
    const tempParentTag = { ...parentTag };
    tempParentTag.children = tempChildren.filter(item => item.text.includes(searchText.value));
    return tempParentTag;
  });

}
const onCancel = () => {
  searchText.value = '';
  tagList.value = originTagList;
};

// 已选中的标签
const activeIds = ref([]);
const activeIndex = ref(0);

// 移除标签
const doClose = (tag) => {
  activeIds.value = activeIds.value.filter(item => {
    return item !== tag;
  })
}

/**
 * 执行搜索
 */
const doSearchResult = () => {
  router.push({
    path: '/user/list',
    query: {
      tags: activeIds.value
    }
  })
}

</script>

<style scoped></style>
