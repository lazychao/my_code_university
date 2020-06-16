package com.news.service;



import fetch_news.*;

import java.io.IOException;

public class CrawlService {
    public static void fetchNews(String section) throws Exception{
        fetchNews f =null;
        if("digital".equalsIgnoreCase(section)) {
            f= new fetch_digitalNews();

        }
        else if("finance".equalsIgnoreCase(section))
        {
            f= new fetch_financeNews();
        }
        else if("express_news".equalsIgnoreCase(section)){


            f=new fetch_express_newsNews();
        }
        else if("military_culture".equalsIgnoreCase(section)){
            f=new fetch_military_cultureNews();
        }
        else if("politics".equalsIgnoreCase(section)){
            f=new fetch_politicsNews();
        }
        else if("sports".equalsIgnoreCase(section)){
            f=new fetch_sportsNews();
        }
        else{
            f=null;
        }

        if(f!=null)
            try {
                f.fetch();
            } catch (
                    IOException e) {
                e.printStackTrace();
            }
    }



}
