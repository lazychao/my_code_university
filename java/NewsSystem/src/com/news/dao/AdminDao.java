package com.news.dao;

import org.apache.ibatis.annotations.Param;

import com.news.domain.Admin;

import java.util.List;

public interface AdminDao {

	public Admin checkAdmin(@Param("username") String username,@Param("password") String password);


}
