//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n, c;
////��С�ľ��뾡���󡣡�����ƽ���֣�������������ġ�    Ȼ���ö���
//bool cheak(int x,int*a)
//{
//	int cnt = 1, temp = a[0];
//	for (int i = 1; i < n; i++)
//		if (a[i] - temp >= x)
//		{
//			cnt++;
//			temp = a[i];
//			if (cnt == c)
//				return true;
//		}
//	return false;
//}
//
////int cheak(int mid,int *num)
////{
////	int x = num[0];
////	int index = 1;
////	int i = 1;
////	for (; i < c; i++)//Ҫcͷ��ţ��
////	{
////		x += mid;
////		for (;index<n;index++)
////		{
////			if (num[index] >= x)
////			{
////				index++;
////				break;
////			}
////		}
////		if (index == n&&i!=c-1)
////		{
////			return 0;
////		}
////	}
////	return 1;
////}
//int split(int *num)
//{
//	int max = -1;
//	
//	int right = num[n-1]/c;
//	int left = 1;
//	
//	while (right >= left)
//	{
//		int mid = left + (right - left) / 2;
//		//��ʼ����ÿһ��Mid,��С�� ���϶���Ҫ��
//		if (cheak(mid, num))
//		{
//			if (mid > max)
//			{
//				max = mid;
//			}
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//		
//	}
//	return max;
//}
//int main()
//{
//
//	cin >> n >> c;
//
//    int *num = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin>>num[i];
//	}
//	sort(num,num+n);
//	cout<<split(num);
//
//
//}