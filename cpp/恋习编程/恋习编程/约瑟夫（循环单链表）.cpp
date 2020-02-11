//#include<cstdio>
//#include<iostream>
//using namespace std;
//typedef struct node
//{
//	struct node *next;
//	int num;
//}node,*nodeptr;
////相比静态链表  需要动态分配内存 会拖慢运行速度
//int main()
//{
//	int n, k, m;//剩余k个人，数m个人退出
//	//建立单链表
//	cin >> n >> k >> m;
//	nodeptr head=new node;
//	head->next = NULL;
//	head->num = 1;//头结点也必须要带有数据
//	//for (int i = n; i > 0; i--)//采用头插法
//	//{
//	//	nodeptr p = new node;
//	//	p->num = i;
//	//	p->next = head->next;
//	//	head->next = p;
//	//}
//	//应该采用尾插法，因为要实现循环链表
//	nodeptr tail = head;//head 必须分配空间，但tail就不需要了反正tail一定会
//	//指向实体空间
//	for (int i = 2; i <= n; i++)
//	{
//		nodeptr p = new node;
//		p->num = i;
//		p->next = tail->next;
//		tail->next = p;
//		tail = p;
//	}
//	tail->next = head;
//	//到这里循环链表就构成了
//	nodeptr p = tail;
//	nodeptr q;
//	int out_totle = n - k;
//	for (int i = 0; i < out_totle; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			q = p;//要记录下p的前一个位置
//			p = p->next;
//		}
//		q->next = p->next;
//		delete p;
//		p = q;
//	}
//	cout << p->num<<' ';
//	p = p->next;
//	//这样是找不到头的，，可以输出 但是无法按有序输出
//	//所以最好是在节点中加一个flag 看是否已被删除  这样就可有序输出了
//	while (p != q)
//	{
//		cout << p->num << ' ';
//		p = p->next;
//	}
//}