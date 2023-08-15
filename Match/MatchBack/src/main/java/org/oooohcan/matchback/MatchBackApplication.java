package org.oooohcan.matchback;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.scheduling.annotation.EnableScheduling;

@SpringBootApplication
@MapperScan("org.oooohcan.matchback.mapper")
@EnableScheduling
public class MatchBackApplication {

    public static void main(String[] args) {
        SpringApplication.run(MatchBackApplication.class, args);
    }

}
