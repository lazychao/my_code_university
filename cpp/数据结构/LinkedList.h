#ifndef LinkedList
#define LinkedList
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
	struct node *next;
}ListNode, *ListNodeptr;
class MyLinkedList
{
private:
	ListNodeptr head;//头指针不应该设置为空
public:
	MyLinkedList();//必须要有一个初始化函数把head分配空间即head头结点的空间一定要先分配
	//不然有的函数无法使用. next
	ListNodeptr Create_head(ElemType n);
	ListNodeptr Create_tail(ElemType n);
	ElemType retrieve(ElemType pos);//返回第pos个元素
	ElemType locate( ElemType num);
	void insert();
	void Print();
	bool isempty();
	ElemType length();
	void remove(ElemType pos);//不是下标
	~MyLinkedList();
};

MyLinkedList::MyLinkedList()
{
	head = new ListNode;
	head->next = NULL;
}
ListNodeptr  MyLinkedList::Create_head(ElemType n)//头插入法
{
	Status status = fail;
	if (n > 0)
	{
		ListNodeptr p;
		for (int i = 0; i < n; i++)//再创建n个节点   因为头节点不存数据
		{
			cout << "请输入第" << i + 1 << "个节点:";
			p = new ListNode;
			cin >> p->data;
			p->next = head->next;
			head->next = p;
		}
		status = success;
	}
	return head;
}
ListNodeptr MyLinkedList::Create_tail(ElemType n)//尾插入法
{
	Status status = fail;
	if (n > 0)
	{
		ListNodeptr p,tail;//得设置一个尾指针跟踪到链表结尾，不然每插入一个就要循环到结尾
		//但这种方法可以实现正序存储数据

		tail = head;
		for (int i = 0; i < n; i++)
		{
			cout << "请输入第" << i + 1 << "个节点:";
			p = new ListNode;
			cin >> p->data;
			p->next = tail->next;
			tail->next = p;//p接到旧tail的后面
			tail = p;//p成为tail
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
		delete p;//释放空间，p指针还是可以使用的
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
	cout << "请输入要插入的数据:";
	cin >> q->data;
	q->next = p->next;
	p->next = q;
}
void MyLinkedList::remove(ElemType pos)
{
	ListNodeptr p=head->next;
	ElemType i = 1;
	while (p&&i<pos-1)//应该定位在pos-1的位置
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