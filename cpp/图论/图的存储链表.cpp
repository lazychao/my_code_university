//#include<cstdio>
//#include<iostream>
//using namespace std;
//int v;
//int e;
//typedef struct arcnode//�����Ͷ����㲻һ��
//{
//	int v;
//	int weight;
//	struct arcnode *next;
//}arcnode;
//typedef struct vnode//������
//{
//	int v;
//	struct arcnode *next;
//}vnode;
//vnode vlist[100];
//int main()
//{
//	for (int i = 0; i < 100; i++)//��ͷ�巨��Ҫ��������ȫ�ֱ��������ܰ�ָ���ʼ��Ϊ��
//	{
//		vlist[i].next = NULL;
//	}
//	cout << "�����붥����Ŀ";
//	cin >> v;
//	cout << "�������";
//	cin >> e;
//	cout << "������ߣ�" << endl;
//	int tempx, tempy, tempw;
//	for (int i = 0; i < e; i++)
//	{
//		cin >> tempx >> tempy>> tempw;
//		//����ͷ���뷨��β����̫�鷳�ˣ����������
//		/*arcnode p;*/
//		arcnode *p = new arcnode;
//		p->weight = tempw;
//		p->v = tempy;
//		//p.next = NULL;//����ܹؼ�  ����β�巨��˵
//		p->next = vlist[tempx].next;
//		vlist[tempx].next = p;
//	}
//	cout << "����ߵ���Ϣ:" << endl;
//	arcnode*p;
//	for (int i = 1; i <= v; i++)
//	{
//		p = vlist[i].next;
//		while (p)
//		{
//			cout << i << "��" << p->v << "�Ĵ���Ϊ" << p->weight << endl;;
//			p = p->next;
//		}
//	}
//}