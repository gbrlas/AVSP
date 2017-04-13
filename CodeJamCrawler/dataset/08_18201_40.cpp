#include<stdio.h>
#include<string.h>
bool p[100][10][2];
int cb(int x)
{
	int r=0;
	while(x)r++,x&=(x-1);
	return r;
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int c;
	scanf("%d",&c);
	for(int t=1;t<=c;t++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(p,0,sizeof(p));
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			while(x--)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				p[i][u-1][v]=true;
			}
		}
		int min=-1;
		for(int i=0;i<1<<n;i++)
		{
			int j=0;
			for(;j<m;j++)
			{
				int k=0;
				for(;k<n;k++)if(p[j][k][(i&(1<<k))?1:0])break;
				if(k==n)break;
			}
			if(j==m)
			{
				if(cb(min)>cb(i))min=i;
			}
		}
		printf("Case #%d:",t);
		if(min<0)puts(" IMPOSSIBLE");
		else
		{
			for(int i=0;i<n;i++)printf(" %d",(min&(1<<i))?1:0);
			putchar('\n');
		}
	}
}
