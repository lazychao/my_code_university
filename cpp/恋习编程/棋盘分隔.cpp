//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int s[9][9];
//int sum[9][9];
//double res[15][9][9][9][9];
//double squaresum;
//int calsum(int x1, int y1, int x2, int y2)
//{
//	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
//}
//double fun(int n, int x1, int y1, int x2, int y2)
//{
//	double m=100000;
//	if (n == 1)
//	{
//		double temp = calsum(x1, y1, x2, y2)*calsum(x1, y1, x2, y2);
//		res[n][x1][y1][x2][y2] = temp;
//		return temp;
//	}
//	for (int i = y1; i < y2; i++)
//	{
//		double temp = min((fun(n - 1, x1, y1, x2, i) + fun(1, x1, i + 1, x2, y2)), (fun(1, x1, y1, x2, i) + fun(n-1, x1, i + 1, x2, y2)));
//		if(temp<m)
//		{
//			m = temp;
//		}
//	}
//	for (int i = x1; i < x2; i++)
//	{
//		double temp = min((fun(n - 1, x1, y1, i+1, y2) + fun(1, i+1, y1, x2, y2)), (fun(1, x1, y1, i+1,y2) + fun(n - 1, i+1, y1, x2, y2)));
//		if (temp < m)
//		{
//			m = temp;
//		}
//	}
//	res[n][x1][y1][x2][y2] = m;
//	return m;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int rowsum = 0;
//	double average = 0;
//	for (int j = 1; j <= 8; j++)
//	{
//		rowsum = 0;
//		for (int i = 1; i <= 8; i++)
//		{
//			cin >> s[i][j];
//			rowsum += s[i][j]; average += s[i][j];
//			sum[i][j] += sum[i][j - 1] + rowsum;
//		}
//		average /= 64;
//		squaresum=fun(n,1,1,8,8);
//		cout << squaresum - n * average*average;
//	}
//
//
//}