package com.news.webController;

import com.news.domain.News;
import com.news.domain.PageBean;
import com.news.domain.Section;
import com.news.service.NewsService;
import com.news.service.SectionService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.SessionAttribute;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

import java.util.List;

@Controller
@SessionAttributes(value = {"news_content"})
public class DisplayContrller {
    @RequestMapping("toDisplayFirst.action")
    public String  toDisplayFirst(Model model){
        System.out.println("ddddddddddddddddddddddddddddd");
        SectionService sectionService=new SectionService();
        List<Section> sections= null;
        String section_id="";
        try {
            sections = sectionService.getSections();
            model.addAttribute("sections",sections);
            section_id=sections.get(0).getSection_id();
        } catch (Exception e) {
            e.printStackTrace();
        }

        NewsService service=new NewsService();
        try {
            PageBean pageBean = service.queryPage(1,section_id);
            model.addAttribute("PageBean",pageBean);
            System.out.println(pageBean.toString());
        } catch (Exception e) {
            e.printStackTrace();
            return "main.jsp";
        }
        return "main.jsp";
    }
    @RequestMapping("toDisplay.action")
    public String toDisplay( Model model,String page,String section_id){
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
            return "main.jsp";
        }
        NewsService service = new NewsService();

        try {
            PageBean pageBean = service.queryPage(Integer.parseInt(page),section_id);
            model.addAttribute("PageBean",pageBean);
            System.out.println(pageBean.toString());
        } catch (Exception e) {
            e.printStackTrace();
            return "main.jsp";
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
        return "main.jsp";
    }
    @RequestMapping("toDetail.action")
    public String toDetail(Model model,String id_news,String page,String section_id){
        NewsService newsService=new NewsService();
        try {
            News news=newsService.queryNewsById(Integer.parseInt(id_news),section_id);
            System.out.println("sssssssssssssssssssssssssssssssssssss");
            System.out.println(news.getContent());
            model.addAttribute("news",news);
            model.addAttribute("news_content",news.getContent());

        } catch (Exception e) {
            e.printStackTrace();
        }
        model.addAttribute("page",page);

        model.addAttribute("section_id",section_id);
        return "detail.jsp";
    }
}
