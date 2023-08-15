<template>
    <div class="iconList">
        <div class="iconItem">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-tubiaozhizuomoban" />
            </svg>
            <span>每日推荐</span>
        </div>
        <div class="iconItem">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-icon_luyinji" />
            </svg>
            <span>私人FM</span>
        </div>
        <div class="iconItem">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-gedan" />
            </svg>
            <span>歌单</span>
        </div>
        <div class="iconItem">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-ranking" />
            </svg>
            <span>排行榜</span>
        </div>
    </div>
</template>

<style lang="less" scoped>
.iconList{
    width: 7.5rem;
    display: flex;
    justify-content: space-between;
    padding: 0.4rem;
    .iconItem{
        display: flex;
        flex-direction: column;
        align-items: center;
        .icon{
        width: 0.8rem;
        height: 0.8rem;
        }
        .span{
            font-size: 0.1rem;
        }
    }
}
</style>