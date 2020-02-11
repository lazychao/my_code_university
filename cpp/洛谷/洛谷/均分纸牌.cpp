//#include<cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
///*两行
//
//第一行为：NN（NN 堆纸牌，1 \le N \le 1001≤N≤100）
//
//第二行为：A_1,A_2, … ,A_nA 
//1
//​	 ,A 
//2
//​	 ,…,A 
//n
//​	  （NN堆纸牌，每堆纸牌初始数，1 \le A_i \le 100001≤A 
//i
//​	 ≤10000）
//*/
//int nums[101];
//int av;
//int count1;
//typedef struct tr
//{
//	int a; int b; int g; int k;
//}tr;
//int main()
//{
//	int n;
//	cin >> n;
//	int sum = 0;
//	int j = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//		sum += nums[i];
//	}
//	av = sum / n; 
//	for (int i = 0; i < n; i++)
//	{
//		if (nums[i] != av)
//		{
//			count1++;
//			nums[i + 1] += (nums[i] - av);
//		}
//	}
//
//	cout << count1;
//}