package com.news.service;

import com.news.dao.NewsDao;
import com.news.domain.News;
import com.news.domain.PageBean;
import com.news.utils.MybatisUtil;
import org.apache.ibatis.session.SqlSession;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class NewsService {
    public List<News> queryAllNews(String section_id) throws Exception {
        //����dao��鿴�����Ƿ����
        SqlSession sqlsession = MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        return mapper.queryAllNews(section_id);
    }
    public PageBean queryPage(int page,String section_id) throws Exception{
        SqlSession sqlsession = MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        PageBean pageBean = new PageBean();
        pageBean.setCurrentPage(page);//���õ�ǰ��ҳ��


        pageBean.setSection_id(section_id);
        //�õ���ҳ�������
        int total =mapper.queryTotal(section_id);
        int begin=total-page*10+1;//���ŵ�id��ʼ//һ��ȡʮ��
        if(begin<1)
        {
            begin=1;//begin������С��1
        }
        int end =total-(page-1)*10;//���ŵĽ�����
        pageBean.setTotalNews(total);
        List<News> pageNews=mapper.queryPage(begin,end,section_id);
        pageBean.setNewsList(pageNews);
        //���ҳ����
        int totalPage=(int)Math.ceil((double)total/10.0);
        pageBean.setTotalPage(totalPage);
        return pageBean;
    }

    public void addNews(String news_title,String content,String section_id) {
        News news=new News();
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd");//�������ڸ�ʽ
        String date_time=df.format(new Date());// new Date()Ϊ��ȡ��ǰϵͳʱ��
//        news_title=cvtEncoding(news_title);
//        content=cvtEncoding(content);
        news.setDate_time(date_time);
        news.setContent(content);
        news.setNews_title(news_title);
        news.setImg_path("");
        SqlSession sqlsession = MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        int total=mapper.queryTotal(section_id);
        news.setId_news(total+1);
        System.out.println(news_title);
        System.out.println("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        System.out.println(news.toString());
        mapper.insertNews(news,section_id);
        mapper.updateTotal(total+1,section_id);
        sqlsession.commit();
    }

    public void deleteNewsById(int id_news, String section_id) throws Exception{
        SqlSession sqlsession=MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        mapper.deleteNewsById(id_news,section_id);
        mapper.updateNews_id(id_news, section_id);
        int total=mapper.queryTotal(section_id);
        mapper.updateTotal(total-1,section_id);
        sqlsession.commit();
    }

    public News queryNewsById(int id_news, String section_id) throws Exception{
        SqlSession sqlsession=MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        News news=mapper.queryNewsById(id_news,section_id);
        return news;
    }

    public void updateNewsById(int id_news, String section_id, String news_title, String content) throws Exception{
        SqlSession sqlsession=MybatisUtil.openSession();
        NewsDao mapper = sqlsession.getMapper(NewsDao.class);
        mapper.updateNewsById(id_news,section_id,news_title,content);
        sqlsession.commit();
    }
}
