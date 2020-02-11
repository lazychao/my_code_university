//#include<cstdio>
//#include<iostream>
//using namespace std;
//void Direct_insert_sort(int nums[],int n)
//{
//	for (int i = 2; i <= n; i++)
//	{
//		nums[0] = nums[i];
//		int j = i-1;
//		/*while (nums[j] != nums[0])
//		{
//			if (nums[j] > nums[0])
//			{
//				nums[j + 1] = nums[j];
//			}
//			j--;
//		}*/
//		while (nums[j] > nums[0])
//		{
//			nums[j + 1] = nums[j];
//			j--;
//		}
//		nums[j + 1] = nums[0];
//	}
//}
//int main()
//{
//	int nums[11] = { -1,3,4,1,53,23,35,77,11,4,3 };//默认第0个不存元素
//	Direct_insert_sort(nums,10);//10是长度
//	for (int i = 1; i < 11; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}