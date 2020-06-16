<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<!DOCTYPE html>
<html dir="ltr" lang="en-US">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <link rel="stylesheet" href="<%=basePath%>css/news.css " charset="utf-8" />
    <link rel="stylesheet" href="<%=basePath%>css/style.css" charset="utf-8"/>
    <link rel="stylesheet" href="<%=basePath%>css/amazeui.min.css" charset="utf-8"/><!--amazeui开源框架-->
    <link rel="stylesheet" href="<%=basePath%>css/pageStyle.css" charset="utf-8"><!--页数按钮样式-->
    <script src="<%=basePath%>js/jquery.min.js"></script>
    <style>
        #update_section{
            padding: 30px 20px;
            width: 400px;
            height: 200px;
            background: white;
            position: fixed;
            left: 50%;
            top: 50%;
            margin-left: -200px;
            margin-top: -100px;
            display: none;
        }
        #close1{
            position: absolute;
            right: 10px;
            top: 10px;
        }
    </style>
</head>

<body>


<div class="main_top">
    <div class="am-cf am-padding am-padding-bottom-0">
        <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">分类管理</strong><small></small></div>
    </div>
    <hr>
    <div class="am-g">
        <div class="am-u-sm-12 am-u-md-6">
            <div class="am-btn-toolbar">
                <div class="am-btn-group am-btn-group-xs">
                    <button id="add" class="am-btn am-btn-default">
                        <span class="am-icon-plus"></span> 添加分类</button>
                </div>
            </div>
        </div>
    </div>
</div>


<div class="goods_list" id="account_List">
    <ul class="list_news_ul">

        <li>修改分类</li>
        <li>分类名称</li>
        <li>删除分类</li>
    </ul>
    <c:forEach items="${sections}" var="category">
        <ul class="list_news_ul">

            <li><a href="<%=basePath%>toEditSection.action?section_name=${category.section_name}"><img class="img_icon" style="width: 20px;height: 20px;" src="<%=basePath%>images/edit_icon.png" alt=""></a></li>
<%--            <button id="update" style="width:168px;">--%>
<%--                 <span class="am-icon-edit">编辑</span>--%>
<%--            </button>--%>
            <li>${category.section_name}</li>
            <li><a href="<%=basePath%>toDeleteSection.action?section_id=${category.section_id}"><img class="img_icon" style="width: 20px;height: 20px;" src="<%=basePath%>images/delete_icon.png" alt=""></a></li>


        </ul>
    </c:forEach>
        </div>


        <div id="modal_view">


        </div>

        <div id="modal_content">
            <div id="close"><img src="<%=basePath%>images/delete_icon.png" alt=""></div>
            <div class="edit_content">
                <form id="form" action="<%=basePath%>addSections.action" style="background: none; width: 700px;">
                    <div class="item1">
                        <div>
                            <span>添加分类：</span>
                        </div>
                    </div>
                    <div class="item1">
                        <div>
                            <span>中文名称：</span>
                            <input type="text" class="am-form-field" name="Chinese_name">&nbsp;&nbsp;
                        </div>
                    </div>
                    <div class="item1">
                        <div>
                            <span>英文名称：</span>
                            <input type="text" class="am-form-field" name="English_name">&nbsp;&nbsp;
                        </div>
                    </div>
                    <div class="item1">
                        <button id="add_submit" class="am-btn am-btn-default" type="button" >添加</button>
                    </div>
                </form>
            </div>
        </div>


        <script>
            $(function () {
                $("#add").click(function () {
                    $("#modal_view").fadeIn();
                    $("#modal_content").fadeIn();
                });

                $("#close").click(function () {
                    $("#modal_view").fadeOut();
                    $("#modal_content").fadeOut();
                });
                $("#add_submit").click(function () {
                    $("#form").submit();//按下按钮后提交表单
                });

            });
        </script>
        </body>
        </html>