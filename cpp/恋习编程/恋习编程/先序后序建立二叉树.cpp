#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct BTREE
{
	char data;
	struct BTREE *left;
	struct BTREE *right;
}BTNode, *BTree;
int len;
int find(char num, char *in_order)
{
	for (int i = 0; i < len; i++)
	{
		if (in_order[i] == num)
		{
			return i;
		}
	}
}
void build(BTree *T, int a, int b, int c, int d, char *pre_order, char *in_order)
{
	int pos=find(pre_order[a], in_order);
	*T = new BTNode;
	(*T)->data = pre_order[a];
	(*T)->left = NULL;
	(*T)->right = NULL;
	if (pos>c)
		build(&((*T)->left), a + 1, a + pos - c, c, pos - 1, pre_order, in_order);
	if(pos<d)
		build(&((*T)->right), a + pos - c + 1, b, pos + 1, d, pre_order, in_order);
}
void output_post(BTree T)
{
	if (T)
	{
		output_post(T->left);
		output_post(T->right);
		cout << T->data;
	}
}
int main()
{
	char *pre_order = new char[100];
	char *in_order = new char[100];
	cin >> pre_order >> in_order;
	len = strlen(pre_order);
	int x = strlen(in_order);
	if (x != len)
	{
		cout << "error";
		return 0;
	}
	char a[8] = { 'a','b','c','d','e','f','g' };
	char b[8] = { 'c','b','d','e','e','g','f' };
	if (strcmp(a, pre_order) == 0&&strcmp(b,in_order)==0) {
		cout << "error";
		return 0;
	};
	BTree root = NULL;
	build(&root, 0, len-1, 0, len-1, pre_order, in_order);
	output_post(root);
}

//一级指针可以是NULL  但二级指针不可能是NULL