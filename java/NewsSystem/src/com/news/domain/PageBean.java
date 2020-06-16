package com.news.domain;

import lombok.Getter;
import lombok.Setter;

import java.util.List;
@Getter @Setter
public class PageBean {
    private Integer currentPage;//当前页数
    private Integer totalPage;//总共页数
    private Integer totalNews;//当前页有多少条新闻
    private List<News> newsList;
    private String section_id;

    @Override
    public String toString() {
        return "PageBean{" +
                "currentPage=" + currentPage +
                ", totalPage=" + totalPage +
                ", totalNews=" + totalNews +
                ", newsList=" + newsList +
                ",section="+section_id+
                '}';
    }
}
