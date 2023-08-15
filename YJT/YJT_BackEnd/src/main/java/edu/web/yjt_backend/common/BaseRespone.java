package edu.web.yjt_backend.common;

import lombok.Data;

import java.io.Serializable;

@Data
public class BaseRespone<T> implements Serializable {
    private int code;
    private T data;
    private String message;
    private String description;

    public BaseRespone(int code, T data, String message, String description) {
        this.code = code;
        this.data = data;
        this.message = message;
        this.description = description;
    }

    public BaseRespone(int code, T data, String message) {
        this(code, data, message, "");
    }

    public BaseRespone(int code, T data) {
        this(code, data, "", "");
    }

    public BaseRespone(ErrorCode errorCode) {
        this(errorCode.getCode(), null, errorCode.getMessage(), errorCode.getDescription());
    }
}