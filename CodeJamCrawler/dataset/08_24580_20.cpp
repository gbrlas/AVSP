#include <stdio.h>
#include <memory.h>
int m;
int a[20000][2];
int c[20000];
bool b[20000];

int main()
{
	freopen ("A-large.in","r",stdin);
	freopen ("A-large.out","w",stdout);

	int n,N;
	int v;
	int G,C;
	int t1,t2;

	scanf("%d",&N);
	
	for (n=1;n<=N;n++)
	{
		scanf("%d",&m);
		scanf("%d",&v);
		memset(a,-1,sizeof(a));
		memset(c,false,sizeof(c));
		int i;
		for (i=1;i<=(m-1)/2;i++)
		{
			scanf("%d %d",&G,&C);
			b[i]=C;
			c[i]=G;
		}
		for (;i<=m;i++)
		{
			scanf("%d",&G);
			a[i][G]=0;
		}
		for (i=m;i>=1;i--)
		{
			if (i*2+1<=m)
			{
				for (t1=0;t1<=1;t1++) for (t2=0;t2<=1;t2++)
				{
					if (a[i*2][t1]!=-1 && a[i*2+1][t2]!=-1)
					{
						if (c[i])
						{
							if (a[i][t1&t2]==-1 || a[i][t1&t2]>a[i*2][t1]+a[i*2+1][t2])
							{
								a[i][t1&t2]=a[i*2][t1]+a[i*2+1][t2];
							}
						}else
						{
							if (a[i][t1|t2]==-1 || a[i][t1|t2]>a[i*2][t1]+a[i*2+1][t2])
							{
								a[i][t1|t2]=a[i*2][t1]+a[i*2+1][t2];
							}
						}
						if (b[i])
						{
							if (c[i])
							{
								if (a[i][t1|t2]==-1 || a[i][t1|t2]>a[i*2][t1]+a[i*2+1][t2]+1)
								{
									a[i][t1|t2]=a[i*2][t1]+a[i*2+1][t2]+1;
								}
							}else
							{
								if (a[i][t1&t2]==-1 || a[i][t1&t2]>a[i*2][t1]+a[i*2+1][t2]+1)
								{
									a[i][t1&t2]=a[i*2][t1]+a[i*2+1][t2]+1;
								}
							}
						}
					}
				}
			}
		}
		printf("Case #%d: ",n);
		if (a[1][v]==-1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",a[1][v]);

	}

	return 0;
}