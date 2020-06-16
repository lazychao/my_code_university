package com.news.webController;

import com.news.domain.Section;
import com.news.service.SectionService;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import java.io.UnsupportedEncodingException;
import java.util.List;

@Controller
public class SectionsController {
    @RequestMapping("updateSection")
    public ModelAndView updateSection(String section){
        //NewsService newsService=new NewsService();
        //newsService.updateSection;
        return new ModelAndView("");
    }
    //转向修改分类
    @RequestMapping("toSections.action")
    public String toSections(Model model){
        SectionService sectionService=new SectionService();
        try {
            List<Section> sections=sectionService.getSections();
            model.addAttribute("sections",sections);
            return "Admin/sections.jsp";
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }

    }
    //转到修改类别界面
    @RequestMapping("toEditSection.action")
    public String toEditSection(Model model,String section_name){
        model.addAttribute("section_name",section_name);
        return "Admin/edit_section.jsp";
    }


    //增加类别
    @RequestMapping("addSections.action")
    public ModelAndView addSections(HttpServletRequest request){
        try {
            request.setCharacterEncoding("utf-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        String section_name=request.getParameter("Chinese_name");
        String section_id=request.getParameter("English_name");
        SectionService sectionService=new SectionService();
        sectionService.addSection(section_id,section_name);
        return new ModelAndView("redirect:/toSections.action");
    }


    @RequestMapping("toDeleteSection.action")
    public ModelAndView toDeleteSection(String section_id){
        SectionService sectionService=new SectionService();
        sectionService.deleteSection(section_id);
        System.out.println("__ss++++++++++++++++++++++++++++++++++++++++++++++++++++");

        return new ModelAndView("redirect:/toSections.action");
    }


    @RequestMapping("updateSectionName.action")
    public ModelAndView updateSectionName(HttpServletRequest request){
        try {
            request.setCharacterEncoding("utf-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        String newSection_name=request.getParameter("newSection_name");
        String oldSection_name=request.getParameter("oldSection_name");
        SectionService sectionService=new SectionService();
        System.out.println("__+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        System.out.println(newSection_name+" oldSection_name:"+ oldSection_name);
        sectionService.updateSectionName(oldSection_name,newSection_name);

        return new ModelAndView("redirect:/toSections.action");
    }
}
