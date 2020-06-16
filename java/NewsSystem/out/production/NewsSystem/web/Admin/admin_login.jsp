<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%System.out.println(basePath); %>
<html dir="ltr" lang="en-US">
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

	<title>新闻后台管理系统</title>
		<link href="<%=basePath%>images/bitbug_favicon.ico" rel="shortcut icon">
	<link rel="stylesheet" href="<%=basePath%>css/style.css" type="text/css" />

	</head>
	<body>
		<div id="container">
			<form action="<%=basePath%>login.action">
				<div class="login">新闻后台管理系统
				<span style="color:red">${err} </span>
				</div>
				<div class="username-text">用户名:</div>
				<div class="password-text">密码:</div>
				<div class="username-field">
					<input type="text" name="username" value="" />
				</div>
				<div class="password-field">
					<input type="password" name="password" value="" />
				</div>
				<input type="checkbox" name="remember-me" id="remember-me" />

				<input type="submit" name="submit" value="GO" />
			</form>
		</div>

	</body>
</html>
