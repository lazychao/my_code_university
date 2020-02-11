//#include<cstdio>
//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int T;int n, m, l, r, a, b, c, d;
//	cin >> T;
//	while (T--)
//	{
//		
//		cin >> n >> m >> l >> r >> a >> b >> c >> d;
//		if (l < b&&b < r&&l < d&&d < r)
//		{
//			int sum1 = b - l + abs(a - c) + d - l;
//			int sum2= r-b  + abs(a - c) + r-d;
//			printf("%d\n", sum1 > sum2 ? sum2 : sum1);
//
//		}
//		else if (a == c)
//		{
//			printf("%d\n", abs(b-d));
//		}
//		else
//		{
//			printf("%d\n", abs(a - c) + abs(b - d));
//		}
//	}
//	return 0;
//}