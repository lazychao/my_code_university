package fetch_news;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.safety.Whitelist;
import org.jsoup.select.Elements;
import java.util.Date;
import java.io.*;
import java.net.URL;
import java.net.URLConnection;
import java.text.SimpleDateFormat;

// ��ȡ�Ѻ����Ų�����Ϣ
//��ҳurl-��ÿ�����ŵ�title��url-���õ�text��ͼ���url-��ͨ��ͼ���url�õ�ͼ��
public class JsoupTest {
    public static void main(String[] args) throws IOException {
        JsoupTest test=new JsoupTest();
        Document index_doc = Jsoup.connect("http://news.sohu.com/").get();//��ȡ��ҳ��html
        // 2.jsoup��ȡ����<a>��ǩ
        Elements newsATags = index_doc.select("div.main-right")
                .select("div.list16")
                .select("ul")
                .select("li")
                .select("a");
        //newsTags����ŵĶ���a��ǩ  ��ǩ����href title
        int count=1;//����ȡ�����Ž��б��
        for (Element element:newsATags){

            if(count==2){
                break;
            }
            String url=element.attr("href");
            if(url.indexOf("//")==0 || url.indexOf("http://www.sohu.com/a/")<0)//��ֹ����������ַ
                continue;
            String title=element.attr("title");
            //��ÿһ�����ŵ�url  �������ı���ͼƬ
            Document news_doc=Jsoup.connect(url).get();
            String text=test.downloadText(news_doc,count);
            String img_path=test.downloadImg(news_doc,count);
            int id=count;
            //�����з�  Ȼ��ȥ��ǰ�����к������� �����ƴ��
            String[] lines=text.split("\n");
            System.out.println(lines.length);
            String[] remove1 = org.apache.commons.lang3.ArrayUtils.remove(lines, 0);
            String[] remove2 = org.apache.commons.lang3.ArrayUtils.remove(remove1, 0);
            String[] remove3 = org.apache.commons.lang3.ArrayUtils.remove(remove2, remove2.length-1);
            String[] remove4 = org.apache.commons.lang3.ArrayUtils.remove(remove3, remove3.length-1);
            text=String.join("\n",remove4);
            SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//�������ڸ�ʽ
            System.out.println(df.format(new Date()));// new Date()Ϊ��ȡ��ǰϵͳʱ��
            System.out.println("id:"+id+'\n'+"text:"+text+"img_path"+img_path);
            count++;
        }
    }
    public String downloadText(Document news_doc,int count){
        //String text=news_doc.select("p").text();
        //System.out.println("���"+count+" text:"+text);
        //�ô�ͳ��elements.text ��ѻ��ж�ʧ  ����Ҫ����������
        //String s=news_doc.select("p");
        String baseContent = Jsoup.clean(news_doc.select("p").toString(), "", Whitelist.none(), new Document.OutputSettings().prettyPrint(false));
        String newText = baseContent.replaceAll("\\s{2,}", "\n");
        String trueContent = newText.replaceFirst("\n", "").trim();
        return trueContent;
    }
    public String downloadImg(Document news_doc,int count) throws IOException{
        //����ͼƬ
        Elements imgs=news_doc.select("p").select("img");//��һ������
        if(imgs==null || imgs.size()<1)
            return null;
        String img_url=imgs.get(0).attr("src");//ֻ��һ��ͼƬ
        if(img_url.indexOf("//")==0){
            img_url=img_url.substring(2);
        }//�õ�ͼƬ�ĵ�ַ
        String imgs_folder="C:\\Users\\Dell\\Documents\\idea_projects\\NewsSystem\\web\\img_news\\";//��������ͼƬ�ļ���
        String img_path=imgs_folder+count+".png";//����ͼƬ·��
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
        return img_path;
    }
}