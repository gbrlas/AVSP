#include <iostream>
int i,min,sum,n,t,xsum;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int ct=1;ct<=t;++ct)
	{
		xsum=sum=0;min=10000000;
		for (scanf("%d",&n);n;--n)
		{
			scanf("%d",&i);
			xsum^=i;
			sum+=i;
			if (i<min) min=i;
		}
		printf("Case #%d: ",ct);
		if (xsum==0) printf("%d\n",sum-min);
		else printf("NO\n");
	}
}