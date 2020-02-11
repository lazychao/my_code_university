//#include <cstdio>
//#include <iostream>
//using namespace std;
//int totle;
//int merge(int *a, int m, int mid, int n, int *temp)
//{
//	int count = 0;
//	int p1 = m, p2 = mid + 1;
//	while (p1 <= mid&&p2<=n)
//	{
//		for (; p2 <= n; p2++)
//		{
//			if (a[p2] < a[p1])
//			{
//				p1++;
//				count += n - p2 + 1;
//				break;
//			}
//		}
//	}
//	int p = 0;
//	int i = m, j = mid + 1;
//	while (i <= mid && j <= n)
//	{
//		if (a[i] > a[j])
//		{
//			temp[p++] = a[i++];
//		}
//		else
//		{
//			temp[p++] = a[j++];
//		}
//	}
//	while (i <= mid)
//	{
//		temp[p++] = a[i++];
//	}
//	while (j <= n)
//	{
//		temp[p++] = a[j++];
//	}
//	for (int k = 0; k < p; k++)
//	{
//		a[m + k] = temp[k];
//	}
//	return count;
//}
//int mergesort_count(int *a, int m, int n, int *temp)
//{
//	int count = 0;
//	if (m < n)
//	{
//		int mid = m + (n- m) / 2;
//		count=mergesort_count(a, m, mid, temp)+mergesort_count(a, mid + 1, n, temp)+merge(a, m, mid, n, temp);
//	}
//	return count;
//}
//int main()
//{
//	int temp[6];
//	int nums[6] = { 8,5,7,6,1,2 };
//	cout<<mergesort_count(nums,0,5,temp);
//}