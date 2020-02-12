#include <cstdio>
#include <iostream>
using namespace std;
int n, m;//棋盘大小
int vis[100][100];
int flag;

int dir[8][2] = { {1,2}, {1,-2} ,{2,1} ,{2,-1},{-1,2}, {-1,-2},{-2,1}, {-2,-1} };
void dfs(int x, int y,int cur,int x2,int y2)
{

	if ( x2 == x && y2 == y)
	{
		cout << cur << endl;
		flag = 1;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (x + dir[i][0]<1 || x + dir[i][0] > n || y + dir[i][1]<1
			|| y + dir[i][1] >m||vis[x + dir[i][0]][y + dir[i][1]])
		{
		}
		else
		{
			vis[x + dir[i][0]][y + dir[i][1]] = 1;
			dfs(x+dir[i][0], y+dir[i][1],cur+1, x2,  y2);
		}

	}

}
int main()
{
	
	int x1, y1;//起始位置
	int N;//测试数量
	int x2, y2;//结束位置
	cin >> n >> m;
	cin >> x1 >> y1;
	
	cin >> N;
	for (int i = 0; i <N; i++)
	{
		cin >> x2 >> y2;
		flag = 0;
		memset(vis, 0, sizeof(vis));
		vis[x1][y1] = 1;
		dfs(x1, y1, 0,x2,y2);
		if (!flag)cout << -1 << endl;
	}
	return 0;
}