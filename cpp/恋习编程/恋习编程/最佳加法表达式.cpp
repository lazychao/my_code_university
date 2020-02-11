//#include<cstdio>
//#include <iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int dp[55][55];
//int nums[55][55];
//int len;
//int main()
//{
//	int n;//加号数
//	char a[55];
//	while (scanf("%d", &n) != EOF)
//	{
//		cin >> a;
//		len = strlen(a);//数字数
//		memset(dp, 0x3f, sizeof(dp));
//		//预处理 求出i到j 的字符组成的数字
//		for (int i = 1; i <=len; i++)
//		{
//			nums[i][i] = a[i-1]-'0';
//			for (int j = i + 1; j <= len; j++)
//			{
//				nums[i][j] = 10 * nums[i][j - 1] + a[j-1]-'0';
//			}
//		}
//		for (int i = 1; i <= len; i++)
//		{
//			dp[0][i] = nums[1][i];
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = i + 1; j <= len; j++)
//			{
//				for (int k = i; k <= j - 1; k++)//从第i个空到第j-1个空
//				{
//					dp[i][j] = min(dp[i][j], dp[i - 1][k] + nums[k + 1][j]);//不是nums[k+1][len]
//				}
//			}
//		}cout << dp[n][len] << endl;;
//	}
//	
//}