<template>
    <div class="topNav">
        <div class="topLeft">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-liebiao2" />
            </svg>
        </div>
        <div class="topCenter">
            <span class="navBan" @click="$router.push('/me')">我的</span>
            <span class="navBan active">发现</span>
            <span class="navBan">云村</span>
            <span class="navBan">视频</span>
        </div>
        <div class="topRight">
            <svg class="icon search" aria-hidden="true" @click="$router.push('/search')">
                <use xlink:href="#icon-sousuo" />
            </svg>
        </div>
    </div>
</template>


<style lang="less" scoped>
.topNav {
    width: 7.5rem;
    height: 0.8rem;
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 0.2rem;
}
.icon {
    width: 0.5rem;
    height: 0.5rem;
}
.search{
    width: 0.45rem;
    height: 0.45rem;
}
.topCenter{
    width: 5rem;
    display: flex;
    justify-content: space-around;
    .active{
        font-weight: 900;
    }
}

</style>