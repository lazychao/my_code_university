package com.news.dao;

import com.news.domain.Section;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface SectionDao {
    List<Section> getSections();
    String querySection(@Param("section_id") String section_id,@Param("section_name") String section_name);

    void createNewSectionTable(@Param("section_id") String section_id);

    void insertNewSectionToSections(@Param("section_id")String section_id, @Param("section_name")String section_name);

    void deleteSectionTable(@Param("section_id") String section_id);

    void deleteSectionInSections(@Param("section_id") String section_id);

    String checkSection(@Param("section_id") String section_id);

    void updateSectionName(@Param("oldSection_name")String oldSection_name,@Param("newSection_name") String newSection_name);
}
