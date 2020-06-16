<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <link rel="stylesheet" href="<%=basePath%>css/common.css">
    <style>
        body{
            border-top: 1px solid;
        }
        ul{
            width: 250px;
            padding-top: 50px;
        }
        ul li{
            color: #B5B5B5;
            width: 250px;
            height: 50px;
            line-height: 50px;
            border-bottom: 1px solid rgba(107, 108, 109, 0.19);
            position: relative;
        }
        ul li a{
            display: block;
            width: 250px;
            height: 50px;
            color: #B5B5B5;
            background: transparent;
            text-shadow: none;
            font-size: 15px;
            text-decoration: none;
            float: left;
            padding-left: 50px;
        }
        ul li a:hover{
            background:#1c5ec0;
            color: white;
            text-decoration: none;
        }
        

</style>
</head>

<body style="background:#283643;">

<ul>
    <li><a href="<%=basePath%>toNewsManagementFirst.action?" target="add_delete_editFrame">商品管理</a></li>
    <li><a href="<%=basePath%>toSections.action" target="add_delete_editFrame">分类管理</a></li>
</ul>

</body>
</html>