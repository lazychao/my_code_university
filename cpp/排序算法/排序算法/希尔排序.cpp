//#include <cstdio>
//#include<iostream>
//using namespace std;
//int nums[21] = { -1,3,4,1,53,23,35,77,11,4,22,5,3,9,53,29,39,79,19,96,82 };
//void Shell_sort(int nums[], int d[],int n)//数字长度
//{
//	//这个就无法设置岗哨了
//	int j,x;
//	/*for (int k = 0; k < 1; k++)
//	{
//		for (int i = d[k] + 1; i <= 20;i++)
//		{
//			j = i - d[k];
//			while ((j > 0) &&( nums[j] > nums[i]))
//			{
//				nums[j + d[k]] = nums[j];
//				j -= d[k];
//			}
//			nums[j + d[k]] = nums[i];
//		}
//	}*/
//	//这样写不对，，一定要有一个拷贝nums[i]的值
//	for (int k = 0; k < 4; k++)
//	{
//		for (int i = d[k] + 1; i <= 20; i++)
//		{
//			j = i - d[k];
//			x = nums[i];
//			while ((j > 0) && (nums[j] > x))
//			{
//
//				nums[j + d[k]] = nums[j];
//				j -= d[k];
//			}
//			nums[j + d[k]] = x;
//		}
//	}
//}
//int main()
//{
//	
//	int d[4] = { 15,7,3,1 };
//	Shell_sort(nums, d,20);
//	for (int i = 1; i < 21; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}