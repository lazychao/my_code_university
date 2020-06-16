package com.news.domain;

import lombok.Getter;
import lombok.Setter;

import java.util.List;
@Getter @Setter
public class PageBean {
    private Integer currentPage;//��ǰҳ��
    private Integer totalPage;//�ܹ�ҳ��
    private Integer totalNews;//��ǰҳ�ж���������
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
