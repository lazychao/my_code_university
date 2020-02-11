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
}node, *nodeptr;//三叉树
int len;//序列长度
//变量名变成了紫色说明是已被定义的关键字
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
	void insert(int num,nodeptr *T);//普通二叉树不研究插入 删除？
	void destroy(nodeptr T);
	nodeptr remove(nodeptr T,int num);
	//int leaf_count(nodeptr T);//统计叶子个数
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
	cout << "请输入序列长度:";
	cin >> len;
	int *nums = new int[len];
	for (int i = 0; i < len; i++)
	{
		cin >> nums[i];
		insert(nums[i],&root);
		
	}
	
	

}
//递归删除
//递归删除法是错误的  只能先查找到 对应节点和其父节点再删除
//出现了既要递归回指针又要将找到的指针返回
nodeptr find_and_remove_left_max(nodeptr T)
{
	//向右查找
	if (T->rt) T->rt= find_and_remove_left_max(T->rt);
	else
	{
		nodeptr temp = T;
		delete T;
		return temp;
	}
		
}
//注意叶节点删除还要 将其父节点的儿子指针置为空不然会报错
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
		return T;//为什么要呢好好想想
	}
	else {
		T->lt = remove(T->lt, num); 
		return T;
	}
}
void my_BST::insert(int num,nodeptr *T)
{
	if (!(*T))//这里太重要了   二级指针不可能为空
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
			insert(num, &((*T)->lt));//不同于老师的方法，不需要return这是为什么呢
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
