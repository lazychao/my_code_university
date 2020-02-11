#pragma once
#ifndef DoubleLinked
#define DoubleLinked
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
	struct node* prior;
	struct node *next;
}ListNode, *ListNodeptr;
class MyDoubleLinked
{
private:
	ListNodeptr head;
public:
	MyDoubleLinked();//����Ҫ��һ����ʼ��������head����ռ伴headͷ���Ŀռ�һ��Ҫ�ȷ���
	//��Ȼ�еĺ����޷�ʹ��. next
	Status Create_head(ElemType n);//ͷ����
	Status Create_tail(ElemType n);//β����
	//Status retrieve(ElemType pos, ElemType *num);//���ص�pos��Ԫ��
	//Status locate(ElemType *pos, ElemType num);
	//void insert();
	void Print();
	//bool isempty();
	//void length(ElemType *l);
	//void remove(ElemType pos);//�����±�
	~MyDoubleLinked();
};
MyDoubleLinked::MyDoubleLinked()
{
	head = new ListNode;
	head->next = head;//��ʼ��ʱ��Ҫָ���Լ�
	head->prior = head;
}
MyDoubleLinked::~MyDoubleLinked()
{
	ListNodeptr p = head->next, q;
	while (p!=head)
	{
		q = p->next;//��ɾ��p֮ǰҪ�Ȱ�p����һ��������
		delete p;
		p = q;
	}
	delete head;//�����ܰ�headɾ��
}
Status MyDoubleLinked::Create_head(ElemType n)//ͷ����
{
	Status status = fail;
	ListNodeptr p;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			p = new ListNode;
			cout << "�������" << i + 1 << "���ڵ�:";
			cin >> p->data;
			p->next = head->next;
			p->prior = head;
			head->next = p;
			p->next->prior = p;
		}
		status = success;
	}
	return status;
}
Status MyDoubleLinked::Create_tail(ElemType n)//β����
{
	Status status = fail;
	ListNodeptr p, tail; tail = head;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			p = new ListNode;
			cout << "�������" << i + 1 << "���ڵ�:";
			cin >> p->data;
			p->next = head;
			p->prior = tail;
			tail->next = p;
			head->prior = p;//ͷ����priorҲҪ�ı�
			tail = p;
		}
		status = success;
	}
	return status;
}
void MyDoubleLinked::Print()
{
	ListNodeptr p = head->next;
	while (p != head)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
#endif