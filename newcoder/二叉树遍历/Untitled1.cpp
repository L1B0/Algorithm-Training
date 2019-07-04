#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BinaryTreeNode{
	char value;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BTNode;
int ind;
char s[101];

BTNode* BuildMyTree()
{
	BTNode *bt=NULL;
	if( ind < strlen(s) && s[ind] != '#' )
	{
		bt = (BTNode*)malloc(sizeof(BTNode));
		bt->value = s[ind];
		ind++;
		bt->left = BuildMyTree();
		bt->right = BuildMyTree(); 
	}
	else ind++;
	return bt;
}

void InOrderTraversal(BTNode *head)
{
	if( head == NULL ) return;
	
	InOrderTraversal(head->left);
	printf("%c ",head->value);
	InOrderTraversal(head->right); 
}

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		ind=0;
		BTNode *head = BuildMyTree();
		InOrderTraversal(head);
		printf("\n"); 
	}
	return 0;	
} 
