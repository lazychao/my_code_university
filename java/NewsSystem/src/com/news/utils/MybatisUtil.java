package com.news.utils;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;

public class MybatisUtil {
    public static final  SqlSessionFactory sessionFactory;
    static {
        //1.sqlSessionFactoryBuilder ���������ļ�
        SqlSessionFactoryBuilder sqlSessionFactoryBuilder = new SqlSessionFactoryBuilder();
        //2.��ȡ�����ļ�
        InputStream resourceAsStream = null;
        try {
            resourceAsStream = Resources.getResourceAsStream("SqlMappingConfig.xml");
        } catch (IOException e) {
            e.printStackTrace();
        }
        //3.��ȡsession����
        sessionFactory = sqlSessionFactoryBuilder.build(resourceAsStream);
    }

    public static SqlSession openSession(){
        return sessionFactory.openSession();
    }

	

}
