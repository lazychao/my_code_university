//#include<cstdio>
//#include <iostream>
//#include "LinkedList.h"
//using namespace std;
//int main()
//{
//	MyLinkedList a;
//	ListNodeptr head = a.Create_tail(5);
//	//���ҵ��ڶ����ڵ�
//	ListNodeptr p1 = head->next->next,pre=head->next;//pre�����ƶ���
//	//һֱָ�ڵ�һ���ڵ�
//
//	while (p1)
//	{
//		pre->next = p1->next;//�Ȱ�p1ȡ���������һ�Ҫ��������
//		p1->next = head->next;
//		head->next = p1;
//		p1 = pre->next;//����p1��next
//	}
//	a.Print();
//	//��ͷ�巨
//	
//}