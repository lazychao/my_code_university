message=input("请输入要加密的文字：")
encrypt1 =""
for letter in message:
    encrypt1+=str(ord(letter))##先将每一个密码转化为其对应的Ascaii码，然后又转成字符串类型，才能相加
    encrypt1+='|'
print("加密第一层后的效果："+encrypt1)
encrypt_list=encrypt1.split('|')
encrypt_list.remove('')
encrypt2=""
for letter in encrypt_list:
    temp=list(letter)
    for i in range(len(temp)):
        temp[i]=chr(int(temp[i])+65)
        encrypt2+=temp[i]
    encrypt2+='|'
print("加密第二层后的效果："+encrypt2)
decrypt=""##解密后的字符串

for letter in encrypt_list:
    decrypt+=chr(int(letter))##先将每一个字符转换成整型，才可以使用chr函数
print("解密后的效果："+decrypt)



