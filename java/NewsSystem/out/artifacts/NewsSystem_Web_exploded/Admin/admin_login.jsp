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
					<input type="text" name="username" value="xx" />
				</div>
				<div class="password-field">
					<input type="password" name="password" value="xx" />
				</div>
				<input type="checkbox" name="remember-me" id="remember-me" />
				<label for="remember-me">记住用户名</label>
				<div class="forgot-usr-pwd"></div>
				<input type="submit" name="submit" value="GO" />
			</form>
		</div>

	</body>
</html>