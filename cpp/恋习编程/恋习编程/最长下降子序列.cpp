//#include <cstdio>
//#include <iostream>
//#include<algorithm>
//using namespace std;//
//int main()
//{
//	int k;
//	cin >> k;
//	int nums[26];
//	int maxlen[26];
//		for (int i = 0; i < k; i++)
//	{
//		cin >> nums[i];
//		maxlen[i] = 1;
//	}
//		int m = -1;//ΪʲôҪ������ء���Ϊ������еĽ�β��һ�������һ��
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[i] <= nums[j])
//			{
//				maxlen[i] = max(maxlen[j] + 1, maxlen[i]);
//			}
//		}
//		if (maxlen[i] > m)
//		{
//			m = maxlen[i];
//		}
//	}
//	cout << m;
//	
//}