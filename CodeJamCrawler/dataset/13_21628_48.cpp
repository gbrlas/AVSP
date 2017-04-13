#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	int v,p;
};

bool operator < (dat a, dat b)
{
	return a.v<b.v;
};

dat a[1001];
dat b[1001];
long long mod=1000002013;

int main()
{
	int t,p;
	long long n;
	int m;
	int i,j,k;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lld",&n);
		scanf("%d",&m);
		long long tot=0;
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i].v,&b[i].v);
			scanf("%d",&a[i].p);
			b[i].p=a[i].p;
			tot=(tot+((b[i].v-a[i].v)*n-(b[i].v-a[i].v)*(long long)(b[i].v-a[i].v-1)/2)%mod*a[i].p)%mod;
		}
		sort (a+1,a+m+1);
		sort (b+1,b+m+1);
		k=0;
		for (i=1;i<=m;i++)
		{
			while (k<m&&a[k+1].v<=b[i].v) k++;
			j=k;
			while (j>=1)
			{
				if (b[i].p>=a[j].p)
				{
					tot=(tot-(((b[i].v-a[j].v)*n-(b[i].v-a[j].v)*(long long)(b[i].v-a[j].v-1)/2)%mod*a[j].p)%mod)%mod;
					if (tot<0) tot=tot+mod;
					b[i].p=b[i].p-a[j].p;
					a[j].p=0;
					j--;
				}
				else
				{
					tot=(tot-(((b[i].v-a[j].v)*n-(b[i].v-a[j].v)*(long long)(b[i].v-a[j].v-1)/2)%mod*b[i].p)%mod)%mod;
					if (tot<0) tot=tot+mod;
					a[j].p=a[j].p-b[i].p;
					b[i].p=0;
					break;
				}
			}
		}
		printf("Case #%d: %lld\n",p,tot);
	}
	return 0;
}




