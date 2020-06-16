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

</head>

<body>
<div id="update_section">
    <div class="edit_content" >

        <form id="form" action="<%=basePath%>updateSectionName.action" style="background: none; width: 700px;">

            <div class="item1">
                <div>
                    <span>旧分类名称：</span>
                    <input type="text" name="oldSection_name" value="${section_name}"  readonly="true" class="am-form-field" >&nbsp;&nbsp;
                </div>
            <br>
                <div>
                    <span>新分类名称：</span>
                    <input type="text" name="newSection_name" value="${section_name}" class="am-form-field" >&nbsp;&nbsp;
                </div>

            </div>
            <div class="item1">
                <button id="update" class="am-btn am-btn-default" type="button" >修改</button>
            </div>
        </form>
    </div>

</div>
</body>
<script>
$("#update").click(function () {

        $("#form").submit();
});
</script>
</html>
