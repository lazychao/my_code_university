//#include<cstdio>
//#include <iostream>
//double nums[4];
//int ans;
//
//using namespace std;
//void count(double *a, int n)
//{
//	double temp[4];
//	int k, m;
//	if (n == 1)
//	{
//		if (abs(a[0] - 24) < 0.01&&a[0]>0)
//			ans = 1;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (j != i)
//				{
//					for ( k = 0, m = 0; k < n; k++)
//					{
//						if (k != i && k != j)
//						{
//							temp[m++] = a[k];
//						}
//					}
//					temp[m] = a[i] + a[j];
//					count(temp, n - 1);
//					temp[m] = a[i] - a[j];
//					count(temp, n - 1);
//					temp[m] = a[i]* a[j];
//					count(temp, n - 1);
//					if (a[j] != 0)
//					{
//						temp[m] = a[i] / a[j];
//						count(temp, n - 1);
//					}
//					
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	for (int i = 0; i < 4; i++)
//	{
//		cin >> nums[i];
//	}
//	count(nums, 4);
//	if (ans) cout << "yes";
//	else cout << "no";
//}
//
