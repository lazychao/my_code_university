//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void maxnums(int *a,int f,int l,int n)
//{
//	int temp = a[f];
//	int i = f, j = l;
//	while (i != j)
//	{
//		while (a[j] <= a[i] && j > i)
//		{
//			j--;
//		}
//		swap(a[j], a[i]);
//		while(a[i]>=a[j]&&j>i)
//		{
//			i++;
//		}
//		swap(a[j], a[i]);
//	}
//	int x = i - f + 1;
//	if (x == n)
//	{
//		return;
//	}
//	else if(x>n)
//	{
//		maxnums(a, f, i, n);
//	}
//	else
//	{
//		maxnums(a, i + 1, l, n - x);
//	}
//}
//int main()
//{
//	
//	int n;
//	cin >> n;
//	int *nums = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//	int k;
//	cin >> k;
//	maxnums(nums,0,n-1, k);
//	sort(nums, nums+k);
//	for (int i = k-1; i>=0 ; i--)
//	{
//		cout << nums[i] << endl;
//	}
//}