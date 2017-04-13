#include <iostream>
long long i,min,sum,n,t,xsum;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lld",&t);
	for (int ct=1;ct<=t;++ct)
	{
		xsum=sum=0;min=10000000;
		for (scanf("%lld",&n);n;--n)
		{
			scanf("%lld",&i);
			xsum^=i;
			sum+=i;
			if (i<min) min=i;
		}
		printf("Case #%d: ",ct);
		if (xsum==0) printf("%lld\n",sum-min);
		else printf("NO\n");
	}
}