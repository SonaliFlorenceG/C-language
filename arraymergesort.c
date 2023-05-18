#include<stdio.h>
void array_mergesort(int *a,int *b,int m, int n)
{
	int res[m+n],i=0,j=0,k=0;
	while (i<m && j<n)
	{
		if (a[i]<=b[j]) res[k++]=a[i++];
		else res[k++]=b[j++];
	}
	while (i<m) res[k++] = a[i++];
	while (j<n) res[k++] = b[j++];
	for (i=0; i<m+n; i++) printf("%d ",res[i]);
}
int main()
{
	int n,m,i;
	printf("Enter number of elements in 1st array: \n");
	scanf("%d",&m);
	int a[m];
	printf("Enter number of elements in 2nd array: \n");
	scanf("%d",&n);
	int b[n];
	printf("Enter %d elements for 1st array: \n",m);
	for (i=0; i<m; i++) scanf("%d",&a[i]);
	printf("Enter %d elements for 2nd array: \n",n);
	for (i=0; i<n; i++) scanf("%d",&b[i]);
	array_mergesort(a,b,m,n);
}
