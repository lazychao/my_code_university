//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//int ori = 0, aim = 0;
//void setbit(char n, int index,int& num)//用于初始化二进制表示，表示为二进制
//{
//	if (n=='1')
//	{
//		num |= (1 << index);
//	}
//	else
//	{
//		num &=~ (1 << index);//很重要的去反
//	}
//}
//void change_bit(int index, int& num)//改变某一位的状态
//{
//	num ^= (1 << index);
//}
//void press(int index,int&num)//按下去改变三个状态，不考虑第一个
//{
//	change_bit(index - 1, num);
//	change_bit(index , num);
//	change_bit(index + 1, num);
//}
//int getbit(int index, int num)//用于查看某一位的状态
//{
//	return (num >> index & 1);
//}
//int main()//很关键一点  是后一个决定前一个的状态而不是后一个决定前一个
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	for (int i = 0; i < s1.size(); i++)
//	{
//		setbit(s1[i], i,ori);
//		setbit(s2[i], i, aim);
//	}
//
//	//第一种情况 第一按下，这也要算一次
//	int a = ori, b = ori;//用两个来测试
//	int count1 = 1, count2 = 0;
//	change_bit(0, a);
//	change_bit(1, a);
//	for (int i = 1; i < s1.size() ; i++)
//	{
//		if (getbit(i - 1, a)!=getbit(i-1,aim))
//		{
//			press(i, a);
//			count1++;
//		}
//	}
//	if (getbit(s1.size() - 1,a) != getbit(s1.size() - 1,aim))
//	{
//		count1 = 100000;
//	}
//	//第二种情况
//	for (int i = 1; i < s1.size(); i++)
//	{
//		if (getbit(i - 1, b) != getbit(i - 1, aim))
//		{
//			press(i, b);
//			count2++;
//		}
//	}
//	if (getbit(s1.size() - 1, b) != getbit(s1.size() - 1, aim))
//	{
//		count2 = 100000;
//	}
//
//	if (count1 == 100000 && count2 == 100000)
//	{
//		cout << "impossible";
//	}
//	else
//	{
//		if (count1 < count2)
//		{
//			cout << count1;
//		}
//		else
//		{
//			cout << count2;
//		}
//	}
//
//}