//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//using namespace std;
//struct arc1
//{
//	int from; int to; int weight;
//}arc[1000];
//
//int pre[1000];//ÿ�����Ӧ���ϴ󣬲�һ���ǰ�������ϣ���Ż��ɰ���(·��ѹ����
//int findboss(int me)
//{
//	int boss;
//	int temp = me;//������, me���ܱ�
//	while (temp != pre[temp])//��������  ֱ��boss�����Լ�
//	{
//		temp = pre[temp];
//	}
//	boss = temp;//boss�����Ա�
//
//	//·��ѹ��
//	temp = me;
//	int temp2;//�ݴ�ԭ������һ��
//	while (temp != pre[temp])
//	{
//		temp2 = pre[temp];
//		pre[temp] = boss;
//		temp = temp2;
//	}
//	//·��ѹ�� ��ÿһ����pre����Ϊboss
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
//	int totweight=0;//��С�������Ĵ���
//	int v, e;
//	cout << "�����붥�����ͱ���";
//	cin >> v >> e;
//	for (int i = 1; i <= v; i++)
//	{
//		pre[i] = i;//�ʼÿ���˶��Լ����Լ��ϴ�
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