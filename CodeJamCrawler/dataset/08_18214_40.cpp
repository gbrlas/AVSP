#include<stdio.h>
#include<string.h>
int a[10001][2],d[10001][2];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int N;
	scanf("%d",&N);
	for(int t=1;t<=N;t++)
	{
		int m,v;
		scanf("%d%d",&m,&v);
		memset(d,0x7f,sizeof(d));
		for(int i=1;i<=m/2;i++)scanf("%d%d",a[i],a[i]+1);
		for(int i=m/2+1;i<=m;i++)
		{
			int x;
			scanf("%d",&x);
			d[i][x]=0;
		}
		for(int i=m/2;i;i--)
		{
			if(d[i*2][0]<0x7f7f7f7f)
			{
				if(d[i*2+1][0]<0x7f7f7f7f)if(d[i][0]>d[i*2][0]+d[i*2+1][0])d[i][0]=d[i*2][0]+d[i*2+1][0];
				if(d[i*2+1][1]<0x7f7f7f7f)
				{
					int x;
					if(a[i][0])x=0;
					else x=1;
					if(d[i][x]>d[i*2][0]+d[i*2+1][1])d[i][x]=d[i*2][0]+d[i*2+1][1];
				}
			}
			if(d[i*2][1]<0x7f7f7f7f)
			{
				if(d[i*2+1][1]<0x7f7f7f7f)if(d[i][1]>d[i*2][1]+d[i*2+1][1])d[i][1]=d[i*2][1]+d[i*2+1][1];
				if(d[i*2+1][0]<0x7f7f7f7f)
				{
					int x;
					if(a[i][0])x=0;
					else x=1;
					if(d[i][x]>d[i*2][1]+d[i*2+1][0])d[i][x]=d[i*2][1]+d[i*2+1][0];
				}
			}
			if(a[i][1])
			{
				if(d[i*2][0]<0x7f7f7f7f)
				{
					if(d[i*2+1][1]<0x7f7f7f7f)
					{
						int x;
						if(a[i][0])x=1;
						else x=0;
						if(d[i][x]>d[i*2][0]+d[i*2+1][1]+1)d[i][x]=d[i*2][0]+d[i*2+1][1]+1;
					}
				}
				if(d[i*2][1]<0x7f7f7f7f)
				{
					if(d[i*2+1][0]<0x7f7f7f7f)
					{
						int x;
						if(a[i][0])x=1;
						else x=0;
						if(d[i][x]>d[i*2][1]+d[i*2+1][0]+1)d[i][x]=d[i*2][1]+d[i*2+1][0]+1;
					}
				}
			}
		}
		if(d[1][v]<0x7f7f7f7f)printf("Case #%d: %d\n",t,d[1][v]);
		else printf("Case #%d: IMPOSSIBLE\n",t);
	}
}
