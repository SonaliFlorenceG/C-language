main()
{ 
	int n,t,rem,sum=0;
	scanf("%d",&n);
	t=n;
	while(n!=0)
	{
		rem=n%10;
		sum=sum+rem*rem*rem;
		n=n/10;
	}
	if(sum==t)
	{
		printf("Amstrong number");
	}
	else
	{
		printf("Not Amstrong number");
	}
}

