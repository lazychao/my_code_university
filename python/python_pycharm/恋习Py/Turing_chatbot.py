from flask import Flask
import requests

app = Flask(__name__)


@app.route('/')
def func():
    url="http://openapi.tuling123.com/openapi/api/v2"
    #这是接口地址，，不要输入网页网址，会有专门的表示出来的
    data_param={
                "reqType":0,
                "perception": {
                    "inputText": {
                        "text": "赖志超最帅"#只需要替换这个
                    },
                    "inputImage": {
                        "url": "imageUrl"
                    },
                    "selfInfo": {
                        "location": {
                            "city": "北京",
                            "province": "北京",
                            "street": "信息路"
                        }
                    }
                },
                "userInfo": {
                    "apiKey": "4a755caed6a34046ac47dab0ad1db7aa",#api秘钥  也要在里面找
                    "userId": "17844537757"#账号id
                }
              }
    response=requests.post(url=url,json=data_param)#请求方式看文档
    print(response.text)
    return "赖志超"
    #有请求次数限制，每天就只能免费那么几次




if __name__ == "__main__":
    app.run()
#这样可以简单地返回一个有赖志超显示的网页