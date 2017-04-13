#include<stdio.h>

int main()
{
	int t,p;
	double c,f,x;
	double cur;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double tot=0;
		cur=2.0;
		while (1)
		{
			double tt=c/cur;
			if (x/cur<tt+x/(cur+f)) break;
 			tot=tot+tt;
			cur=cur+f;
		}
		printf("Case #%d: %.7lf\n",p,tot+x/cur);
	}
	return 0;
}
