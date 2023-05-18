#include<stdio.h>
int main()
{
	int n,temp;
	printf("Enter number of elements:\n");
	scanf("%d",&n);
	int arr[n],i,j;
	printf("Enter %d elements:\n",n);
	for (i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("Array after bubble sorting :");
   for (j=0; j<n; j++)
   {
	    for (i=0; i<n-1 ; i++)
        {
    	    if (arr[i]>arr[i+1])
    	    {
    		    temp=arr[i];
    		    arr[i]=arr[i+1];
    		    arr[i+1]=temp;
		    }
	    }
    }
    	for (i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
}
