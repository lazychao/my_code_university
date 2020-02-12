/*算法简述：我将利用kruscal最小生成树的思想，对边进行处理，假设迷宫
为n*m  则目标为产生一颗随机生成树，将n*m个点连通，与kruscal最小生成树的
些许区别是这里选取边并不是选最小权重，而是随机选取，其余思想基本相同，都利用了并查集
来判断选取的边的两个端点是否在同一个集合中
在这里单位长度路径和墙壁都是用一个方块表示  初始时刻 相邻两个顶点之间有一个墙壁
*/
/*寻路算法采用A*算法，启发函数F=G+H,H选为曼哈顿距离。算法流程，每次选择F最小
且尚未加入visited集的点去更新其周围的点(用最小堆优化)，直到把目标加入close集
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
	int prex, prey;//用存储路径，这是前驱节点
}path_node;
struct cmp {
		bool operator () (path_node  a, path_node b)	  
		{
			return a.F > b.F;
		}//返回F小的
	};
	
	
priority_queue <path_node,vector<path_node>,cmp> q;
node nodes[1000][1000];
path_node path_nodes[1000][1000];
int maze[1000][1000];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
//int visted[1000][1000];
int n, m;//迷宫的大小 n行m列
int path[1000][1000];//用于存储路径
int pre[1000];//每个点对应的老大，不一定是帮主，但希望优化成帮主(路径压缩）
int findboss(int me)
{
	int boss;
	int temp = me;//迭代器, me不能变
	while (temp != pre[temp])//逐级往上找  直到boss就是自己
	{
		temp = pre[temp];
	}
	boss = temp;//boss不可以变

	//路径压缩
	temp = me;
	int temp2;//暂存原来的上一级
	while (temp != pre[temp])
	{
		temp2 = pre[temp];
		pre[temp] = boss;
		temp = temp2;
	}
	//路径压缩 把每一级的pre都设为boss
	return boss;
}//此乃并查集操作
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
					q.push(path_nodes[tempx][tempy]);//变小了才放进去
				}
			}//无需想着要去更新已放入队列的节点 直接把更新后的加进去就好了，尽管会浪费空间
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
	cout << "请输入迷宫大小："; cin >> n >> m;
	if (n < 2 || m < 2) {
		cout << "迷宫大小有误";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			nodes[i][j].x = i; nodes[i][j].y = j;
			maze[2 * i - 1][2 * j - 1] = 1;
		}
	}//迷宫初始化
	vector<edge> es;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			edge e; e.fromx = nodes[i][j].x; e.fromy = nodes[i][j].y;
			e.tox = nodes[i][j+1].x; e.toy = nodes[i][j+1].y;
			es.push_back(e);
		}
	}//存储横边
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			edge e; e.fromx = nodes[j][i].x; e.fromy = nodes[j][i].y;
			e.tox = nodes[j+1][i].x; e.toy = nodes[j+1][i].y;
			es.push_back(e);
		}
	}//存储竖边
	
	for (int i = 1; i <= n*m; i++)
	{
		pre[i] = i;//最开始每个人都自己是自己老大
	}
	edge temp;
	int randpos;
	while(!es.empty())
	{
		randpos = rand() % (es.size());
		temp = es[randpos];//随机挑选一条边
		es.erase(es.begin() +randpos, es.begin() + randpos+1);//然后删除它
		int boss1 = findboss((temp.fromx-1)*m+temp.fromy);
		int boss2 = findboss((temp.tox - 1)*m + temp.toy);
		if (boss1 != boss2)
		{
			maze[temp.fromx + temp.tox - 1][temp.fromy + temp.toy - 1]=1;//把两端点
			//对应的墙拆除
			pre[boss1] = boss2;//合并集合
		}
	}
	//A*算法寻找通路
	A_star();
	save_path(2 * n - 1, 2 * m - 1);
	for (int i = 0; i <= 2*n; i++)
	{
		for (int j = 0; j <= 2 * m ;j++)
		{
			if (path[i][j])
			{
				cout <<"☆";
			}
			else if (maze[i][j])
			{
				cout << "  ";
			}
			else
			{
				cout << "■";
			}
		}
		cout << endl;
	}
	
	
}

