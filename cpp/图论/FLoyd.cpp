#include <cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 0x7f7f7f7f
int dp[101][101];
int path[101][101];
//采用深度优先遍历求出路径
void recursion(int i, int j)
{
	if (i==j)
	{
		cout << i;
		return;
	}
	else
	{
		recursion(i, path[i][j]);
		cout <<"->"<< j;
	}
}
int main()
{
	int n,m;
	cout << "请输入城市个数n:"; cin >> n;
	while (n > 100) {
		cout << "n最大为100，请重新输入";
		cin >> n;
	}
	while (n <=0 ) {
		cout << "请重新输入";
		cin >> n;
	}
	cout<< "请输入铁路个数m:"; cin >> m; 
	while (m <= 0) {
		cout << "请重新输入";
		cin >> m;
	}
	int tempx, tempy, tempw;
	//初始矩阵 顶点到本身的最短距离为0 到其他的距离初始为无穷
	for (int i = 1; i <=n; i++)
	{
		for (int j =1; j <= n; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
				path[i][j] = i;
			}
			else
				dp[i][j] = inf;
		}
	}
	//存储弧
	for (int i = 0; i < m; i++)
	{
		cin >> tempx >> tempy >> tempw;
		dp[tempx][tempy] = tempw;
		path[tempx][tempy] = tempx;
	}
	//以下为FLoyd算法
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <=n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (dp[i][k] + dp[k][j] < dp[i][j])
				{
					dp[i][j] = dp[i][k] + dp[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	//输出路径
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] != inf)
			{
				if (i != j)
				{
					cout << i << "城市到" << j << "城市的最小开销为" << dp[i][j] << endl;
					cout << "路径为：";
					recursion(i, j);
					cout << endl;
				}
			}
			else
			{
				cout << i << "城市无法到达" << j <<"城市"<< endl;
			}
		}
	}
}