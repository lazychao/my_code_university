//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <time.h>
//#include <windows.h>
//using namespace std;
//int v,e,w;//w�Ǳ�Ȩֵ
//int edge[100][100];
////��������ͼ�洢
//int main()
//{
//	cout << "�����붥����Ŀ";
//	cin >> v;
//	cout << "�������";
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
//	cout << "����ߵ���Ϣ:" << endl;
//	for (int i = 1; i <= v; i++)
//	{
//		for (int j = 1; j <= v; j++)
//		{
//			if (edge[i][j] != -1&& edge[i][j] != 0)
//			{
//				cout << i <<"��"<< j <<"�Ĵ���Ϊ"<< edge[i][j]<<endl;
//			}
//		}
//	}
//}