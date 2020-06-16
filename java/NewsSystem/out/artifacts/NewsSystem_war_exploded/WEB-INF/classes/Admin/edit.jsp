<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core"  prefix="c"%>
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
        <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">修改新闻</strong><small></small></div>
    </div>
    <hr>

    <div class="edit_content">
        <form action="<%=basePath%>updateNewsById.action?id_news=${news.id_news}&section_id=${section_id}&page=${page}" method="post" id="edit_form" style="background: none; width: 700px;">
            <div class="item1">
                <input type="text"  name="id" value="${news.id_news }" style="display:none">
                <div>
                    <span>新闻标题：</span>
                    <input type="text" class="am-form-field" name="title" value="${news.news_title }">&nbsp;&nbsp;
                </div>

            </div>

            <div class="item1">
                <div>
                    <span>所属分类：</span>
                    <select id="categorySel" name="cid">
                        <c:forEach items="${sections }" var="category">
                            <option value="${category.section_id }">${category.section_name }</option>
                        </c:forEach>
                    </select>
                    &nbsp;
                </div>



            </div>

            <div class="item1">
                <span>新闻图片：</span>
                <input type="file" name="image" />
            </div>

            <div class="item1 item_desc">
                <span>新闻内容：</span>
                <textarea  style= "overflow:scroll; overflow-x:hidden;" id="desc" name="content" rows="4" cols="50">${news.content }</textarea>
            </div>
            <button class="am-btn am-btn-default" type="button" id="edit">更新</button>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <button class="am-btn am-btn-default" type="button" id="reset">重置</button>
        </form>
    </div>

</div>

<script src="<%=basePath%>js/jquery.min.js"></script>

<script>

    $(function () {

        $("#edit").click(function () {
            //让表单提交 GoodsEditServlet
            //获取表单  让其提交
            $("#edit_form").submit();
        });

        //让value的值等于商品is_hot的option成为选中状态


        $("#categorySel option[value=${section_id}]").prop("selected",true);

    });



</script>
</body>
</html>