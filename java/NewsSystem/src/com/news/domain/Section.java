package com.news.domain;

import lombok.Getter;
import lombok.Setter;

@Getter @Setter
public class Section {
    String section_id;
    String section_name;
    String total;
    @Override
    public String toString() {
        return "Section{" +
                "section_id='" + section_id + '\'' +
                ", section_name='" + section_name + '\'' +
                ", total='" + total + '\'' +
                '}';
    }

}
