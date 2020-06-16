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
    <link rel="stylesheet" href="<%=basePath%>css/style.css" type="text/css" />
    <link rel="stylesheet" href="<%=basePath%>css/amazeui.min.css" />
</head>
<body>

<div class="main_top">
    <div class="am-cf am-padding am-padding-bottom-0">
        <div class="am-fl am-cf"><strong class="am-text-primary am-text-lg">添加商品</strong><small></small></div>
    </div>
    <hr>

    <div class="edit_content">

        <div class="item1">
            <div>
                <span>商品名称：</span>
                <input type="text" class="am-form-field" >&nbsp;&nbsp;
            </div>
            <div>
                <span>商品价格：</span>
                <input type="text" class="am-form-field" >
            </div>

        </div>

        <div class="item1">
                <span>所属分类：</span>
                 <select id="category_select">
                    <option value="1">所属分类</option>
                    <option value="0">否</option>
                 </select>
        </div>

        <div class="item1">
                <span>商品图片：</span>
                <input type="file" name="upload" id="upload"/>
        </div>
        
        <div class="item1 item_desc">
            <span>商品描述：</span>
            <textarea  id="desc" name="pdesc" rows="4" cols="50"></textarea>
        </div>
        <button class="am-btn am-btn-default" type="button" id="add">添加</button>
        &nbsp;&nbsp;&nbsp;&nbsp;
        <button class="am-btn am-btn-default" type="button" id="reset">重置</button>
    </div>


</div>

<script src="<%=basePath%>js/jquery.min.js"></script>

<script>
    $("#add").click(function () {
        $(window).attr('location','main.jsp');
    });
    
    $("#reset").click(function () {
       $(window).attr('location','edit.jsp');
    });
</script>
</body>
</html>