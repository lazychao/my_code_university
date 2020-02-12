#ifndef LinkedList
#define LinkedList
#include <cstdio>
#include <iostream>
using namespace std; 
typedef int ElemType;
typedef enum Status
{
	success, fail, fatal, rangeerror
	//����Ҫ�ֺ�
}Status;
typedef struct node
{
	ElemType data;
	struct node *next;
}ListNode, *ListNodeptr;
class MyLinkedList
{
private:
	ListNodeptr head;//ͷָ�벻Ӧ������Ϊ��
public:
	MyLinkedList();//����Ҫ��һ����ʼ��������head����ռ伴headͷ���Ŀռ�һ��Ҫ�ȷ���
	//��Ȼ�еĺ����޷�ʹ��. next
	ListNodeptr Create_head(ElemType n);
	ListNodeptr Create_tail(ElemType n);
	ElemType retrieve(ElemType pos);//���ص�pos��Ԫ��
	ElemType locate( ElemType num);
	void insert();
	void Print();
	bool isempty();
	ElemType length();
	void remove(ElemType pos);//�����±�
	~MyLinkedList();
};

MyLinkedList::MyLinkedList()
{
	head = new ListNode;
	head->next = NULL;
}
ListNodeptr  MyLinkedList::Create_head(ElemType n)//ͷ���뷨
{
	Status status = fail;
	if (n > 0)
	{
		ListNodeptr p;
		for (int i = 0; i < n; i++)//�ٴ���n���ڵ�   ��Ϊͷ�ڵ㲻������
		{
			cout << "�������" << i + 1 << "���ڵ�:";
			p = new ListNode;
			cin >> p->data;
			p->next = head->next;
			head->next = p;
		}
		status = success;
	}
	return head;
}
ListNodeptr MyLinkedList::Create_tail(ElemType n)//β���뷨
{
	Status status = fail;
	if (n > 0)
	{
		ListNodeptr p,tail;//������һ��βָ����ٵ������β����Ȼÿ����һ����Ҫѭ������β
		//�����ַ�������ʵ������洢����

		tail = head;
		for (int i = 0; i < n; i++)
		{
			cout << "�������" << i + 1 << "���ڵ�:";
			p = new ListNode;
			cin >> p->data;
			p->next = tail->next;
			tail->next = p;//p�ӵ���tail�ĺ���
			tail = p;//p��Ϊtail
		}
		status = success;
	}
	return head;
}
MyLinkedList::~MyLinkedList()
{
	ListNodeptr p = head,q;
	while (p)
	{	
		q = p->next;
		delete p;//�ͷſռ䣬pָ�뻹�ǿ���ʹ�õ�
		p = q;
	}
}
void MyLinkedList::Print()
{
	ListNodeptr p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
void MyLinkedList::insert()
{
	ListNodeptr p=head;
	while (p->next)
	{
		p = p->next;
	}
	ListNodeptr q = new ListNode;
	cout << "������Ҫ���������:";
	cin >> q->data;
	q->next = p->next;
	p->next = q;
}
void MyLinkedList::remove(ElemType pos)
{
	ListNodeptr p=head->next;
	ElemType i = 1;
	while (p&&i<pos-1)//Ӧ�ö�λ��pos-1��λ��
	{
		p = p->next;
		++i;
	}
	if (!p)
	{
		cout << "range_error";
		return;
	}
	if (i == pos-1)
	{
		ListNodeptr q= p->next->next;
		delete p->next;
		p->next = q;
	}
}
ElemType MyLinkedList::retrieve(ElemType pos)
{
	int num;
	Status status = fail; ElemType i = 1;
	ListNodeptr p = head->next;
	while (i < pos&&p)
	{
		++i;
		p = p->next;
	}
	if (i == pos && p)
	{
		status = success;
		num = p->data;
	}
	return num;
}
ElemType MyLinkedList::locate( ElemType num)
{
	ElemType pos;
	Status status = fail;
	ListNodeptr p = head->next; ElemType i = 1;
	while (p)
	{
		if (p->data == num)
		{
			break;
		}
		++i;
		p = p->next;
	}
	if (p)
	{
		status = success;
		pos = i;
	}
	return pos;
}
ElemType MyLinkedList::length()
{
	ElemType l;
	ElemType i = 0;
	ListNodeptr p = head->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	l = i;
	return l;
}
bool MyLinkedList::isempty()
{
	return head->next == NULL;
}
#endif