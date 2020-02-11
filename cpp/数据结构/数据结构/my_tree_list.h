#pragma once
#ifndef my_tree_vector
#define my_tree_vector
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
}node,*nodeptr;//三叉树
int len;//序列长度
class my_tree
{
private:
	nodeptr root;
public:
	my_tree();
	~my_tree();
	nodeptr get_root();
	void build_level();
	void build_pre_in_input();
	void build_pre_in(nodeptr *T, int a, int b, int c, int d, int *order_pre, int *order_in);
	void preorder(nodeptr T);
	void inorder(nodeptr T);
	void postorder(nodeptr T);
	void insert(nodeptr T);//普通二叉树不研究插入 删除？
	void destroy(nodeptr T);
	int leaf_count(nodeptr T);//统计叶子个数
	int depth(nodeptr T);
};
//
my_tree::my_tree()
{
	root = NULL;
}
my_tree::~my_tree()
{
	destroy(root);
}
int my_tree::depth(nodeptr T)
{
	if (!T)return 0;
	return 1 + max(depth(T->lt), depth(T->rt));
}
nodeptr my_tree::get_root()
{
	return root;
}
void my_tree::preorder(nodeptr T)
{
	if (T)
	{
		cout << T->num<<' ';
		preorder(T->lt);
		preorder(T->rt);
	}
}
void my_tree::inorder(nodeptr T)
{
	if (T)
	{
		inorder(T->lt);
		cout << T->num << ' ';
		inorder(T->rt);
	}
}
void my_tree::postorder(nodeptr T)
{
	if (T)
	{
		postorder(T->lt);
		postorder(T->rt);
		cout << T->num << ' ';
	}
}
void my_tree::destroy(nodeptr T)
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

}//用return 1  就不需要再设一个叠加的变量
int my_tree::leaf_count(nodeptr T)
{
	if(T==NULL) return 0;
	if (!T->lt && !T->rt) return 1;
	else return leaf_count(T->lt) + leaf_count(T->rt);
}
//要用队列
void my_tree::build_level()
{
	char datas[100];
	cin >> datas;
	len = strlen(datas);
	node *nodes = new node[len];
	for (int i = 0; i < len; i++)
	{
		nodes[i].num = datas[i]-'0';
		nodes[i].lt = NULL;
		nodes[i].rt = NULL;
		nodes[i].parent = NULL;
	}
	queue<nodeptr> q;
	if (len <= 0) return;
	q.push(&nodes[0]);
	root = &nodes[0];
	nodeptr temp;
	int i = 1;
	while (i<len)
	{
		
		temp = q.front();
		if (nodes[i].num != 0)
		{
			temp->lt = &nodes[i]; q.push(&nodes[i]);
		}
		else
		{
			temp->lt = NULL;
		}
		i++;
		if (nodes[i].num != 0)
		{
			temp->rt = &nodes[i]; q.push(&nodes[i]);
		}
		else
		{
			temp->rt = NULL;
		}
		i++;
		q.pop();
	}
}
int find(int num, int *in_order)
{
	for (int i = 0; i < len; i++)
	{
		if (in_order[i] == num)
		{
			return i;
		}
	}
}
void my_tree::build_pre_in(nodeptr *T,int a,int b,int c,int d,int *order_pre, int *order_in)
{
	int pos = find(order_pre[a],order_in);
	*T = new node;
	(*T)->num = order_pre[a];
	(*T)->lt = NULL;
	(*T)->rt = NULL;
	if (pos > c)
		build_pre_in(&((*T)->lt), a + 1, a + pos - c, c, pos - 1, order_pre, order_in);
	if (pos < d)
		build_pre_in(&((*T)->rt), a + pos - c + 1, b, pos + 1, d, order_pre,order_in);

}
void my_tree::build_pre_in_input()
{
	destroy(root);
	int *order_pre = new int[20];
	int *order_in = new int[20];
	char *order_pre_char = new char[20];
	char *order_in_char = new char[20];
	cin >> order_pre_char >> order_in_char;
	len = strlen(order_pre_char);
	for (int i = 0; i < len; i++)
	{
		order_pre[i] = order_pre_char[i] - '0';
		order_in[i] = order_in_char[i] - '0';
	}
	build_pre_in(&root,0,len-1,0,len-1, order_pre, order_in);
}
void my_tree::insert(nodeptr T)
{

}
#endif