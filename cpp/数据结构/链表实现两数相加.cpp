//#include "LinkedList.h"
//#include <iostream>
//using namespace std;
//int main()
//{
//	MyLinkedList a,b;
//	ListNodeptr l1 = NULL, l2=NULL;
//	a.Create_head(2,&l1);
//	b.Create_head(2, &l2);
//
//	ListNodeptr p1=l1->next, p2=l2->next,p3,p4;//p3�����ݴ�ָ�룬�ͷſռ�ʱʹ��
//	int sum = 0; int add = 0;
//	while (p1&&p2)
//	{
//		sum = p1->data + p2->data+add;add = sum / 10;//���һ��Ҫд������
//		if (sum > 9)
//		{
//			sum %= 10;
//		}
//		p1->data = sum;
//		p3 = p2->next;
//		delete p2;
//		p2 = p3;
//		p4 = p1;//�Ȱѷǿյ�p1������
//		p1 = p1->next;
//	}
//	if (!p1 && !p2&&add)
//	{
//		ListNodeptr x = new ListNode;
//		x->data = add;
//		x->next = NULL;//�·���Ľڵ�Ҫ��NULL ��Ȼ����ᱨ��
//		p4->next = x;
//	}
//	else
//	{
//		if (p1)
//		{
//			while (p1)
//			{
//				sum = p1->data + add;
//				if (sum > 9)
//				{
//					add = sum / 10;
//					sum %= 10;
//				}
//				p1->data = sum;
//				p4 = p1;
//				p1 = p1->next;
//			}
//			if (add)
//			{
//
//				ListNodeptr x = new ListNode;
//				x->next = NULL;//�·���Ľڵ�Ҫ��NULL ��Ȼ����ᱨ��
//				x->data = add;
//				p4->next = x;
//
//			}
//		}
//		if (p2)
//		{
//			p4->next = p2;
//			while (p2)
//			{
//				sum = p2->data + add;
//				if (sum > 9)
//				{
//					add = sum / 10;
//					sum %= 10;
//				}
//				p2->data = sum;
//				p4 = p2;
//				p2 = p2->next;
//			}
//			if (add)
//			{
//
//				ListNodeptr x = new ListNode;
//				x->next = NULL;//�·���Ľڵ�Ҫ��NULL ��Ȼ����ᱨ��
//				x->data = add;
//				p4->next = x;
//
//			}
//		}
//		
//	}
//	a.Print();
//}