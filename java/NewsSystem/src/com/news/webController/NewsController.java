package com.news.webController;

import com.news.domain.News;
import com.news.domain.PageBean;
import com.news.domain.Section;
import com.news.service.CrawlService;
import com.news.service.NewsService;
import com.news.service.SectionService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import com.news.service.AdminService;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import java.io.UnsupportedEncodingException;
import java.util.List;

@Controller
@SessionAttributes(value={"section_id","section_name"})

public class NewsController {
	    @RequestMapping("login.action")
		public String cheak_login(String username,String password) {
			AdminService adminservice=new AdminService();
			try{
				
				adminservice.login(username, password);
				System.out.println("登陆成功");
				return "Admin/admin_index.jsp";
				}
			catch(Exception e)//可能sql语句错误可能密码错误
				{
					if (e.getMessage().equals("用户名或密码错误")){
						return "Admin/admin_login.jsp";
					} 
					else {
						e.printStackTrace();
						return "";
					}
				}
		}

		//转向添加新闻界面 dome
		@RequestMapping("toAdd.action")
		public String getSections(Model model){
			SectionService sectionService=new SectionService();
			try {
				List<Section> sections=sectionService.getSections();
				model.addAttribute("sections",sections);
				return "Admin/add.jsp";
			} catch (Exception e) {
				e.printStackTrace();
				return "";
			}

		}


		//第一次或重新进入新闻管理界面 done
		@RequestMapping("toNewsManagementFirst.action")
		public String toNewsMannagementFirst( Model model){
			//先查出所有section
			String page="1";
			model.addAttribute("page",page);

			SectionService sectionService=new SectionService();
			String section_id="";
			try {
				List<Section> sections=sectionService.getSections();
				model.addAttribute("sections",sections);
				section_id=sections.get(0).getSection_id();
			} catch (Exception e) {
				e.printStackTrace();
				return "Admin/NewsManagement.jsp";

			}
			NewsService service = new NewsService();

			try {
				PageBean pageBean = service.queryPage(Integer.parseInt(page),section_id);
				model.addAttribute("PageBean",pageBean);
				System.out.println(pageBean.toString());
			} catch (Exception e) {
				e.printStackTrace();
				return "Admin/NewsManagement.jsp";
			}
//			try {
//				allNews = service.queryAllNews();
//				model.addAttribute("allNews",allNews);
//			} catch (Exception e) {
//				e.printStackTrace();
//				return "Admin/NewsManagement.jsp";
//			}
//			for (News i:allNews){
//				System.out.println(i);
//			}


			System.out.println(model.asMap());
			return "Admin/NewsManagement.jsp";
		}
		//转到新闻管理界面
		@RequestMapping("toNewsManagement.action")
		public String toNewsMannagement( Model model,String page,String section_id){
	    	//先查出所有section
			model.addAttribute("page",page);
			System.out.println("sssssssssssssssssssssssssssssssssssss"+section_id);
			System.out.println("section2"+section_id);
			SectionService sectionService=new SectionService();

			try {
				List<Section> sections=sectionService.getSections();
				model.addAttribute("sections",sections);
			} catch (Exception e) {
				e.printStackTrace();
				return "Admin/NewsManagement.jsp";
			}
			NewsService service = new NewsService();

			try {
				PageBean pageBean = service.queryPage(Integer.parseInt(page),section_id);
				model.addAttribute("PageBean",pageBean);
				System.out.println(pageBean.toString());
			} catch (Exception e) {
				e.printStackTrace();
				return "Admin/NewsManagement.jsp";
			}
//			try {
//				allNews = service.queryAllNews();
//				model.addAttribute("allNews",allNews);
//			} catch (Exception e) {
//				e.printStackTrace();
//				return "Admin/NewsManagement.jsp";
//			}
//			for (News i:allNews){
//				System.out.println(i);
//			}


			System.out.println(model.asMap());
			return "Admin/NewsManagement.jsp";
		}

		//添加新闻 done
		@RequestMapping("addNews.action")
		public ModelAndView addNews(HttpServletRequest request){
			NewsService newsService=new NewsService();//从前端取的数据要更改编码方法
			try {
				request.setCharacterEncoding("utf-8");
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
			String news_title=request.getParameter("news_title");
			String content=request.getParameter("content");
			String section_id=request.getParameter("section_id");
			System.out.println(news_title+"1"+content+"2"+section_id);
			newsService.addNews(news_title,content,section_id);
			return new ModelAndView("redirect:/toNewsManagementFirst.action?");
			//System.out.println(news.toString());
			//System.out.println(section);
		}

		//删除新闻
		@RequestMapping("deleteNewsById.action")
		public ModelAndView deleteNewsById(String id_news, String page,String section_id){
			System.out.println("__+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	    	System.out.println("id"+id_news+"section"+section_id+"page"+page);
			NewsService newsService=new NewsService();
			try {
				newsService.deleteNewsById(Integer.parseInt(id_news),section_id);
			} catch (Exception e) {
				e.printStackTrace();
			}
			return new ModelAndView("redirect:/toNewsManagement.action?page="+page+"&section_id="+section_id);

		}

		//转到修改新闻界面
		@RequestMapping("toEditNews.action")
		public String toEditNews(Model model,String id_news,String section_id,String page){
			System.out.println("__+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
			System.out.println(id_news+"s"+section_id);
			model.addAttribute("page",page);
			NewsService newsService=new NewsService();
			try {
				News news=newsService.queryNewsById(Integer.parseInt(id_news),section_id);
				model.addAttribute("news",news);
				System.out.println("__+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
				System.out.println(news.toString());
			} catch (Exception e) {
				e.printStackTrace();
			}
			SectionService sectionService=new SectionService();
			List<Section> sections= null;
			try {
				sections = sectionService.getSections();
			} catch (Exception e) {
				e.printStackTrace();
			}

			model.addAttribute("sections",sections);
			model.addAttribute("section_id",section_id);
			return "Admin/edit.jsp";
		}

		//修改新闻
		@RequestMapping("updateNewsById.action")
		public ModelAndView updateNewsById(HttpServletRequest request){
			try {
				request.setCharacterEncoding("utf-8");
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
			String id_news=request.getParameter("id_news");
			String section_id=request.getParameter("section_id");
			String news_title=request.getParameter("title");
			String content=request.getParameter("content");
			String page=request.getParameter("page");
	    	System.out.println("sda +++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
			NewsService newsService=new NewsService();
			System.out.println("page"+page);
			System.out.println(id_news+"section"+section_id+"title"+news_title+"content"+content);
			//System.out.println("section1"+section);
			try {
				newsService.updateNewsById(Integer.parseInt(id_news),section_id,news_title,content);
			} catch (Exception e) {
				e.printStackTrace();
			}
			//System.out.println("section1"+section);
			return new ModelAndView("redirect:/toNewsManagement.action?page="+page);
		}
		//爬取新闻
		@RequestMapping("CrawlNews.action")
		public ModelAndView CrawlNews(String section_id){
			System.out.println("sda +++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

			System.out.println("section"+section_id);
			try {
				CrawlService.fetchNews(section_id);
			} catch (Exception e) {
				e.printStackTrace();
			}
			return new ModelAndView("redirect:/toNewsManagementFirst.action");
		}


}