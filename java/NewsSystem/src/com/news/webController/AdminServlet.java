package com.news.webController;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.news.service.AdminService;

/**
 * Servlet implementation class AdminServlet
 */
public class AdminServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AdminServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#service(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String username=request.getParameter("username");
		String password=request.getParameter("password");
		AdminService adminservice=new AdminService();
		System.out.println(username);
		System.out.println(password);
		String path = request.getContextPath();
	    String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
		//System.out.println(basePath);
	    try{
			
			adminservice.login(username, password);
			System.out.println("登陆成功");
			response.sendRedirect(basePath+"Admin/admin_index.jsp");
		    
			
			
		}
		catch(Exception e)//可能sql语句错误可能密码错误
		{
			if (e.getMessage().equals("用户名或密码错误"))
			{
			request.setAttribute("err",e.getMessage());
			request.getRequestDispatcher("Admin/admin_login.jsp").forward(request,response);
			} 
			else {
				e.printStackTrace();
			}
		}
		
	}

}
