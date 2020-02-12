import jieba
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
word_list=["的","实力","贪心","学院","如何","python"]
s1="贪心学院的python厉害吗"
s2="我想学python"
s3="贪心学院好吗"
question_string="贪心学院的python实力如何"
def get_vector (the_string):
    vector=[]
    for i in word_list:
        if i in the_string:
            vector.append(1)
        else:
            vector.append(0)
    return np.array(vector).reshape(1,-1)   #要转换成二维的，不然用不了函数  为甚么用-1 不懂


question_vector=get_vector(question_string)
vector1=get_vector(s1)
vector2=get_vector(s2)
vector3=get_vector(s3)
# print(vector1)
# print(vector2)
# print(vector3)

#相似度计算  属于nlp范畴了

print(cosine_similarity(vector1,vector3))#这样就可以计算出相似度了
#要用二维的