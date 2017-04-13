#include <stdio.h>
int a[1005],i,j,k,n,m,t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int ct=1;ct<=t;++ct)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",a+i);
		m=0;
		for (i=1;i<=n;i++)
			if (a[i]!=i)
			{
				j=a[i];
				while (j!=i)
				{
					++m;
					k=a[j];
					a[j]=j;
					j=k;
				}
				++m;
				a[i]=i;
			}
		printf("Case #%d: %d.000000\n",ct,m);
	}
}