//#include <cstdio>
//#include <iostream>
//#include<cstring>
//using namespace std;
////用静态链表
//typedef struct a
//{
//	int next;
//	int pre;
//	int flag;
//}a;
//
//a nums[1 << 16];
//int main()
//{
//	/*
//	约瑟夫游戏的主要问题：
//输入：总人数 N
//	 剩余人数 K
//	 间隔人数 M
//其中的间隔人数为实际间隔的人数，如果剩余人数为0，则输出0。
//比如，输入8 4 3（空格分隔输入）
//	 输出1,3,6,7（逗号分隔输出）
//输入数据错误时，输出ERROR
//分析过程如下：
//1、初始状态  1 2 3 4 5 6 7 8
//2、间隔三个删除， 4,8
//3、余下人数大于4，流程继续删除 5,2
//4、现在剩下人数4人=K，剩余输出余下的人有：1,3,6,7
//*/
//	char s[10000];
//	gets_s(s);
//	for (int i = 0; i < strlen(s); i++)
//	{
//		if (s[i] != ' ')
//		{
//			if (!isdigit(s[i]))
//			{
//				cout << "ERROR";
//				return 0;
//			}
//		}
//	}
//	int n = 0, pass = 0, remain = 0; int i = 0;
//	for (; s[i]!=' '; i++)
//	{
//		n *=  10;
//		n += s[i] - '0';
//	}
//	for (i=i+1; s[i] != ' '; i++)
//	{
//		remain *= 10;
//		remain += s[i] - '0';
//	}
//	for (i=i+1; s[i] != '\0'; i++)
//	{
//		pass *= 10;
//		pass += s[i] - '0';
//	}
//	if (pass < 0 || n <= 0 || remain < 0 || remain > n)
//	{
//
//		cout << "ERROR";
//		return 0;
//
//	}
//	else if (remain == 0)
//	{
//		cout << 0; return 0;
//	}
//	else if (remain == n)
//	{
//		for (int i = 0; i < n-1; i++)
//		{
//			cout << i + 1 << ',';
//		}
//		cout << n;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		nums[i].next = ((i + 1) % n);
//		if (i != 0)
//			nums[i].pre = (i - 1);
//	}
//	nums[0].pre = n - 1;
//	pass = pass + 1;
//	int index = -1;
//	int j = n - 1;
//	for (int x = 0; x < n - remain; x++)
//	{
//		for (int i = 0; i < pass; i++)
//		{
//			j = nums[j].next;
//
//		}
//		nums[nums[j].pre].next = nums[j].next;
//		nums[nums[j].next].pre = nums[j].pre;
//		nums[j].flag = 1;
//	}
//	int count = 1;
//	int flag = 0;
//	for (int i = 0; i < n; i++)
//	{
//
//		if (nums[i].flag != 1 && count != remain)
//		{
//			count++;
//			cout << i + 1 << ',';
//
//		}
//
//		if (nums[i].flag != 1 && count == remain && flag == 1)
//		{
//			cout << i + 1;
//		}
//		if (count == remain)flag = 1;
//	}
//
//
//
//}
