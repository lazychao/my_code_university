from random import shuffle
import random
from sys import exit
import numpy as ny
#初始化扑克牌
cards={"黑桃A":1,"黑桃2":2, "黑桃3":3,"黑桃4":4,"黑桃5":5,"黑桃6":6,"黑桃7":7,"黑桃8":8,"黑桃9":9 ,
       "梅花A": 1, "梅花2": 2, "梅花3": 3, "梅花4": 4, "梅花5": 5, "梅花6": 6, "梅花7": 7, "梅花8": 8, "梅花9": 9,
       "方块A":1,"方块2":2, "方块3":3,"方块4":4,"方块5":5,"方块6":6,"方块7":7,"方块8":8,"方块9":9 ,
         "红桃A":1,"红桃2":2, "红桃3":3,"红桃4":4,"红桃5":5,"红桃6":6,"红桃7":7,"红桃8":8,"红桃9":9 }
cards_list= list(cards.keys)
