//#include<cstdio>
//#include<iostream>
//#include <algorithm>
//using namespace std;
//struct item
//{
//	int v, w;
//}items[100];
//int dp[101][101];
//int main()
//{
//	int n;
//	cin >> n;
//	int weight;
//	cin >> weight;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> items[i].v >> items[i].w;
//
//	}
//	for (int i = 0; i <= weight; i++)
//	{
//		dp[0][i] = 0;
//	}
//	for (int i = 0; i <= n; i++)
//	{
//		dp[i][0] = 0;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= weight; j++)
//		{
//			if (items[i-1].w > j)
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else
//			{
//				dp[i][j] = max(dp[i - 1][j], items[i - 1].v + dp[i - 1][j - items[i - 1].w]);
//			}
//		}
//	}
//}