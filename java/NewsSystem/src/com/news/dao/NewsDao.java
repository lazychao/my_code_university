package com.news.dao;

import com.news.domain.News;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface NewsDao {
    void insertNews(@Param("news") News news,@Param("section_id") String section_id);
    List<News> queryAllNews(@Param("section_id") String section_id);
    int queryTotal(@Param("section_id") String section_id);
    News checkTitle(@Param("news_title") String news_title,@Param("section_id") String section_id);
    void updateTotal(@Param("total") int total,@Param("section_id") String section_id);
    List<News> queryPage(@Param("begin") int begin,@Param("end") int end,@Param("section_id")String section_id);
    void deleteNewsById(@Param("id_news") int id_news,@Param("section_id") String section_id);
    void updateNews_id(@Param("id_news") int begin,@Param("section_id") String section_id);
    News queryNewsById(@Param("id_news") int id_news,@Param("section_id") String section_id);
    void updateNewsById(@Param("id_news") int id_news,@Param("section_id") String section_id,@Param("news_title") String news_title,@Param("content") String content);

}
