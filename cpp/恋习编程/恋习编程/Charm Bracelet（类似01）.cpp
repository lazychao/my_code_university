//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int v[12881];
//int w[12881];
//int dp[12881];
//int main()
//{
//	int n, m;
//	while (scanf("%d%d", &n, &m) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			scanf("%d%d", &w[i], &v[i]);
//		}
//		
//		//for (int i = 1; i <= n; i++)
//		//{
//		//	for (int j = 1; j <= m; j++)
//		//	{
//		//		if (w[i] <= j)//j��Ҫд��m
//		//			dp[j][i] = max(dp[j][i - 1], v[i] + dp[j - w[i]][i - 1]);
//		//
//		//	}
//		//}�Ѷ�άд��һά�� ���б��һά  �Ӻ���ǰд
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = m; j >=w[i]; j--)//Ҫ��j>=w[j]
//			{
//				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//				//dp[j]��ԭdp[i-1][j]    
//			}
//		}
//		printf("%d\n",dp[m]);
//	}
//}
