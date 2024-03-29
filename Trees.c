#include<stdio.h>
#include<stdlib.h>
struct t_node{
	int data;
	struct t_node *left;
	struct t_node *right;
};
typedef struct t_node TreeNode;
// creating a function that creates a tree node and puts value in it .
TreeNode* create_tree_node(int val)
{
	TreeNode *nn = (TreeNode*)malloc(sizeof(TreeNode));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
void pre_order(TreeNode *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(TreeNode *root)
{
	if(root != NULL)
	{
		in_order(root->left);
		printf("%d ",root->data);
		in_order(root->right);
	}
}

void post_order(TreeNode *root)
{
	if(root != NULL)
	{
		post_order(root->left);
		post_order(root->right);
		printf("%d ",root->data);
	}
}

void level_order(TreeNode *root)
{
	TreeNode *q[100]; //queue of tree nodes
	int front,rear;
	front=0;
	rear=1;
	q[0]=root; //inserting root into queue
	while(front!=rear)
	{
		TreeNode *dn = q[front++]; //dequeue
		printf("%d ",dn->data); // printing deleted node
		//check if deleted node is having left child
		if (dn->left!=NULL)
		{
			q[rear++]=dn->left;
		}
		//check if deleted node is having right child
		if (dn->right!=NULL)
		{
			q[rear++]=dn->right;
		}
		dn=NULL;
		free(dn);
	}
}

int main()
{
	//creating tree nodes
	TreeNode *n1,*n2,*n3,*n4,*n5,*n6,*n7,*n8,*n9;
	n1 = create_tree_node(10);
	n2 = create_tree_node(20);
	n3 = create_tree_node(30);
	n4 = create_tree_node(40);
	n5 = create_tree_node(50);
	n6 = create_tree_node(60);
	n7 = create_tree_node(70);
	n8 = create_tree_node(80);
	n9 = create_tree_node(90);
	//making connections
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	n3->right=n7;
	n4->right=n8;
	n7->left=n9;
	//printing through 1st node
	printf("Node 1: %d\n",n1->data);
	printf("Node 2: %d\n",n1->left->data);
	printf("Node 3: %d\n",n1->right->data);
	printf("Node 4: %d\n",n1->left->left->data);
	printf("Node 5: %d\n",n1->left->right->data);
	printf("Node 6: %d\n",n1->right->left->data);
	printf("Node 7: %d\n",n1->right->right->data);
	printf("Node 8: %d\n",n1->left->left->right->data);
	printf("Node 9: %d\n\n",n1->right->right->left->data);
	//pre order traversal
	printf("Pre Order : ");
	pre_order(n1);
	printf("\n\n");
	//in order traversal
	printf("In Order : ");
	in_order(n1);
	printf("\n\n");
	//post order traversal
	printf("Post Order : ");
	post_order(n1);
	printf("\n\n");
	//level order traversal
	printf("Level Order : ");
	level_order(n1);
	
}
