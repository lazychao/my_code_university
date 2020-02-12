/*�㷨�������ҽ�����kruscal��С��������˼�룬�Ա߽��д��������Թ�
Ϊn*m  ��Ŀ��Ϊ����һ���������������n*m������ͨ����kruscal��С��������
Щ������������ѡȡ�߲�����ѡ��СȨ�أ��������ѡȡ������˼�������ͬ���������˲��鼯
���ж�ѡȡ�ıߵ������˵��Ƿ���ͬһ��������
�����ﵥλ����·����ǽ�ڶ�����һ�������ʾ  ��ʼʱ�� ������������֮����һ��ǽ��
*/
/*Ѱ·�㷨����A*�㷨����������F=G+H,HѡΪ�����پ��롣�㷨���̣�ÿ��ѡ��F��С
����δ����visited���ĵ�ȥ��������Χ�ĵ�(����С���Ż�)��ֱ����Ŀ�����close��
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<time.h>
#include<queue>
#include<algorithm>
using namespace std;
#define inf 0x7f7f7f7f
typedef struct edge
{
	int fromx,fromy; int tox,toy;
}edge;
typedef struct node
{
	int x, y;
}node;
typedef struct path_node
{
	int x, y;
	int visited;
	int F, G, H;
	int prex, prey;//�ô洢·��������ǰ���ڵ�
}path_node;
struct cmp {
		bool operator () (path_node  a, path_node b)	  
		{
			return a.F > b.F;
		}//����FС��
	};
	
	
priority_queue <path_node,vector<path_node>,cmp> q;
node nodes[1000][1000];
path_node path_nodes[1000][1000];
int maze[1000][1000];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
//int visted[1000][1000];
int n, m;//�Թ��Ĵ�С n��m��
int path[1000][1000];//���ڴ洢·��
int pre[1000];//ÿ�����Ӧ���ϴ󣬲�һ���ǰ�������ϣ���Ż��ɰ���(·��ѹ����
int findboss(int me)
{
	int boss;
	int temp = me;//������, me���ܱ�
	while (temp != pre[temp])//��������  ֱ��boss�����Լ�
	{
		temp = pre[temp];
	}
	boss = temp;//boss�����Ա�

	//·��ѹ��
	temp = me;
	int temp2;//�ݴ�ԭ������һ��
	while (temp != pre[temp])
	{
		temp2 = pre[temp];
		pre[temp] = boss;
		temp = temp2;
	}
	//·��ѹ�� ��ÿһ����pre����Ϊboss
	return boss;
}//���˲��鼯����
void A_star()
{
	int endx = 2*n - 1, endy =2*m- 1;
	path_node temp;int tempx, tempy;
	for (int i = 1; i <= 2*n; i++)
	{
		for (int j = 1; j <= 2*m; j++)
		{
			path_nodes[i][j].x = i;
			path_nodes[i][j].y = j;
			path_nodes[i][j].F = inf;
		}
	}
	path_nodes[1][1].G = 0; path_nodes[1][1].F = 0;
	path_nodes[1][1].prex = 1; path_nodes[1][1].prey = 1;
	q.push(path_nodes[1][1]);
	while (path_nodes[endx][endy].visited != 1)
	{
		temp=q.top();
		q.pop();
		path_nodes[temp.x][temp.y].visited = 1;
		for (int i = 0; i < 4; i++)
		{
			tempx = temp.x + dir[i][0]; tempy = temp.y + dir[i][1];
			if (maze[tempx][tempy])
			{
				path_nodes[tempx][tempy].G = temp.G + 1;
				path_nodes[tempx][tempy].H = endx - tempx + endy - tempy;
				
				if (path_nodes[tempx][tempy].F > path_nodes[tempx][tempy].G + path_nodes[tempx][tempy].H)
				{
					path_nodes[tempx][tempy].F = path_nodes[tempx][tempy].G + path_nodes[tempx][tempy].H;
					path_nodes[tempx][tempy].prex = temp.x;
					path_nodes[tempx][tempy].prey = temp.y;
					q.push(path_nodes[tempx][tempy]);//��С�˲ŷŽ�ȥ
				}
			}//��������Ҫȥ�����ѷ�����еĽڵ� ֱ�ӰѸ��º�ļӽ�ȥ�ͺ��ˣ����ܻ��˷ѿռ�
		}
	}
}
void save_path(int i,int j)
{
	if (path_nodes[i][j].prex == i && path_nodes[i][j].prey == j)
	{
		path[i][j] = 1;
		return;
	}
	else
	{
		path[i][j] = 1;
		save_path(path_nodes[i][j].prex, path_nodes[i][j].prey);
	}

}
int main()
{
	srand(time(0));
	cout << "�������Թ���С��"; cin >> n >> m;
	if (n < 2 || m < 2) {
		cout << "�Թ���С����";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			nodes[i][j].x = i; nodes[i][j].y = j;
			maze[2 * i - 1][2 * j - 1] = 1;
		}
	}//�Թ���ʼ��
	vector<edge> es;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			edge e; e.fromx = nodes[i][j].x; e.fromy = nodes[i][j].y;
			e.tox = nodes[i][j+1].x; e.toy = nodes[i][j+1].y;
			es.push_back(e);
		}
	}//�洢���
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			edge e; e.fromx = nodes[j][i].x; e.fromy = nodes[j][i].y;
			e.tox = nodes[j+1][i].x; e.toy = nodes[j+1][i].y;
			es.push_back(e);
		}
	}//�洢����
	
	for (int i = 1; i <= n*m; i++)
	{
		pre[i] = i;//�ʼÿ���˶��Լ����Լ��ϴ�
	}
	edge temp;
	int randpos;
	while(!es.empty())
	{
		randpos = rand() % (es.size());
		temp = es[randpos];//�����ѡһ����
		es.erase(es.begin() +randpos, es.begin() + randpos+1);//Ȼ��ɾ����
		int boss1 = findboss((temp.fromx-1)*m+temp.fromy);
		int boss2 = findboss((temp.tox - 1)*m + temp.toy);
		if (boss1 != boss2)
		{
			maze[temp.fromx + temp.tox - 1][temp.fromy + temp.toy - 1]=1;//�����˵�
			//��Ӧ��ǽ���
			pre[boss1] = boss2;//�ϲ�����
		}
	}
	//A*�㷨Ѱ��ͨ·
	A_star();
	save_path(2 * n - 1, 2 * m - 1);
	for (int i = 0; i <= 2*n; i++)
	{
		for (int j = 0; j <= 2 * m ;j++)
		{
			if (path[i][j])
			{
				cout <<"��";
			}
			else if (maze[i][j])
			{
				cout << "  ";
			}
			else
			{
				cout << "��";
			}
		}
		cout << endl;
	}
	
	
}

