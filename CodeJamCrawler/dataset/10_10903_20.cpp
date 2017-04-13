#include<iostream.h>
#include<stdio.h>
#include<math.h>
void main()
{

int t=0, n=0, k=0;

scanf("%d",&t);

for(int i=0; i<t; i++)
{
	scanf("%d %d", &n,&k);

	if(k==0)
		printf("Case #%d: OFF\n",(i+1));

	else
	{
		int l = pow(2,n)-1;
		int m=0;
		while(m<k)
		{
		    m+=l;
		    if(m==k)
		    {	printf("Case #%d: ON\n",(i+1));
			break;
		    }
		    m+=1;
		}
		if(m!=k)
		printf("Case #%d: OFF\n",(i+1));
	}
}
}