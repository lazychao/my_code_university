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

    <link rel="stylesheet" href="<%=basePath%>css/add_delete_edit.css" type="text/css" />
    <link rel="stylesheet" href="<%=basePath%>css/style.css" type="text/css" />
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
        <div class="am-u-sm-12 am-u-md-6">
            <div class="am-btn-toolbar">
                <div class="am-btn-group am-btn-group-xs">
                    <button id="add" class="am-btn am-btn-default">
                        <span class="am-icon-plus"></span> 新增</button>
                </div>
            </div>
        </div>
        <div class="am-u-sm-12 am-u-md-3">

        </div>
        <div class="am-u-sm-12 am-u-md-3">
            <div class="am-input-group am-input-group-sm">
                <input type="text" class="am-form-field" id="input_search">
                <span class="am-input-group-btn">
                    <button class="am-btn am-btn-default" type="button" id="input_search_btn">搜索</button>
                </span>
            </div>
        </div>
    </div>
</div>
<!--以上是用到了框架-->
<!--下面是展示新闻-->>
<div class="goods_list">
    <ul class="title_ul">
        <li>序号</li>
        <li>商品图片</li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li>编辑</li>
        <li>删除</li>
    </ul>

    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><a href="#"><img class="img_icon" src="images/edit_icon.png" alt=""></a></li>
        <li><a href="#"><img class="img_icon" src="images/delete_icon.png" alt=""></a></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <ul class="list_goods_ul">
        <li>01</li>
        <li><img src="<%=basePath%>images/good1.png" alt=""></li>
        <li>商品名称</li>
        <li>商品价格</li>
        <li><img class="img_icon" src="<%=basePath%>images/edit_icon.png" alt=""></li>
        <li><img class="img_icon" src="<%=basePath%>images/delete_icon.png" alt=""></li>
    </ul>
    <!--分页-->


    <div id="page" class="page_div">aaa</div>
</div>

<script src="<%=basePath%>js/jquery.min.js"></script>
<script type="text/javascript" src="<%=basePath%>js/paging.js"></script>
<script>
    //分页
    $("#page").paging({
        pageNo:1,
        totalPage: 10,
        totalSize: 300,
        callback: function(num) {
            alert(num);
        }
    });

    $("#add").click(function () {
        $(window).attr('location','edit.jsp');
    });

</script>

</body>
</html>