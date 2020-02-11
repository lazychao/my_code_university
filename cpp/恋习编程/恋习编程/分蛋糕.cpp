//#include <cstdio>
//#include<cmath>
//#include <iostream>
//using namespace std;
//const double P = acos(-1);
//double sum;
//int n, F;
//bool cheak(double mid,double *a)
//{
//	int cnt = 0;
//	double temp;
//	for (int i = 0; i < n; i++)
//	{
//		temp = a[i];
//		while (temp >= mid)
//		{
//			cnt++;
//			temp -= mid;
//			if (cnt == F+1)
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}
//double split(double *a)
//{
//	double right = sum / F;
//	double left = 0;
//	double max = -1;
//	while (fabs(right-left)>double(0.000001))
//	{
//		double mid = left + (right - left) / 2;
//		if (cheak(mid, a))
//		{
//			if (mid > max)
//			{
//				max = mid;
//			}
//			left = mid;
//		}
//		else
//		{
//			right = mid;
//		}
//		
//	}
//	return max;
//}
//int main()
//{
//	cin >> n>> F;
//	double *num = new double[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> num[i];
//		num[i] = num[i] * num[i] * P;
//		sum += num[i];
//	}
//	printf("%.3lf", split(num));
//}