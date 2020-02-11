//#include<cstdio>
//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//int main()
//{
//	MyLinkedList a;
//	ListNodeptr head = a.Create_tail(5);
//	//先找到第二个节点
//	ListNodeptr p1 = head->next->next,pre=head->next;//pre不会移动，
//	//一直指在第一个节点
//
//	while (p1)
//	{
//		pre->next = p1->next;//先把p1取出来，并且还要保持连续
//		p1->next = head->next;
//		head->next = p1;
//		p1 = pre->next;//不是p1的next
//	}
//	a.Print();
//	//用头插法
//	
//}