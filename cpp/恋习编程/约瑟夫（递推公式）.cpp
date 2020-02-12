//#include<cstdio>
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, m, k;//共有n个人，m个剩余，数k次
//	cin >> n >> m >> k;
//	int *remain = new int[m];
//	for (int i = 0; i < m; i++)
//	{
//		remain[i] = i;
//	}
//	for (int i = m + 1; i <= n; i++)//m为最终剩余人数
//	{
//		for (int j = 0; j < m; j++)
//		{
//			remain[j] = (remain[j] + k) % i;
//		}
//	}
//	for (int i = 0; i < m; i++)
//	{
//		remain[i]++;
//		cout << remain[i]<<' ';
//	}
//	
//}