#include<stdio.h>
#include<stdlib.h>
struct t_node
{
	int data;
	struct t_node *left;
	struct t_node *right;
};
typedef struct t_node TreeNode;

void in_order(TreeNode *root)
{
	if(root != NULL)
	{
		in_order(root->left);
		printf("%d ",root->data);
		in_order(root->right);
	}
}

TreeNode* create_tree_node(int val)
{
	TreeNode *nn = (TreeNode*)malloc(sizeof(TreeNode));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}

TreeNode *constructBT(int *arr,int n)
{
	TreeNode *q[100];
	int front=0,rear=0;
	q[rear++]=create_tree_node(arr[0]);
	int i=0;
	while(1)
	{
		if (2*i+1>=n)
		{
			break;
		}
		if (2*i+1<n)
		{
			// creating a node with the value at 2*i+1 index
			TreeNode *t= create_tree_node(arr[2*i+1]);
			q[rear++]=t; // adding it to the queue
			q[front]->left=t; //connecting left child
		}
		if (2*i+2<n)
		{
			// creating a node with the value at 2*i+2 index
			TreeNode *t= create_tree_node(arr[2*i+2]);
			q[rear++]=t; // adding it to the queue
			q[front]->right=t; //connecting right child
		}
		front++;
		i++;
	}
	return q[0];
}

int main()
{
	int n,i;
	printf ("Enter the size of the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements for the array : ",n);
	for (i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	TreeNode *root = constructBT(arr,n);
	//checking the tree
	in_order(root);
}
