#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTREE
{
	char data;
	struct BTREE *left;
	struct BTREE *right;
}BTNode, *BTree;

BTree Rebuilt(char *PreOrder, char *InOrder, int L)
{
	int i, LeftL, RightL;
	BTree pTree = new BTNode;
	if (L == 1)
	{
		pTree->data = *PreOrder;
		pTree->left = NULL;
		pTree->right = NULL;
	}
	else
	{
		i = 0;
		while (InOrder[i] != *PreOrder && i < L)
		{
			i++;
		}
		if (i >= L)
		{
			printf("error");
			exit(0);
		}
		LeftL = i;
		RightL = L - i + 1;
		pTree->data = *PreOrder;
		pTree->left = Rebuilt(&PreOrder[1], &InOrder[0], LeftL);
		pTree->right = Rebuilt(&PreOrder[i + 1], &InOrder[i + 1], RightL);
	}
	return pTree;
}

void PostOrder(BTNode *pTree)
{
	if (pTree->left != NULL)
	{
		PostOrder(pTree->left);
	}
	if (pTree->right != NULL)
	{
		PostOrder(pTree->right);
	}
	printf("%c", pTree->data);
}

int main()
{
	char PreOrder[50];
	char InOrder[50];
	int L;
	BTree pTree;
	gets_s(PreOrder);
	gets_s(InOrder);
	if (strlen(PreOrder) != strlen(InOrder))
	{
		printf("error");
		return -1;
	}
	L = strlen(PreOrder);
	pTree = Rebuilt(PreOrder, InOrder, L);
	PostOrder(pTree);
	return 0;
}