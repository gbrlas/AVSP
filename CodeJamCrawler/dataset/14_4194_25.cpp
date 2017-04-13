#include<stdio.h>
int main()
{
	double t1,t2,x,c,f,rate=2,t=0,p;
	int n,ctr=0;
	scanf("%d",&n);
	while(ctr<n)
	{
		ctr++;
		scanf("%lf",&c);
		scanf("%lf",&f);
		scanf("%lf",&x);
		p=0;	
		t=0;
		rate=2;
		if(x<=c)
		{
			printf("Case #%d: %lf\n",ctr,x/rate);
		}
		else
		{
			while(p<x)
			{
				t+=c/rate;
				p+=c;
				t1=(x-p)/rate;
				t2=(x)/(rate+f);
				if(t1<t2)
				{
					t+=t1;
					printf("Case #%d: %lf\n",ctr,t);
					break;
				}
				else
				{
					rate+=f;
					p-=c;
				}
			}
		}
	}		
}
