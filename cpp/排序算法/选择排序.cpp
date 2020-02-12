//#include<cstdio>
//#include<iostream>
//using namespace std;
//int nums[21] = { -1,3,4,1,53,23,35,77,11,4,22,5,3,9,53,29,39,79,19,96,82 };
//void simple_select_sort(int *nums, int n)
//{
//	int temp;
//	for (int i = 1; i <= n; i++)
//	{
//		int index = i;
//		for (int k = i+1; k <= n; k++)
//		{
//			if (nums[k] < nums[index])
//			{
//				index = k;
//			}
//		}
//		if(index!=i)
//		{ 
//		temp = nums[i];
//		nums[i] = nums[index];
//		nums[index] = temp;
//		}
//	}
//}
////找出数组中的最大值
//
//int main()
//{
//	simple_select_sort(nums, 20);
//	for (int i = 1; i < 21; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}
