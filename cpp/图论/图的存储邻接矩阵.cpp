//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <time.h>
//#include <windows.h>
//using namespace std;
//int v,e,w;//w是边权值
//int edge[100][100];
////这是有向图存储
//int main()
//{
//	cout << "请输入顶点数目";
//	cin >> v;
//	cout << "输入边数";
//	cin >> e;
//	memset(edge, -1, sizeof(edge));
//	for (int i = 1; i <= v; i++)
//	{
//		edge[i][i] = 0;
//	}
//	int tempx, tempy, tempw;
//	for (int i = 0; i < e; i++)
//	{
//		cin >> tempx >> tempy>>tempw;
//		edge[tempx][tempy] = tempw;
//	}
//	cout << "输出边的信息:" << endl;
//	for (int i = 1; i <= v; i++)
//	{
//		for (int j = 1; j <= v; j++)
//		{
//			if (edge[i][j] != -1&& edge[i][j] != 0)
//			{
//				cout << i <<"到"<< j <<"的代价为"<< edge[i][j]<<endl;
//			}
//		}
//	}
//}