import axios from 'axios'

let urlBase = 'http://music.cpengx.cn'

//获取轮播图的api, type:资源类型,对应以下类型,默认为 0 即 PC
// 0: pc 1: android 2: iphone 3: ipad
export function getBanner(type = 0) {
    return axios.get(`${urlBase}/banner?type=${type}`)
}
// 获取歌单推荐，limit: 取出数量 , 默认为 10 (不支持 offset)
export function getMusicList(limit = 10) {
    return axios.get(`${urlBase}/personalized?limit=${limit}`)
}

// 获取歌单详情，必选参数 : id : 歌单id; 可选参数: s: 歌单最近的 s 个收藏者, 默认为 8
export function getPlayListDetail(id){
    return axios.get(`${urlBase}/playlist/detail?id=${id}`)
}

// 获取歌词
export function getLyric(id){
    return axios.get(`${urlBase}/lyric?id=${id}`)
}

// 搜索歌曲
export function searchMusic(keywords) {
    return axios.get(`${urlBase}/cloudsearch?keywords=${keywords}`)
}

// 手机登录
export function phoneLogin(phone,password) {
    return axios.get(`${urlBase}/login/cellphone?phone=${phone}&password=${password}`)
}

// 获取用户详情
export function userDetail(uid) {
    return axios.get(`${urlBase}/user/detail?uid=${uid}`)
}

export default{
    getBanner, getMusicList, getPlayListDetail, getLyric, searchMusic, phoneLogin, userDetail
}