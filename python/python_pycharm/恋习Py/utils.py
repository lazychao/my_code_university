import requests
import json


def get_browsers():
    response = requests.get("https://fake-useragent.herokuapp.com/browsers/0.1.11")
    # 把网页上的内容写成文件   读取会更快
    with open("browsers_storage.json", 'w') as f:
        json.dump(response.text, f)
        # 为什么用with open  因为它把try open 和 close 合在一起
        # 为什么用dump 而不用f.write   因为可以格式保存着就直接存成json格式而不是字符串


import random


def get_one_random_browser():
    with open("browsers_storage.json", "r") as f:
        agent_json = json.load(f)

        agent_json = json.loads(agent_json)#把str变成dict

        browser_list = agent_json["browsers"]
        i = random.randint(0, len(browser_list)-1)
        if i == 0:
            browser = "chrome"
        elif i == 1:
            browser = "opera"
        elif i == 2:
            browser = "firefox"
        elif i == 3:
            browser = "internetexplorer"
        else:
            browser = "safari"
        final_browser = browser_list[browser][random.randint(0, len(browser_list[browser])-1)]
        # 这行比较复杂，  browserlist是一个字典   browser是一个key   所对应的value是一个list
        return final_browser
get_one_random_browser()