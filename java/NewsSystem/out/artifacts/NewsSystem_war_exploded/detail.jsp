<%@ page import="com.news.domain.News" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core"  prefix="c"%>
<!DOCTYPE html>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%

    String news_content=request.getParameter("news_content");
    String section_id=request.getParameter("section_id");
    System.out.println(news_content+"1"+section_id);

%>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>新闻系统</title>
    <!--BootStrap设计的页面支持响应式的 -->
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- 最新版本的 Bootstrap 核心 CSS 文件 -->
    <link rel="stylesheet" href="<%=basePath%>css/bootstrap.min.css" type="text/css"/>
    <!--引入JQuery的JS文件：JQuery的JS文件要在BootStrap的js的文件的前面引入-->
    <script type="text/javascript" src="<%=basePath%>js/jquery-1.11.3.min.js" ></script>
    <!--引入BootStrap的JS的文件-->
    <script type="text/javascript" src="<%=basePath%>js/bootstrap.min.js" ></script>
    <style>


        #logo ul{float:right;}
        #logo ul li{list-style: none;float:left;padding: 5px 10px;line-height: 24px;}

        .divider{width:100%;height:3px;background:#336699;}

        .nav_title{

        }
        .nav_title .title{
            text-align: center;
        }
        .nav_title p{
            margin-top: 30px;
            text-align: center;
            font-size: 12px;
            color: #999999;
        }
        .nav_title .posttime{
            margin-right: 30px;
        }
        .nav_title .source{

        }
        .nav_title span{
            /*margin-left: 200px;*/

        }
        .img{
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .content{
            width:100%;
            margin-top: 30px;
            margin-left: auto;
            margin-right: auto;
            line-height: 26px;
        }
        .content textarea{

            font-size: 18px;
        }
        .bottom{
            width:100%;
            margin-top: 80px;
        }

        .view img{
            width:18px;
            height:18px;
            display: block;
            padding: 0px;
            margin:0px;
            /*line-height: 18px;*/
            float:left;
        }
        .view p{
            float:left;
            font-size: 12px;
            margin-top: 0px;
            margin-left: 6px;
            /*line-height: 18px;*/
        }
        .view span{
            display:inline-block;
            /*margin-top: 6px;*/
        }
    </style>
</head>
<body>

<div class="container" style="min-height:700px;">
    <div class="site">
        <p>
            <span>当前位置：</span>
            <span>首页</span>
            <span>&gt;</span>
            <span>${section_id}</span>
            <span>&gt;</span>
            <span>正文</span>
            <a href="<%=basePath%>toDisplay.action?page=${page}&section_id=${section_id}">返回</a>
        </p>
    </div>
    <div class="divider"></div>
    <div class="nav_title">
        <h3 class="title">${news.news_title }</h3>
        <p>
            <span>发布时间：</span>
            <span class="posttime">${news.date_time}</span>

        </p>
    </div>
    <div class="img">
        <img src="<%=basePath%>img_news/${news.img_path}">
    </div>
    <div class="content">

            <textarea  name="content" rows="50" cols="127" readonly placeholder="${news.content}"></textarea>

    </div>
    <div class="bottom">
    </div>
</div>


</body>
</html>
