//#include <cstdio>
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//int maxlen[11][11];
//int main()
//{
//	char a[10],b[10];
//	cin >> a >> b;
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	for (int i = 1; i <= len1; i++)
//	{
//		for (int j = 1; j <= len2; j++)
//		{
//			if (a[i - 1] == b[j - 1])
//			{
//				maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
//			}
//			else
//			{
//				maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
//			}
//		}
//	}
//	cout << maxlen[len1][len2];
//	
//}