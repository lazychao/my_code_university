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
  <meta charset=utf-8>
  <!--适合运行在移动端-->
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link href="<%=basePath%>css/bootstrap.css" rel="stylesheet" >
  <link href="<%=basePath%>css/mycss.css" rel="stylesheet" >
  <link rel="stylesheet" href="<%=basePath%>css/news.css"  />
  <link rel="stylesheet" href="<%=basePath%>css/style.css" />
  <link rel="stylesheet" href="<%=basePath%>css/pageStyle.css"><!--页数按钮样式-->
  <link rel="shortcut icon" href="<%=basePath%>images/bitbug_favicon.ico" type="image/x-icon">
  <script src="<%=basePath%>js/jquery.min.js"></script>
  <script src="<%=basePath%>js/paging.js" type="text/javascript"></script>
  <script src="<%=basePath%>js/bootstrap.min.js"></script>
</head>
<body>



<div id="header_bar" style="background:#1c5ec0;">
  <div class="container">
    <ul class="nav nav-tabs">
      <c:forEach  items="${sections }" var="value">
      <li role="presentation" id="${value.section_id}"><a href="<%=basePath%>toDisplay.action?page=1&section_id=${value.section_id}" class="nav_button">${value.section_name}</a></li>
      </c:forEach>
      <li role="presentation" class="pull-right"><a href="<%=basePath%>Admin/admin_login.jsp" class="nav_button" >管理员登陆</a></li>

    </ul>
  </div>
</div>

<div id="presentation_area">
  <div class="container" >

    <div class="list-group" style="background-color: white;color:black;">
      <c:forEach items="${PageBean.newsList}" var="newsList">
        <a href="<%=basePath%>toDetail.action?id_news=${newsList.id_news}&page=${PageBean.currentPage}&section_id=${PageBean.section_id}" class="list-group-item" >
          <h4 class="list-group-item-heading">${newsList.news_title}</h4>
          <p class="list-group-item-text">${newsList.date_time}</p>
        </a>
      </c:forEach>
    </div>

  </div>

</div>
<div id="page" class="page_div">aaa</div>




<script>
  //分页
  $("#page").paging({
    pageNo:${PageBean.currentPage},
    totalPage: ${PageBean.totalPage},
    totalSize: ${PageBean.totalNews},
    callback: function(num) {//跳转到其他页面
      $(window).attr('location',"<%=basePath%>toDisplay.action?page="+num+"&section_id="+"${PageBean.section_id}");

    }

  });
  $(document).ready(function () {
var location=window.location.href;
var id=location.substring(location.lastIndexOf("=")+1);//把url中最后的section_id裁剪出来
    $("#"+id).addClass("active")//选中当前的section_id导航按钮
  });
 </script>
</body>
</html>