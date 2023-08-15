package edu.web.yjt_backend.model.domain.request;

import lombok.Data;

import java.io.Serializable;

@Data
public class PageProblemRequest implements Serializable{
    private static final long serialVersionUID = 6592864678216221106L;
    private int current;
    private int pageSize;
}