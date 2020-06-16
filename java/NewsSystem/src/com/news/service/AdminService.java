package com.news.service;

import org.apache.ibatis.session.SqlSession;

import com.news.dao.AdminDao;
import com.news.domain.Admin;
import com.news.utils.MybatisUtil;

public class AdminService {

	public Admin login(String username, String password) throws Exception {
		//调用dao层查看数据是否存在
		SqlSession sqlsession = MybatisUtil.openSession();
		AdminDao mapper = sqlsession.getMapper(AdminDao.class);
		Admin admin=mapper.checkAdmin(username, password);
		if(admin!=null) {
			return admin;		
		}
		else {
			throw new RuntimeException("用户名或密码错误");
		}
	}

	
}
