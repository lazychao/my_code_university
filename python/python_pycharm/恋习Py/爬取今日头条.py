import requests
import time
import json
import random
import pandas as pd
import openpyxl
from utils import get_one_random_browser
"""
可以把下面这个函数封装起来,,可以把网页上的下载下来成为文件，读写更方便
"""
# def get_one_user_agent():
#     result = requests.get("https://fake-useragent.herokuapp.com/browsers/0.1.11")
#     agent_json = json.loads(result.text)  # 把字符串转换成字典  与loads功能相反
#     # print(agent_json)
#     browser_list = agent_json["browsers"]
#     i = random.randint(0, len(browser_list))
#     if i == 0:
#         browser = "chrome"
#     elif i == 1:
#         browser = "op era"
#     elif i == 2:
#         browser = "firefox"
#     elif i == 3:
#         browser = "internetexplorer"
#     else:
#         browser = "safari"
#     final_browser = browser_list[browser][random.randint(0, len(browser_list[browser]))]
#     # 这行比较复杂，  browserlist是一个字典   browser是一个key   所对应的value是一个list
#     return final_browser


def get_url_and_headers():
    current_time = int(time.time())  # 得转化为整形，，本来是浮点数

    user_agent = get_one_random_browser()

    url = "https://www.toutiao.com/api/pc/feed/?max_behot_time=" + str(
        current_time) + "&category=__all__&utm_source=toutiao&widen=1&tadrequire=true&as=A1D50DE6F41E9D1&cp=5D64CEE91DD10E1&_signature=3vWjtBAVg5nXudmhTvyw7971o6"

    header = {
        "user-agent": user_agent,
        "cookie": "tt_webid=6729008409938707976; WEATHER_CITY=%E5%8C%97%E4%BA%AC; " \
                  "tt_webid=6729008409938707976; csrftoken=2437d90657fb171ee6e46e6f019897af; __" \
                  "tasessionId=8t4ofd0q31566891638657"
    }  # 这个是用户代理，是浏览器身份证，为了防止反爬，需要实时刷新不同的用户代理
    # cookie 要设置在header里面

    my_proxies = {
        "proxies": 'http://117.41.38.18'
    }  # 这个是ip代理  是机子
    return url,header,my_proxies


def get_html():
    url,header,my_proxies=get_url_and_headers()
    response = requests.get(
        url=url,
        headers=header,
        proxies=my_proxies,
    )
    global the_html  #必须要设为全局变量，，不然递归返回的是最开始的那个
    the_html=json.loads(response.text)
    print(the_html)
    if the_html["message"]=="error":
        get_html()
    return the_html

def data_to_file (html):
    data=html["data"]
    for i in range(len(data)):
        part=data[i]
        with open ("今日头条.json","a+")as f:#不可以用r+  a+是追加，而r+是打开文件之后从最开头开始写
            json.dump(part,f,ensure_ascii=False)#要加后面这个     不然不会显示中文
            f.write('\n')       #分成多行


def file_to_excel():
    df = pd.read_json("今日头条.json", lines=True)##要有一个df   ture的T要大写
    df.to_excel("今日头条.xlsx")##是xlsx


html = get_html()
data_to_file(html)
file_to_excel()

# print(result.text)#result是一个状态，text是它的文本信息，，说白了是字符串
