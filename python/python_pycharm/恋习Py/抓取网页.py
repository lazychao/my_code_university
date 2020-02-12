import requests
import  re
#https://www.zdic.net/zd/zb/cc1/
result=requests.get("https://www.zdic.net/zd/zb/cc1/")
result.encoding='utf-8'
reg="href='/hans/(.*)' "

hans=re.findall(reg, result.text)
message ="你好"

# print(hans)
#加密过程
encoding =""
for i in message:
    for index,element in enumerate(hans):#index 要写在前面，，先返回的是下角标
        if element == i:
            encoding+=str(index)    #要把数字转换成字符
            encoding+='|'
hanslist=encoding.split('|')
hanslist.remove('')
print(hanslist)
#解密过程
key=""
for i in hanslist:
    for index,element in enumerate(hans):#index 要写在前面，，先返回的是下角标
        if index == int(i):
            key+=element    #要把数字转换成字符

print("解密后:"+key)