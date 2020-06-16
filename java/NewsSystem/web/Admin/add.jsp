<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core"  prefix="c"%>
<%@taglib uri="http://www.springframework.org/tags/form" prefix="fm" %>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <link rel="stylesheet" href="<%=basePath%>css/style.css" type="text/css" />
    <link rel="stylesheet" href="<%=basePath%>css/amazeui.min.css" />
</head>
<body>

<div class="main_top">
    <div class="am-cf am-padding am-padding-bottom-0">
        <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">添加新闻</strong><small></small></div>
    </div>
    <hr>

    <div class="edit_content">
		<form action="<%=basePath%>addNews.action" method="post" id="add_form" style="background: none; width: 700px;">
			<div class="item1">
                <div>
                    <span>新闻标题：</span>
                    <input type="text" class="am-form-field" name="news_title"/> &nbsp;&nbsp;
                </div>

            </div>


            <div class="item1">
        	<div>
                <span>所属分类：</span>
                <select class="category_select" name="section_id">
                    <c:if test="${!empty sections}">
                        <c:forEach items="${sections }" var="section">
                            <option value="${section.section_id }">${section.section_name }</option>
                        </c:forEach>
                    </c:if>
                </select>
                &nbsp;
        	</div>
            </div>




            <div class="item1">
                    <span>商品图片（可选）：</span>
                    <input value="xx.png" type="file" name="imag_path" />
            </div>

            <div class="item1 item_desc">
                <span>新闻内容：</span>
             <textarea id="desc" name="content" rows="4" cols="50" required></textarea>
            </div>
            <button class="am-btn am-btn-default" type="button" id="add">添加</button>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <button class="am-btn am-btn-default" type="button" id="reset">重置</button>
		</form>
   </div>

</div>

<script src="<%=basePath%>js/jquery.min.js"></script>

<script>

    $("#add").click(function () {
        //让表单提交 GoodsAddServlet
        //获取表单  让其提交

        //换行转回车
        var haha=document.getElementById("desc").value;
        haha=haha.replace('/n','<br />');
        document.getElementById("desc").value=haha;

        $("#add_form").submit();
    });

</script>
</body>
</html>