//#include<cstdio>
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n, m, k;//����n���ˣ�m��ʣ�࣬��k��
//	cin >> n >> m >> k;
//	int *remain = new int[m];
//	for (int i = 0; i < m; i++)
//	{
//		remain[i] = i;
//	}
//	for (int i = m + 1; i <= n; i++)//mΪ����ʣ������
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