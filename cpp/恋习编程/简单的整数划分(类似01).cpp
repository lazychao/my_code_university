//#include <cstdio>
//#include <iostream>
//using namespace std;
//int dp[51][51];
//int main()
//{
//	int n;
//	
//	while (scanf("%d", &n) != EOF)
//	{
//		dp[0][0] = 1;
//		for (int i = 1; i <= n; i++)
//		{
//			dp[i][1] = 1;
//			dp[0][i] = 0;
//			dp[i][0] = 0;
//		}
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= i; j++)
//			{
//				if(j-1>i-j)//用这些if语句都是为了防止dp[i][j]中的j>i 
//					//其实归根结底就是dp[i][j] = dp[i][j - 1] + dp[i - j][j];
//					dp[i][j] = dp[i][j - 1] + dp[i - j][i-j];
//				else if(j>i-j)
//					dp[i][j] = dp[i][j - 1] + dp[i - j][i-j];//不是dp[i - j][j - 1],,j可以被选不止一次
//				else
//					dp[i][j] = dp[i][j - 1] + dp[i - j][j];
//			}
//		}
//		cout << dp[n][n] << endl;
//	}
//}