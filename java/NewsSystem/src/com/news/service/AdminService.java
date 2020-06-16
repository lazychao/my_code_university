package com.news.service;

import org.apache.ibatis.session.SqlSession;

import com.news.dao.AdminDao;
import com.news.domain.Admin;
import com.news.utils.MybatisUtil;

public class AdminService {

	public Admin login(String username, String password) throws Exception {
		//����dao��鿴�����Ƿ����
		SqlSession sqlsession = MybatisUtil.openSession();
		AdminDao mapper = sqlsession.getMapper(AdminDao.class);
		Admin admin=mapper.checkAdmin(username, password);
		if(admin!=null) {
			return admin;		
		}
		else {
			throw new RuntimeException("�û������������");
		}
	}

	
}
