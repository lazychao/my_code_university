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
</head>
<style>
    .admin_top{
        height: 70px;
        background:#1c5ec0;
        text-align: right;
        padding-right: 70px;
        color: white;
        position: relative;
    }

    .admin_top span{
        position: absolute;
        right: 50px;
        top: 25px;

    }
    .admin_top img{
        margin-top: 20px;
    }
    .admin_top .top_left{
        width: 250px;
        height: 70px;
        background:#283643;
        float: left;
        color: white;
        font-weight: bold;
        text-align: center;
        padding-top: 20px;
        font-size: 20px;

    }
    .admin_top .h_top_right{
        font-size: 18px;
    }
    .admin_top .top_left:hover{
        background: rgba(0, 0, 0, 0.938);
    }

    
</style>
<body style="background:blue">
<div class="admin_top">
    <div class="top_left">
        新闻管理
    </div>
    <div class="h_top_right">
        <a href="<%=basePath%>toDisplayFirst.action" target="__top"><span style="color: white;">返回首页</span></a>
    </div>
</div>

</body>
</html>