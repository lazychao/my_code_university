<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core"  prefix="c"%>
<!DOCTYPE html>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>

    <link rel="stylesheet" href="<%=basePath%>css/news.css"  />
    <link rel="stylesheet" href="<%=basePath%>css/style.css" />
    <link rel="stylesheet" href="<%=basePath%>css/amazeui.min.css" /><!--amazeui开源框架-->
    <link rel="stylesheet" href="<%=basePath%>css/pageStyle.css"><!--页数按钮样式-->

</head>


<body style="background:#f3f3f3;">
<!--上层-->>

<div class="main_top">
    <div class="am-cf am-padding am-padding-bottom-0">
        <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">商品管理</strong><small></small></div>
    </div>
    <hr>
    <div class="am-g">
        <div class="am-u-sm-12 am-u-md-3">
            <div class="am-btn-toolbar">
                <div class="am-btn-group am-btn-group-xs">
                    <button id="add" class="am-btn am-btn-default">
                        <span class="am-icon-plus"></span> 新增</button>
                </div>
            </div>
        </div>
        <div class="am-u-sm-12 am-u-md-3">
            <div class="am-btn-toolbar">
                <div class="am-btn-group am-btn-group-xs">
                    <button id="CrawlNews" class="am-btn am-btn-default">
                        <span class="am-icon-plus"></span> 爬取新闻</button>
                </div>
            </div>
        </div>
        <div class="am-u-sm-12 am-u-md-6">
            <div>
                <span>新闻类别：</span>
                <select id="category_select" name="category">
                    <c:if test="${!empty sections}">
                        <c:forEach items="${sections }" var="value">
                            <option value="${value.section_id}">${value.section_name}</option>
                        </c:forEach>
                    </c:if>
                </select>
                &nbsp;
            </div>
        </div>

    </div>
</div>
<!--以上是用到了框架-->
<!--下面是展示新闻-->>

<div class="goods_list">
    <ul class="title_ul">

        <li>新闻图片</li>
        <li>发布时间</li>
        <li>新闻标题</li>
        <li>编辑</li>
        <li>删除</li>
    </ul>

<c:forEach items="${PageBean.newsList}" var="newsList">
    <ul class="list_news_ul">

        <li><img src="<%=basePath%>img_news/${newsList.img_path}" alt=""></li>
        <li>${newsList.date_time}</li>
        <li>${newsList.news_title}</li>

        <li><a href="<%=basePath%>toEditNews.action?id_news=${newsList.id_news}&section_id=${PageBean.section_id}&page=${PageBean.currentPage}"><img style="width: 20px;height: 20px;" src="<%=basePath%>images/edit_icon.png" alt=""></a></li>

        <li><a href="<%=basePath%>deleteNewsById.action?id_news=${newsList.id_news}&page=${PageBean.currentPage}&section_id=${PageBean.section_id}"><img style="width: 20px;height: 20px;" src="<%=basePath%>images/delete_icon.png" alt=""></a></li>
    </ul>
</c:forEach>
    <!--分页-->


    <div id="page" class="page_div">aaa</div>
</div>

<script src="<%=basePath%>js/jquery.min.js"></script>
<script type="text/javascript" src="<%=basePath%>js/paging.js"></script>
<script>
    //分页
    $("#page").paging({
        pageNo:${PageBean.currentPage},
        totalPage: ${PageBean.totalPage},
        totalSize: ${PageBean.totalNews},
        callback: function(num) {//跳转到其他页面
            $(window).attr('location',"<%=basePath%>toNewsManagement.action?page="+num+"&section_id="+"${PageBean.section_id}");

        }

    });

    $("#category_select option[value=${PageBean.section_id}]").prop("selected",true);


    $("#add").click(function () {

        $(window).attr('location','<%=basePath%>toAdd.action');
    });
    $("#CrawlNews").click(function () {

        $(window).attr('location','<%=basePath%>CrawlNews.action?section_id=${PageBean.section_id}');
    });
    $("#category_select").change(function () {
        var value = $("#category_select option:selected").attr("value");
        //跳转页面
        $(window).attr('location',"<%=basePath%>toNewsManagement.action?page=1&section_id="+value);


    })
</script>

</body>
</html>