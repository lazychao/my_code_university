//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct arc1
//{
//	int from; int to; int weight;
//}arc[1000];
//
//int pre[1000];//每个点对应的老大，不一定是帮主，但希望优化成帮主(路径压缩）
//int findboss(int me)
//{
//	int boss;
//	int temp = me;//迭代器, me不能变
//	while (temp != pre[temp])//逐级往上找  直到boss就是自己
//	{
//		temp = pre[temp];
//	}
//	boss = temp;//boss不可以变
//
//	//路径压缩
//	temp = me;
//	int temp2;//暂存原来的上一级
//	while (temp != pre[temp])
//	{
//		temp2 = pre[temp];
//		pre[temp] = boss;
//		temp = temp2;
//	}
//	//路径压缩 把每一级的pre都设为boss
//	return boss;
//}
//bool mycmp(arc1 a, arc1 b)
//{
//	if (a.weight < b.weight)
//		return true;
//	return false;
//}
//int main()
//{
//	int totweight=0;//最小生成树的代价
//	int v, e;
//	cout << "请输入顶点数和边数";
//	cin >> v >> e;
//	for (int i = 1; i <= v; i++)
//	{
//		pre[i] = i;//最开始每个人都自己是自己老大
//	}
//	int tempx, tempy,tempw;
//	for (int i = 1; i <= e; i++)
//	{
//		cin>>tempx>>tempy>>tempw;
//		arc[i].from = tempx;
//		arc[i].to = tempy;
//		arc[i].weight = tempw;
//	}
//	sort(arc+1,arc+e+1,mycmp);
//	for (int i = 1; i <= e; i++)
//	{
//		int boss1=findboss(arc[i].from);
//		int boss2 = findboss(arc[i].to);
//		if (boss1 != boss2)
//		{
//			totweight += arc[i].weight;
//			pre[boss1] = boss2;
//		}
//	}
//	cout << totweight;
//}