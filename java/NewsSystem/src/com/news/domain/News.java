package com.news.domain;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class News {
    int id_news;
    String date_time;
    String news_title;
    String img_path;
    String content;
    @Override
    public String toString() {
        return "news [id_news=" + id_news + ",date_time=" + date_time + ", title=" + news_title + "]";
    }

}
