//#include<cstdio>
//#include<iostream>
//using namespace std;
//int pre[1000];//每个点对应的老大，不一定是帮主，但希望优化成帮主(路径压缩）
//int findboss(int me)
//{
//	int boss;
//	int temp=me;//迭代器, me不能变
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
//int main()
//{
//	int n,m;
//	cout << "输入点个数:"; cin >> n;
//	int num=n;//帮派数量  一开始是n个
//	for (int i = 1; i <= n; i++)
//	{
//		pre[i] = i;//最开始每个人都自己是自己老大
//	}
//	//开始结拜   相当于是在找两个点连成边
//	cout << "请输入结拜次数："; cin >> m;
//	int x, y;//这两个要结拜  引发两个帮派合并
//	int boss1, boss2;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> x >> y;
//		boss1=findboss(x);
//		boss2 = findboss(y);
//		if (boss1 != boss2)
//		{
//			pre[boss1] = boss2;//其中一个boss认另一个为boss
//			num--;//少一个帮派
//		}
//		cout << "还有" << num << "个帮派" << endl;
//	}
//	
//}