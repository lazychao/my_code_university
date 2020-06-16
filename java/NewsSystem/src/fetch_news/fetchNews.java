package fetch_news;

import org.jsoup.nodes.Document;

import java.io.IOException;

public interface fetchNews {
    void fetch() throws IOException;
    String downloadContent(Document news_doc);
    String downloadImg (Document news_doc,int count)throws IOException;
}
