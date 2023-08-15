# match-back
用户匹配系统后端(基于spring全家桶、mybatis-plus)

## idea启动方式
1. 更改src/main/resources/application.yml中的数据库连接信息和redis端口信息
2. 选择主程序启动
## cmd启动方式
```bash
mvn package -DskipTests
```
```bash
nohup java -jar user-back-0.0.1-SNAPSHOT.jar --spring.profiles.active=prod &
```
