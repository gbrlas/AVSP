#include<stdio.h>
#include<string.h>

int d[60010];
int l[60010];
int f[60010];

int main()
{
	int t,p;
	int n;
	int i,j,k;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&d[i],&l[i]);
		scanf("%d",&d[n+1]);
		for (i=1;i<=n+1;i++)
			f[i]=d[i];
		f[1]=0;
		for (i=1;i<=n;i++)
		{
			k=d[i]-f[i];
			if (k>l[i]) k=l[i];
			for (j=i+1;j<=n+1&&d[j]<=d[i]+k;j++)
				if (f[j]>d[i]) f[j]=d[i];
		}
		if (f[n+1]<d[n+1]) printf("Case #%d: YES\n",p);
		else printf("Case #%d: NO\n",p);
	}
	return 0;
}
