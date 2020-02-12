//#include <cstdio>
//#include <iostream>
//using namespace std;
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void quicksort(int *nums,int m, int n)
//{
//	int i = m, j = n;
//	if (m < n)
//	{
//		int temp = nums[m];
//		while (i != j)
//		{
//			while (nums[j] >= nums[i]&&j>i)
//			{
//				j--;
//			}
//			swap(nums[i], nums[j]);
//			while (nums[i] <= nums[j]&&j>i)
//			{
//				i++;
//			}
//			swap(nums[i], nums[j]);
//		}quicksort(nums, m, i);
//	quicksort(nums, i + 1, n);
//	}
//	
//}
//int main()
//{
//	int nums[10] = { 4,5,1,2,8,8,3,11,45,12 };
//	quicksort(nums,0,9);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}