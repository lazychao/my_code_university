//#include <cstdio>
//#include <iostream>
//#include<queue>
//using namespace std;
//int n, m;//棋盘大小
//int vis[100][100];
//int flag;
//int tempx, tempy;
////起始位置
//int N;//测试数量
////要定义结构体二维数组
//typedef struct node
//{
//	int x; int y;
//	int path;
//}node;
//node map[500][500];
//queue<node> a;
//queue<node> q;
//int dir[8][2] = { {1,2}, {1,-2} ,{2,1} ,{2,-1},{-1,2}, {-1,-2},{-2,1}, {-2,-1} };
//void bfs()
//{
//	while (!q.empty())
//	{
//		node temp = q.front();
//		q.pop();
//		for (int i = 0; i < 8; i++)
//		{
//			if (temp.x + dir[i][0] >= 1 && temp.x + dir[i][0] <= n && temp.y + dir[i][1] >= 1
//				&& temp.y + dir[i][1] <= m&& map[temp.x + dir[i][0]][temp.y + dir[i][1]].path==0)
//			{
//				map[temp.x + dir[i][0]][temp.y + dir[i][1]].path = temp.path + 1;
//				q.push(map[temp.x + dir[i][0]][temp.y + dir[i][1]]);
//			}
//		}
//	}
//
//}
//int main()
//{
//
//	
//	node end;//结束位置
//	cin >> n >> m;
//
//	cin >> tempx >> tempy;
//
//	cin >> N;
//	for (int i = 0; i < 500; i++)
//	{
//		for(int j = 0; j < 500; j++)
//		{
//			map[i][j].x = i;
//			map[i][j].y = j;
//		}
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cin >> end.x >> end.y;
//		a.push(end);
//	}
//	map[tempx][tempy].path = 1;
//	q.push(map[tempx][tempy]);
//	bfs();
//	while (!a.empty())
//	{
//		end = a.front();
//		a.pop();
//		if (!map[end.x][end.y].path)
//			cout << -1 << endl;
//		else
//			cout << map[end.x][end.y].path - 1 << endl;
//	}
//	return 0;
//}