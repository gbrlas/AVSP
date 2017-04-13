#include<stdio.h>
main()
{  
int t;
scanf("%d",&t);
int k=1;
while(k<=t)
	{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double n3,n1=0,n2=0,max,n4	;
	max=c/2;
	if(max==1)
	{   printf("Case #%d: %.7lf\n",k,max);
	k++;
      continue;
      
	}
	while(1)
	{
		n1=n1+a/(2+n2);
		n3=c/(2+n2+b);
		n2=n2+b;
		n4=n1+n3;
		if(max>=n4)
		max=n4;
		else
	 break;
		
	}
	printf("Case #%d: %.7lf\n",k,max);
	k++;
	}
}