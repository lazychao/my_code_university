//#include<cstdio>
//#include<iostream>
//using namespace std;
//typedef struct node
//{
//	struct node *next;
//	int num;
//}node,*nodeptr;
////��Ⱦ�̬����  ��Ҫ��̬�����ڴ� �����������ٶ�
//int main()
//{
//	int n, k, m;//ʣ��k���ˣ���m�����˳�
//	//����������
//	cin >> n >> k >> m;
//	nodeptr head=new node;
//	head->next = NULL;
//	head->num = 1;//ͷ���Ҳ����Ҫ��������
//	//for (int i = n; i > 0; i--)//����ͷ�巨
//	//{
//	//	nodeptr p = new node;
//	//	p->num = i;
//	//	p->next = head->next;
//	//	head->next = p;
//	//}
//	//Ӧ�ò���β�巨����ΪҪʵ��ѭ������
//	nodeptr tail = head;//head �������ռ䣬��tail�Ͳ���Ҫ�˷���tailһ����
//	//ָ��ʵ��ռ�
//	for (int i = 2; i <= n; i++)
//	{
//		nodeptr p = new node;
//		p->num = i;
//		p->next = tail->next;
//		tail->next = p;
//		tail = p;
//	}
//	tail->next = head;
//	//������ѭ������͹�����
//	nodeptr p = tail;
//	nodeptr q;
//	int out_totle = n - k;
//	for (int i = 0; i < out_totle; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			q = p;//Ҫ��¼��p��ǰһ��λ��
//			p = p->next;
//		}
//		q->next = p->next;
//		delete p;
//		p = q;
//	}
//	cout << p->num<<' ';
//	p = p->next;
//	//�������Ҳ���ͷ�ģ���������� �����޷����������
//	//����������ڽڵ��м�һ��flag ���Ƿ��ѱ�ɾ��  �����Ϳ����������
//	while (p != q)
//	{
//		cout << p->num << ' ';
//		p = p->next;
//	}
//}