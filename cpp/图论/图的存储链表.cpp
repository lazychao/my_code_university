//#include<cstdio>
//#include<iostream>
//using namespace std;
//int v;
//int e;
//typedef struct arcnode//弧结点和顶点结点不一样
//{
//	int v;
//	int weight;
//	struct arcnode *next;
//}arcnode;
//typedef struct vnode//顶点结点
//{
//	int v;
//	struct arcnode *next;
//}vnode;
//vnode vlist[100];
//int main()
//{
//	for (int i = 0; i < 100; i++)//对头插法需要这样，，全局变量并不能把指针初始化为空
//	{
//		vlist[i].next = NULL;
//	}
//	cout << "请输入顶点数目";
//	cin >> v;
//	cout << "输入边数";
//	cin >> e;
//	cout << "请输入边：" << endl;
//	int tempx, tempy, tempw;
//	for (int i = 0; i < e; i++)
//	{
//		cin >> tempx >> tempy>> tempw;
//		//采用头插入法，尾插入太麻烦了，还得设变量
//		/*arcnode p;*/
//		arcnode *p = new arcnode;
//		p->weight = tempw;
//		p->v = tempy;
//		//p.next = NULL;//这个很关键  对于尾插法来说
//		p->next = vlist[tempx].next;
//		vlist[tempx].next = p;
//	}
//	cout << "输出边的信息:" << endl;
//	arcnode*p;
//	for (int i = 1; i <= v; i++)
//	{
//		p = vlist[i].next;
//		while (p)
//		{
//			cout << i << "到" << p->v << "的代价为" << p->weight << endl;;
//			p = p->next;
//		}
//	}
//}