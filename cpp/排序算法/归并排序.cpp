#include<cstdio>
#include<iostream>
using namespace std;
int nums[21] = { -1,3,4,1,53,23,35,77,11,4,22,5,3,9,53,29,39,79,19,96,82 };
int temp[21];
void merge(int l, int mid, int r)
{
	int i = l, j = mid + 1; int k = l;
	while (i != mid && j != r)
	{
		if (nums[i] <= nums[j])
		{
			temp[k++] = nums[i++];
		}
		if (nums[i] > nums[j])
		{
			temp[k++] = nums[j++];
		}
	}
	while (i != mid)
	{
		temp[k++] = nums[i++];
	}
	while (j != r)
	{
		temp[k++] = nums[j++];
	}
	for (int x = i; x <= r; x++)
	{
		nums[x] = temp[x];
	}
}
void merge_sort(int l,int r)
{
	if (r > l)
	{
		int mid = l + (r - l) / 2;
		merge_sort(l, mid);
		merge_sort(mid + 1, r);
		merge(l,mid, r);
	}

}
int main()
{
	merge_sort(1,20);
	for (int i = 1; i < 21; i++)
	{
		cout << nums[i] << ' ';
	}
}