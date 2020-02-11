//#include<cstdio>
//#include<iostream>
//using namespace std;
//int nums[21] = { -1,3,4,1,53,23,35,77,11,4,22,5,3,9,53,29,39,79,19,96,82 };
//void bubble_sort(int *nums, int n)
//{
//	int edge;//害得多设置一个变量存储当前无序的边界
//	int temp;
//	int i = n;//代表无序的边界
//	while (i > 1)
//	{
//		int j = 1;
//		for (; j < i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//			edge = j;
//		}
//		i = edge;
//	}
//}
//int main()
//{
//	bubble_sort(nums, 20);
//	for (int i = 1; i < 21; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}