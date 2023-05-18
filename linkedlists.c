#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
typedef struct node NODE;
NODE *Head=NULL,*Tail=NULL;
void insert(NODE *nn)
{
	if(Head==NULL && Tail==NULL)
	{
		Head=nn;
		Tail=nn;
	}
	else
	{
		Tail->next=nn;
		Tail=nn;
	}
}
void display()
{
	NODE *temp;
	if(Head==NULL && Tail==NULL)
	{
		printf("no node\n");
	}
	else
	{
		temp=Head;
		while(temp)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("\n");
	}
}
NODE * delete()
{
	NODE *temp,*dn;
	if(Head==NULL && Tail==NULL)
	{
		return NULL;
	}
	if(Head==Tail)
	{
		dn=Head;
		Head=NULL;
		Tail=NULL;
		return dn;
	}
	temp=Head;
	while(temp->next->next)
	{
		temp=temp->next;
		temp->next=NULL;
		dn=Tail;
		Tail=temp;
		return dn;
	}
}
int count()
{
	NODE *temp;
	int c=0;
	if(Head==NULL && Tail==NULL)
	{
		return 0;
	}
	temp=Head;
	while(temp)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
void insert_head(NODE *nn)
{
	if(Head==NULL && Tail==NULL)
	{
		Head=nn;
		Tail=nn;
	}
	else{
		nn->next=Head;
		Head=nn;
	}
}
NODE *delete_head()
{  
    NODE *temp;
    if(Head==NULL&&Tail==NULL)
    {
	   return NULL;
   }
   else if (Head==Tail)
   {
	  temp==Head;
	  Head=NULL;
	  Tail=NULL;
	  return temp;
   }
   else
   {
	  temp=Head;
   	Head=Head->next=NULL;
	 return temp;
    }
}
int searching(int search)
{
	NODE *temp;
	int c=0;
	temp=Head;
	while(temp)
	{
		if(temp->data==search)
		{
			c++;
		}
		temp=temp->next;
	}
	return c;
}
void reverse_display(int cnt)
{
	int arr[cnt],i;
	NODE *temp;
	temp=Head;
	for(i=0;i<cnt;i++)
	{
	    arr[i]=temp->data;
		temp=temp->next;	
	}
	for(i=0;i<cnt;i--)
	{
	   printf("%d",arr[i]); 	
	}
	printf("\n");
	}
	
int main()
{
   NODE *nn,*res;
   int ch,val,search,cnt;
   while(1){
   	printf("1.insert 2.delete 3.display 4.count 5.insert at head 6.delete at head 7.search 8.reverse 9.exit:");
   	scanf("%d",&ch);
   	if (ch==1)
   	{
   	    scanf("%d",&val);
   	    nn=(NODE*)malloc(sizeof(NODE));
		nn->data=val;
		nn->next=NULL;
		insert(nn); 	
    }
    else if(ch==2)
    {
    	res=delete();
    	if(res==NULL)
    	{
    		printf("no nodes\n");
		}
		else
		{
			printf("%d\n",res->data);
			free(res);
		}
	}
	else if(ch==3)
	{
	    display();	
	}
	else if(ch==4)
	{
		printf("%d\n",count());
	}
	else if(ch==5)
	{
	   scanf("%d",&val);
   	    nn=(NODE*)malloc(sizeof(NODE));
		nn->data=val;
		nn->next=NULL;
		insert_head(nn); 	
	}
	else if(ch==6)
	{
		res=delete_head();
		if(res==NULL)
		{
			
			printf("no nodes\n");
		}
		else
		{
			printf("%d\n",res->data);
		}
	}
	else if(ch==7)
	{
		int search;
		scanf("%d",&search);
		searching(search);
	}
	else if(ch==8)
	{
		reverse_display(cnt);
	}
	else
	{
		break;
	}
   }	
}
