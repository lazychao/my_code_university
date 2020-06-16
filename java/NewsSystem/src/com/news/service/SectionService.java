package com.news.service;

import com.news.dao.SectionDao;
import com.news.domain.Section;
import com.news.utils.MybatisUtil;
import org.apache.ibatis.session.SqlSession;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

public class SectionService {
    public List<Section> getSections() throws Exception {
        //����dao��鿴�����Ƿ����
        SqlSession sqlsession = MybatisUtil.openSession();
        SectionDao mapper = sqlsession.getMapper(SectionDao.class);
        List<Section> sections=mapper.getSections();
        if(sections!=null){
            return sections;
        }
        else{
            throw new RuntimeException("û�з����sql�쳣");
        }
    }

    public void addSection(String section_id, String section_name) {
        SqlSession sqlsession = MybatisUtil.openSession();
        SectionDao mapper = sqlsession.getMapper(SectionDao.class);
        //�����ж�section_name ��section_id �Ƿ��������ݿ���
        String flag=mapper.querySection(section_id,section_name);
        if(flag==null){

            mapper.createNewSectionTable(section_id);
            mapper.insertNewSectionToSections(section_id,section_name);
            sqlsession.commit();
        }
        else{
            System.out.println("----_++++++++++++++++++++++++++++++++");
            System.out.println("�Ѵ���");
        }
    }

    public void deleteSection(String section_id) {
        SqlSession sqlsession = MybatisUtil.openSession();
        SectionDao mapper = sqlsession.getMapper(SectionDao.class);
        mapper.deleteSectionTable(section_id);
        mapper.deleteSectionInSections(section_id);
        sqlsession.commit();
    }

    public void updateSectionName(String oldSection_name,String newSection_name) {
        SqlSession sqlsession = MybatisUtil.openSession();
        SectionDao mapper = sqlsession.getMapper(SectionDao.class);
        mapper.updateSectionName(oldSection_name, newSection_name);
        sqlsession.commit();
    }
}
