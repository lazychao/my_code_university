#pragma once
#ifndef my_BST1
#define my_BST1
#include <cstdio>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef int ElemType;
typedef struct node
{
	ElemType num;
	struct node *parent, *lt, *rt;
}node, *nodeptr;//������
int len;//���г���
//�������������ɫ˵�����ѱ�����Ĺؼ���
class my_BST
{
private:
    nodeptr root;
public:
	my_BST();
	~my_BST();
	nodeptr get_root();
	void build();
	/*void build_pre_in_input();
	void build_pre_in(nodeptr *T, int a, int b, int c, int d, int *order_pre, int *order_in);*/
	void preorder(nodeptr T);
	void inorder(nodeptr T);
	void postorder(nodeptr T);
	void insert(int num,nodeptr *T);//��ͨ���������о����� ɾ����
	void destroy(nodeptr T);
	nodeptr remove(nodeptr T,int num);
	//int leaf_count(nodeptr T);//ͳ��Ҷ�Ӹ���
	int depth(nodeptr T);
};
//
my_BST::my_BST()
{
	root = NULL;
}
my_BST::~my_BST()
{
	destroy(root);
}
int my_BST::depth(nodeptr T)
{
	if (!T)return 0;
	return 1 + max(depth(T->lt), depth(T->rt));
}
nodeptr my_BST::get_root()
{
	return root;
}
void my_BST::build()
{
	int len;
	cout << "���������г���:";
	cin >> len;
	int *nums = new int[len];
	for (int i = 0; i < len; i++)
	{
		cin >> nums[i];
		insert(nums[i],&root);
		
	}
	
	

}
//�ݹ�ɾ��
//�ݹ�ɾ�����Ǵ����  ֻ���Ȳ��ҵ� ��Ӧ�ڵ���丸�ڵ���ɾ��
//�����˼�Ҫ�ݹ��ָ����Ҫ���ҵ���ָ�뷵��
nodeptr find_and_remove_left_max(nodeptr T)
{
	//���Ҳ���
	if (T->rt) T->rt= find_and_remove_left_max(T->rt);
	else
	{
		nodeptr temp = T;
		delete T;
		return temp;
	}
		
}
//ע��Ҷ�ڵ�ɾ����Ҫ ���丸�ڵ�Ķ���ָ����Ϊ�ղ�Ȼ�ᱨ��
nodeptr my_BST::remove(nodeptr T, int num)
{
	if (!T) return NULL;
	if (num == T->num)
	{
		if (T->lt&&T->rt) {
			nodeptr temp=find_and_remove_left_max(T);
			T->num = temp->num;
			return T;
		}
		else if (T -> lt) {
			nodeptr temp = T;
			delete T;
			return temp-> lt;
		}
		else if (T->rt) {
			nodeptr temp = T;
			delete T;
			return temp->rt;
		}
		else
		{
			delete T;
			T = NULL;
			return T;
		}
	}
	else if (num > T->num)
	{
		T->rt = remove(T->rt,num);
		return T;//ΪʲôҪ�غú�����
	}
	else {
		T->lt = remove(T->lt, num); 
		return T;
	}
}
void my_BST::insert(int num,nodeptr *T)
{
	if (!(*T))//����̫��Ҫ��   ����ָ�벻����Ϊ��
	{
		(*T) = new node;
		(*T)->num = num;
		(*T)->lt = NULL;
		(*T)->rt = NULL;
	}
	else
	{
		if (num >= (*T)->num)
			insert(num, &((*T)->rt));
		if (num < (*T)->num)
			insert(num, &((*T)->lt));//��ͬ����ʦ�ķ���������Ҫreturn����Ϊʲô��
	}
}
void my_BST::preorder(nodeptr T)
{
	if (T)
	{
		cout << T->num << ' ';
		preorder(T->lt);
		preorder(T->rt);
	}
}
void my_BST::inorder(nodeptr T)
{
	if (T)
	{
		inorder(T->lt);
		cout << T->num << ' ';
		inorder(T->rt);
	}
}
void my_BST::postorder(nodeptr T)
{
	if (T)
	{
		postorder(T->lt);
		postorder(T->rt);
		cout << T->num << ' ';
	}
}
void my_BST::destroy(nodeptr T)
{

	if (T)
	{
		nodeptr lt = T->lt;
		nodeptr rt = T->rt;
		delete T;
		T = NULL;
		destroy(lt);
		destroy(rt);
	}
}
#endif
