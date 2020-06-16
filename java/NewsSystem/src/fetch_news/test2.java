package fetch_news;

import java.io.IOException;

public class test2 {
    public static void main(String[] args)  {
    fetch_sportsNews ss=new fetch_sportsNews();
    fetch_military_cultureNews ff=new fetch_military_cultureNews();
    fetch_politicsNews dd=new fetch_politicsNews();
    fetch_digitalNews gg=new fetch_digitalNews();
    fetch_express_newsNews hh=new fetch_express_newsNews();
    fetch_financeNews jj=new fetch_financeNews();
    try {
        ss.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }
    try {
        dd.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }
    try {
        ff.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }
    try {
        gg.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }
    try {
        hh.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }
    try {
        jj.fetch();
    } catch (IOException e) {
        e.printStackTrace();
    }



    }
}
