//#include<cstdio>
//#include<iostream>
//using namespace std;
//int nums[21] = { -1,3,4,1,53,23,35,77,11,4,22,5,3,9,53,29,39,79,19,96,82 };
//void quick_sort(int l, int r)
//{
//	if (r > l)
//	{
//
//		int temp;
//		int i = l, j = r;
//		while (i < j)
//		{
//			while (i < j&&nums[i] <= nums[j])
//			{
//				i++;
//			}
//			if (i < j)
//			{
//				temp = nums[i];
//				nums[i] = nums[j];
//				nums[j] = temp;
//			}
//			while (i < j&&nums[i] <= nums[j])
//			{
//				j--;
//			}
//			if (i < j)
//			{
//				temp = nums[i];
//				nums[i] = nums[j];
//				nums[j] = temp;
//			}
//		}
//		quick_sort(l, i - 1);
//		quick_sort(i + 1, r);
//	}
//}
//int main()
//{
//	quick_sort(1,20);
//	for (int i = 1; i < 21; i++)
//	{
//		cout << nums[i] << ' ';
//	}
//}