<template>
    <div class="meview">
        欢迎<br>
        <span class="nickname">{{ $store.state.user.userDetail.profile.nickname }}</span><br>
        <img class="avatarimg" :src="$store.state.user.userDetail.profile.avatarUrl" alt="头像">
        <br>
        <br>
        什么都还没写的个人主页。。。
        <br>
        <button class="back" @click="$router.push('/')">点我回首页</button>
    </div>
</template>

<style>
.meview {
    width: 100vw;
    height: 100vh;
    padding: 2rem;
}

.nickname {
    font-size: 0.5rem;
    font-weight: 900;
    color: aqua
}

.avatarimg{
    width: 3rem;
}

.back{
    width: 2rem;
    height: 1.2rem;
    background-color: aquamarine;
    border-radius: 0.5rem;
}

</style>