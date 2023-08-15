const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  // transpileDependencies: true,
  publicPath:'./',
  // 配置的根地址
  // publicPath:'http://oooohcan.gitee.io/xzmusic/',
  // publicPath:'http://oooohcan.github.io/xzmusic/',
  pages:{
    index:{
      entry:"src/main.js",
      title:"小张音乐"
    }
  }
})
