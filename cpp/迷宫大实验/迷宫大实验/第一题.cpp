//#include <cstdio>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n, m;
//	int nums[10000];
//	cin >> m >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> nums[n*j+i];
//		}
//	}
//	for (int j = 0; j < m; j++)
//	{
//		sort(nums + j*n, nums + j*n + n);
//	}
//	int sum = 0;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if(nums[i*n+j]>0)
//			{
//				sum += nums[i*n+j];
//				break;
//			}
//		}
//	}
//	cout << sum;
//	return 0;
//}