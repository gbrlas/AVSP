#include<stdio.h>
#include<map>
using namespace std;
int g[1000],a[1000],b[1000];
long long c[1001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		int r,k,n;
		scanf("%d%d%d",&r,&k,&n);
		long long total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",g+i);
			total+=g[i];
		}
		if(total<=k)
		{
			printf("Case #%d: %I64d\n",tt,total*r);
			continue;
		}
		for(int i=0;i<n;i++)
		{
			int j=i,l=k;
			while(l>=g[j])
			{
				l-=g[j];
				j=(j+1)%n;
			}
			a[i]=j;
			b[i]=k-l;
		}
		map<int,int > z;
		z[0]=0;
		c[0]=0;
		int dq=0,round=0;
		bool pd=true;
		while(r--)
		{
			++round;
			c[round]=c[round-1]+b[dq];
			dq=a[dq];
			if(z.find(dq)!=z.end())
			{
				pd=false;
				printf("Case #%d: %I64d\n",tt,c[round]+r/(round-z[dq])*(c[round]-c[z[dq]])+(c[z[dq]+r%(round-z[dq])]-c[z[dq]]));
				break;
			}
			else
			{
				z[dq]=round;
			}
		}
		if(pd)
		{
			printf("Case #%d: %I64d\n",tt,c[round]);
		}
	}
}
