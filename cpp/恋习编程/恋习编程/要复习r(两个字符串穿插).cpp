//#include <cstdio>
//#include <iostream>
//#include <cstring>
//using namespace std;char a[201], b[201], c[401];
//int dp[201][201];
//int len1 ;
//int len2;
//int len3 ;
//int flag;
//�����ַ����������������ܲ��ܵ��ڵ�������
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s%s%s", a, b, c);
//		len1 = strlen(a);
//		len2 = strlen(b);
//		
//		memset(dp, 0, sizeof(dp));dp[0][0]=1;
//		for (int i = 0; i <= len1; i++)
//		{
//			for (int j = 0; j <= len2; j++)
//			{//dp[i][j]ָ������������ֱ�ǰi ��j ��Ԫ���Ƿ��������� ����Ϊ1  ������Ϊ0
//				if (j > 0 && c[i + j - 1] == b[j - 1] && dp[i][j - 1] > 0)
//				{
//					dp[i][j] = 1;
//				}
//				if (i > 0 && c[i + j - 1] == a[i - 1] && dp[i - 1][j] > 0)
//				{
//					dp[i][j] = 1;
//				}
//			}
//		}
//		printf("Data set %d: %s\n", i + 1, dp[len1][len2] > 0 ? "yes" : "no");
//	}
//
//}