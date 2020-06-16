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

// ��ȡ�Ѻ����Ų�����Ϣ
//��ҳurl-��ÿ�����ŵ�title��url-���õ�text��ͼ���url-��ͨ��ͼ���url�õ�ͼ��
public class fetch_politicsNews implements fetchNews{
    public void fetch() throws IOException {
        Document index_doc = Jsoup.connect("http://news.sohu.com/").get();//��ȡ��ҳ��html
        // 2.jsoup��ȡ����<a>��ǩ
        Elements  newsATags = index_doc.select("div.content-politics-society")
                .select("div.main")
                .select("div.main-modA")
                .select("div.main-right") //���ڴ洢��ǩ����
                .select("div.list16")
                .select("ul")
                .select("li")
                .select("a");
        //newsTags����ŵĶ���a��ǩ  ��ǩ����href title
        SqlSession sqlsession=MybatisUtil.openSession();
        NewsDao mapper=sqlsession.getMapper(NewsDao.class);
        int count=mapper.queryTotal("politics");//��ȡ��ǰsection���е���������
        int max=count+5;//һ�������ȡ6������
        for (Element element:newsATags){
            if(max<count){
                break;
            }
            String url=element.attr("href");
            url="http:"+url;
            System.out.println(url);
            if(url.indexOf("//")==0 || (url.indexOf("http://www.sohu.com/a/")<0
                    &&url.indexOf("https://www.sohu.com/a/")<0))//��ֹ����������ַ
                continue;
            String title=element.attr("title");
            //��ÿһ�����ŵ�url  �������ı���ͼƬ
            if (mapper.checkTitle(title,"politics")!=null){
                continue;//˵���������������ݿ����Ѿ����� �Ͳ����ظ�����
            }
            count++;//��ż�һ
            Document news_doc=Jsoup.connect(url).get();
            String content=downloadContent(news_doc);
            String img_path=downloadImg(news_doc,count);
            //�����з�  Ȼ��ȥ��ǰ�����к������� �����ƴ��
            String[] lines=content.split("\n");
            System.out.println(lines.length);
            String[] remove1 = org.apache.commons.lang3.ArrayUtils.remove(lines, 0);
            String[] remove2 = org.apache.commons.lang3.ArrayUtils.remove(remove1, 0);
            String[] remove3 = org.apache.commons.lang3.ArrayUtils.remove(remove2, remove2.length-1);
            String[] remove4 = org.apache.commons.lang3.ArrayUtils.remove(remove3, remove3.length-1);
            content=String.join("\n",remove4);
            SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd");//�������ڸ�ʽ
            String date_time=df.format(new Date());// new Date()Ϊ��ȡ��ǰϵͳʱ��
            News politics_news=new News();
            politics_news.setId_news(count);
            politics_news.setDate_time(date_time);
            politics_news.setImg_path(img_path);
            politics_news.setNews_title(title);
            politics_news.setContent(content);
            mapper.insertNews(politics_news,"politics");//����һ����¼
            //System.out.println("id:"+id+'\n'+"text:"+text+"img_path"+img_path);

        }
        System.out.println("ss:"+count);
        mapper.updateTotal(count,"politics");
        sqlsession.commit();
    }
    public String downloadContent(Document news_doc){
        //String text=news_doc.select("p").text();
        //System.out.println("���"+count+" text:"+text);
        //�ô�ͳ��elements.text ��ѻ��ж�ʧ  ����Ҫ����������
        String baseContent = Jsoup.clean(news_doc.select("p").toString(), "", Whitelist.none(), new Document.OutputSettings().prettyPrint(false));
        String newText = baseContent.replaceAll("\\s{2,}", "\n");
        String trueContent = newText.replaceFirst("\n", "").trim();
        return trueContent;
    }
    public String downloadImg(Document news_doc,int count) throws IOException{
        //����ͼƬ
        Elements imgs=news_doc.select("p").select("img");//��һ������
        if(imgs==null || imgs.size()<1)
            return "";
        String img_url=imgs.get(0).attr("src");//ֻ��һ��ͼƬ
        if(img_url.indexOf("//")==0){
            img_url=img_url.substring(2);
        }//�õ�ͼƬ�ĵ�ַ
        if(img_url.indexOf("p")==0){
            img_url="https://"+img_url;
        }
        String imgs_folder="C:\\Users\\Dell\\Documents\\idea_projects\\NewsSystem\\web\\img_news\\";//��������ͼƬ�ļ���
        String img_name="politics"+count+".png";
        String img_path=imgs_folder+img_name;//����ͼƬ·��
        URL url=new URL(img_url);  // ����URL
        URLConnection uc=url.openConnection(); // ������
        InputStream is=uc.getInputStream(); // ������
        File file=new File(img_path); //�����ļ�
        FileOutputStream out=new FileOutputStream(file);  // ������ļ���
        byte[] bs = new byte[1024];
        // ��ȡ�������ݳ���
        int len;
        // ��ʼ��ȡ
        while ((len = is.read(bs)) != -1) {
            out.write(bs, 0, len);
        }
        // ��ϣ��ر���������
        out.close();
        is.close();
        //System.out.println("���Ϊ��"+count+" url: "+url+"img_path: "+img_path);
        return img_name;
    }
}