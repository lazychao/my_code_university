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
//	ListNodeptr p1=l1->next, p2=l2->next,p3,p4;//p3用于暂存指针，释放空间时使用
//	int sum = 0; int add = 0;
//	while (p1&&p2)
//	{
//		sum = p1->data + p2->data+add;add = sum / 10;//这个一点要写在外面
//		if (sum > 9)
//		{
//			sum %= 10;
//		}
//		p1->data = sum;
//		p3 = p2->next;
//		delete p2;
//		p2 = p3;
//		p4 = p1;//先把非空的p1存起来
//		p1 = p1->next;
//	}
//	if (!p1 && !p2&&add)
//	{
//		ListNodeptr x = new ListNode;
//		x->data = add;
//		x->next = NULL;//新分配的节点要给NULL 不然输出会报错
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
//				x->next = NULL;//新分配的节点要给NULL 不然输出会报错
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
//				x->next = NULL;//新分配的节点要给NULL 不然输出会报错
//				x->data = add;
//				p4->next = x;
//
//			}
//		}
//		
//	}
//	a.Print();
//}