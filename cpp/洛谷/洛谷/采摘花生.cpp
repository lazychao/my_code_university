#include<cstdio>
#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;
typedef struct pos
{
	int x; int y;
	int v;//花生个数
	int c;//回到路边的代价
}pos;
bool mycompare(pos a, pos b)
{
	return a.v > b.v;
}
int main()
{
	
	int m, n, k;
	pos poss[21 * 21];
	cin >> m >> n >> k;
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> poss[(i)*n + j].v;
			poss[(i)*n+ j].x = j;
			poss[i*n + j].y = i;
			poss[i*n + j].c = i + 1;
		}
	}
	sort(poss, poss + m * n,mycompare);
	int i = 0;
	int sum = 0;
	/*if (k < poss[i].c)
	{
		cout << 0;
		return 0;
	}
	k -= poss[i].c;*/
	int cost = poss[i].c +1;
	while (poss[i].v != 0)
	{
		if (k < cost+poss[i].c)
		{
			break;
		}
		else
		{
			k -= cost;
			sum += poss[i].v;
			if (i + 1 == m * n)break;
			else
			{
				cost=abs(poss[i+1].x-poss[i].x)+
					abs(poss[i + 1].y - poss[i].y)+1;
				
			}
			
		}
		i++;

	}
	cout << sum;
	return 0;
}