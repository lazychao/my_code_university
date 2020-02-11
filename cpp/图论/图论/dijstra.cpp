#include<cstdio> 
#include<vector>
#include <iostream> 
using namespace std;
#define inf 0x70ffffff//初始距离不要初始化int的最大  否则判断时他再加上一个值就爆了
int dis[20];
int map[20][20];
int vis[20];
int main()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = inf;
		}
	}//初始化 
	int n, m;
	cin >> n >> m;
	int tempx, tempy, tempvalue;
	for (int i = 0; i < m; i++)
	{
		cin >> tempx >> tempy >> tempvalue;
		tempx--; tempy--;//1~n映射到0~n-1     
		map[tempy][tempx] = map[tempx][tempy] = tempvalue;
	}
	dis[0] = 0; vis[0] = 1;//一开始起点就要是被访问过得   
	for (int i = 0; i < n; i++)
	{
		dis[i] = map[0][i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a = -1;//记录编号不能为0      
		int b = inf;//记录距离        
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && dis[j] < b)
			{
				b = dis[j];
				a = j;
			}
		}//此过程是要找出未成为固定编号且目前距离最短，可以用优先队列优化     
		vis[a] = 1;//临时编号变成固定编号。        
		if (a == -1)break;
		for (int k = 0; k < n; k++)
		{
			if (!vis[k] && ((b + map[a][k]) < dis[k]))
			{
				dis[k] = b + map[a][k];
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (dis[i] == inf)
			cout << "1号城市到" << i + 1 << "号城市无路可走" << endl;
		else cout << "1号城市到" << i + 1 << "号城市最短距离为" << dis[i] << endl;
	}
	return 0;
}