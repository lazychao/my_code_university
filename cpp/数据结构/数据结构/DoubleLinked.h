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
	//不需要分号
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
	MyDoubleLinked();//必须要有一个初始化函数把head分配空间即head头结点的空间一定要先分配
	//不然有的函数无法使用. next
	Status Create_head(ElemType n);//头插入
	Status Create_tail(ElemType n);//尾插入
	//Status retrieve(ElemType pos, ElemType *num);//返回第pos个元素
	//Status locate(ElemType *pos, ElemType num);
	//void insert();
	void Print();
	//bool isempty();
	//void length(ElemType *l);
	//void remove(ElemType pos);//不是下标
	~MyDoubleLinked();
};
MyDoubleLinked::MyDoubleLinked()
{
	head = new ListNode;
	head->next = head;//初始化时就要指向自己
	head->prior = head;
}
MyDoubleLinked::~MyDoubleLinked()
{
	ListNodeptr p = head->next, q;
	while (p!=head)
	{
		q = p->next;//在删除p之前要先把p的下一级存起来
		delete p;
		p = q;
	}
	delete head;//最后才能把head删除
}
Status MyDoubleLinked::Create_head(ElemType n)//头插入
{
	Status status = fail;
	ListNodeptr p;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			p = new ListNode;
			cout << "请输入第" << i + 1 << "个节点:";
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
Status MyDoubleLinked::Create_tail(ElemType n)//尾插入
{
	Status status = fail;
	ListNodeptr p, tail; tail = head;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			p = new ListNode;
			cout << "请输入第" << i + 1 << "个节点:";
			cin >> p->data;
			p->next = head;
			p->prior = tail;
			tail->next = p;
			head->prior = p;//头结点的prior也要改变
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