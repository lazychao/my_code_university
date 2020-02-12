import random
a=int(input("请输入起始值："))
b=int(input("请输入结束值："))
num=random.randint(a,b)
print(num)
guess=int(input("please guess the number:"))
while guess!=num:
    if guess >num:
        print("Higher than the number\nguess the number again:")
        guess=int(input())
    elif guess < num:
        print("Lower than the number\nguess the number again:")
        guess=int(input())
    else:
        print("bingo！")
        break
