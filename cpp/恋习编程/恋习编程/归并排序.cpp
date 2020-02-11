//#include <cstdio>
//#include <iostream>
//using namespace std;
//void merge(int *a, int m, int mid,int n, int *temp)
//{
//	int index = 0;
//	int p1 = m, p2 = mid+1;
//	while (p1 <= mid && p2 <= n)
//	{
//		if (a[p1] <= a[p2])
//		{
//			temp[index++] = a[p1];
//			p1++;
//		}
//		else
//		{
//			temp[index++] = a[p2];
//			p2++;
//		}
//	}
//	while (p1 <= mid)
//	{
//		temp[index++] = a[p1++];
//	}
//	while (p2<= n)
//	{
//		temp[index++] = a[p2++];
//	}
//	for (int i = 0; i < index; i++)
//	{
//		a[m+i] = temp[i];
//	}
//}
//void mergesort(int *a, int m, int n, int *temp)
//{
//	if (m < n)
//	{
//		int mid = m + (n - m) / 2;
//		mergesort(a, m, mid, temp);
//		mergesort(a, mid + 1, n, temp);
//		merge(a,m,mid,n,temp);
//	}
//}
//int main()
//{
//	int a[10] = { 1,9,11,5,3,2,4,6,7,24 };
//	int temp[10];
//	mergesort(a,0,9,temp);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << a[i]<<' ';
//	}
//}