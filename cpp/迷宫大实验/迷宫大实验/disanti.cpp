//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//int nums[5000];
//int x, y;
//int n;
//int minn;
//int maxx;
//
//int allhuoqiu()
//{
//	int t=0;
//	for (int i = 0; i < n; i++)
//	{
//		if(nums[i] % y==0)
//		t += (nums[i] / y);
//		else
//			t += (nums[i] / y+1);
//	}
//	return t;
//}
//int allxuanf()
//{
//	int t;
//	if (maxx%x == 0)
//		t = maxx / x;
//	else
//		t = maxx / x+1;
//	return t;
//}
//int main()
//{
//	maxx = 0; minn = 5001;
//	scanf("%d", &n);
//	
//	
//	scanf("%d%d", &x,&y);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &nums[i]);
//		if (nums[i] > maxx) maxx = nums[i];
//		if (nums[i] < minn) minn = nums[i];
//	}
//	int fi = 0;
//	if (minn > y)
//	{
//		int minn;
//		int x1 = minn / x;
//		int x2 = n*minn / y;
//		if (x1 <= x2)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				nums[i] -= (x1 * x);
//			}
//			fi = x1;
//		}
//		if (x1 > x2)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				nums[i] -= (x2/n * y);
//			}
//			fi = x2;
//		}
//	}
//	sort(nums, nums + n); priority_queue<int> q;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		q.push(nums[i]);
//	}
//	int s1 = allhuoqiu();
//	int s2 = allxuanf();
//	int s = min(s1, s2);
//	int mins3 = 5000;
//	int temp;
//	int x1; int x2;
//	int i = 0;
//	int j = 0;
//	while (j<10)
//	{
//		j++;
//		i++;
//		temp = q.top();
//		q.pop();
//		q.push(temp - y);
//		x1 = allhuoqiu();
//		x2 = allxuanf();
//		if (x1 + i < mins3) mins3 = x1 + i;
//		if (x2 + i < mins3) mins3 = x2 + i; 
//	}
//	printf("%d", fi+min(mins3, s));
//}