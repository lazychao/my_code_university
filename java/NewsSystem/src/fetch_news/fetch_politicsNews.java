package fetch_news;

import com.news.dao.NewsDao;
import com.news.domain.News;
import com.news.utils.MybatisUtil;
import org.apache.ibatis.session.SqlSession;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.safety.Whitelist;
import org.jsoup.select.Elements;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;
import java.text.SimpleDateFormat;
import java.util.Date;

// 爬取搜狐新闻部分信息
//首页url-》每个新闻的title和url-》得到text和图像的url-》通过图像的url得到图像
public class fetch_politicsNews implements fetchNews{
    public void fetch() throws IOException {
        Document index_doc = Jsoup.connect("http://news.sohu.com/").get();//获取首页的html
        // 2.jsoup获取新闻<a>标签
        Elements  newsATags = index_doc.select("div.content-politics-society")
                .select("div.main")
                .select("div.main-modA")
                .select("div.main-right") //用于存储标签集合
                .select("div.list16")
                .select("ul")
                .select("li")
                .select("a");
        //newsTags里面放的都是a标签  标签里有href title
        SqlSession sqlsession=MybatisUtil.openSession();
        NewsDao mapper=sqlsession.getMapper(NewsDao.class);
        int count=mapper.queryTotal("politics");//获取当前section已有的新闻总数
        int max=count+5;//一次最多爬取6个新闻
        for (Element element:newsATags){
            if(max<count){
                break;
            }
            String url=element.attr("href");
            url="http:"+url;
            System.out.println(url);
            if(url.indexOf("//")==0 || (url.indexOf("http://www.sohu.com/a/")<0
                    &&url.indexOf("https://www.sohu.com/a/")<0))//防止混入其他网址
                continue;
            String title=element.attr("title");
            //打开每一条新闻的url  里面有文本和图片
            if (mapper.checkTitle(title,"politics")!=null){
                continue;//说明该条新闻在数据库中已经存在 就不再重复插入
            }
            count++;//编号加一
            Document news_doc=Jsoup.connect(url).get();
            String content=downloadContent(news_doc);
            String img_path=downloadImg(news_doc,count);
            //按行切分  然后去掉前面两行后面两行 最后再拼接
            String[] lines=content.split("\n");
            System.out.println(lines.length);
            String[] remove1 = org.apache.commons.lang3.ArrayUtils.remove(lines, 0);
            String[] remove2 = org.apache.commons.lang3.ArrayUtils.remove(remove1, 0);
            String[] remove3 = org.apache.commons.lang3.ArrayUtils.remove(remove2, remove2.length-1);
            String[] remove4 = org.apache.commons.lang3.ArrayUtils.remove(remove3, remove3.length-1);
            content=String.join("\n",remove4);
            SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd");//设置日期格式
            String date_time=df.format(new Date());// new Date()为获取当前系统时间
            News politics_news=new News();
            politics_news.setId_news(count);
            politics_news.setDate_time(date_time);
            politics_news.setImg_path(img_path);
            politics_news.setNews_title(title);
            politics_news.setContent(content);
            mapper.insertNews(politics_news,"politics");//插入一条记录
            //System.out.println("id:"+id+'\n'+"text:"+text+"img_path"+img_path);

        }
        System.out.println("ss:"+count);
        mapper.updateTotal(count,"politics");
        sqlsession.commit();
    }
    public String downloadContent(Document news_doc){
        //String text=news_doc.select("p").text();
        //System.out.println("编号"+count+" text:"+text);
        //用传统的elements.text 会把换行丢失  所以要用其他方法
        String baseContent = Jsoup.clean(news_doc.select("p").toString(), "", Whitelist.none(), new Document.OutputSettings().prettyPrint(false));
        String newText = baseContent.replaceAll("\\s{2,}", "\n");
        String trueContent = newText.replaceFirst("\n", "").trim();
        return trueContent;
    }
    public String downloadImg(Document news_doc,int count) throws IOException{
        //下载图片
        Elements imgs=news_doc.select("p").select("img");//是一个集合
        if(imgs==null || imgs.size()<1)
            return "";
        String img_url=imgs.get(0).attr("src");//只存一个图片
        if(img_url.indexOf("//")==0){
            img_url=img_url.substring(2);
        }//得到图片的地址
        if(img_url.indexOf("p")==0){
            img_url="https://"+img_url;
        }
        String imgs_folder="C:\\Users\\Dell\\Documents\\idea_projects\\NewsSystem\\web\\img_news\\";//保存下载图片文件夹
        String img_name="politics"+count+".png";
        String img_path=imgs_folder+img_name;//保存图片路径
        URL url=new URL(img_url);  // 构造URL
        URLConnection uc=url.openConnection(); // 打开连接
        InputStream is=uc.getInputStream(); // 输入流
        File file=new File(img_path); //创建文件
        FileOutputStream out=new FileOutputStream(file);  // 输出的文件流
        byte[] bs = new byte[1024];
        // 读取到的数据长度
        int len;
        // 开始读取
        while ((len = is.read(bs)) != -1) {
            out.write(bs, 0, len);
        }
        // 完毕，关闭所有链接
        out.close();
        is.close();
        //System.out.println("编号为："+count+" url: "+url+"img_path: "+img_path);
        return img_name;
    }
}