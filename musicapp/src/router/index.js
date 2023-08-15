import { createRouter, createWebHistory, createWebHashHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import store from '@/store'

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path: '/list',
    name: 'listview',
    component:()=> import('../views/ListView.vue')
  },
  {
    path: '/search',
    name: 'searchview',
    component: () => import('../views/SearchView.vue')
  },
  {
    path: '/login',
    name: 'loginview',
    component: () => import('../views/LoginView.vue')
  },
  {
    path: '/me',
    name: 'meview',
    // 路由守卫
    beforeEnter:(to,from,next)=>{
      // 登录状态才让进
      if (store.state.user.isLogin)
        next()
      else
        next("/login")
    },
    component: () => import('../views/MeView.vue')
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  // history: createWebHashHistory(process.env.BASE_URL),
  routes
})

export default router
