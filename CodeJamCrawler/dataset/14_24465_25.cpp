#include<stdio.h>

main()
{
	int t,m=1;
	scanf("%d",&t);
	while(m<=t)
	{
	long long int n,k,count=0,i,j,no;
	scanf("%lld",&n);
	long long int a[20][20],b[20][20];
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	scanf("%lld",&a[i][j]);
	   scanf("%lld",&k);
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	scanf("%lld",&b[i][j]);
	
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[n-1][i]==b[k-1][j])
			{
				count++;
				no=a[n-1][i];
			}
			
		}
		
		
		//if((a[n-1][i]==b[k-1][0])||(a[n-1][i]==b[k-1][1])||(a[n-1][i]==b[k-1][2])||(b[n-1][i]==b[k-1][3]))
		//count++;
	}
	
//	printf("%lld\n",count);
	if(count==0)
	printf("Case #%d: Volunteer cheated!\n",m);
	if(count>1)
	printf("Case #%d: Bad magician!\n",m);
  if(count==1)
	printf("Case #%d: %lld\n",m,no);	
	m++;
	
	}

}