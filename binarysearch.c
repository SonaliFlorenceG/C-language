#include<stdio.h>
int binary_search(int *arr,int n,int i, int se)
{
	int l=i,h=n-1;
	int m=(l+h)/2;
	if (arr[m]==se) return m;
	return -1;
	if (arr[m]<se) return binary_search(arr,n,m+1,se);
	if (arr[m]>se) return binary_search(arr,m,m,se);
}
int main()
{
	int n,se;
	printf("Enter number of elements in an array:\n");
	scanf("%d",&n);
	int arr[n],i;
	printf("Enter %d elements :\n",n);
	for (i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter element to search :\n");
	scanf("%d",&se);
	int res = binary_search(arr,n,0,se);
	if (res==-1) printf ("Element not found\n");
	else printf ("Element found at index : %d\n",res);
}

