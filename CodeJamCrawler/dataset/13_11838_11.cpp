#include<stdio.h>

int main()
{
	long long int t,i,r,p,out,ans,d1,d2;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		out = ans = 0;
		scanf("%lld%lld",&r,&p);
		d1=r;
		d2=r+1;
		for(;out<=p;)
		{
			ans++;
			out += d2*d2-d1*d1;
			d1 = d2 + 1;
			d2 = d1 + 1;			
		}
		printf("Case #%lld: %lld\n",i+1,ans-1);
	}
	return 0;
}
