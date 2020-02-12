#include<cstdio> 
#include<vector>
#include <iostream> 
using namespace std;
#define inf 0x70ffffff//��ʼ���벻Ҫ��ʼ��int�����  �����ж�ʱ���ټ���һ��ֵ�ͱ���
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
	}//��ʼ�� 
	int n, m;
	cin >> n >> m;
	int tempx, tempy, tempvalue;
	for (int i = 0; i < m; i++)
	{
		cin >> tempx >> tempy >> tempvalue;
		tempx--; tempy--;//1~nӳ�䵽0~n-1     
		map[tempy][tempx] = map[tempx][tempy] = tempvalue;
	}
	dis[0] = 0; vis[0] = 1;//һ��ʼ����Ҫ�Ǳ����ʹ���   
	for (int i = 0; i < n; i++)
	{
		dis[i] = map[0][i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a = -1;//��¼��Ų���Ϊ0      
		int b = inf;//��¼����        
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && dis[j] < b)
			{
				b = dis[j];
				a = j;
			}
		}//�˹�����Ҫ�ҳ�δ��Ϊ�̶������Ŀǰ������̣����������ȶ����Ż�     
		vis[a] = 1;//��ʱ��ű�ɹ̶���š�        
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
			cout << "1�ų��е�" << i + 1 << "�ų�����·����" << endl;
		else cout << "1�ų��е�" << i + 1 << "�ų�����̾���Ϊ" << dis[i] << endl;
	}
	return 0;
}