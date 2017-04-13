#include<stdio.h>

int main()
{
	freopen("B-large.in","r",stdin);
    freopen("outp.in","w",stdout);
	int t,num;
	scanf("%d",&t);
	num=t;
	while(t--)
	{
		double c,f,x,rate,ans=0.0;
		scanf("%lf%lf%lf",&c,&f,&x);
		rate=2.0;
		while((x/rate)>((c/rate)+(x/(rate+f))))
		{
			ans+=(c/rate);
			rate+=f;
		}
		ans+=(x/rate);
		printf("Case #%d: %.7lf\n",num-t,ans);
	}
	
return 0;
}
