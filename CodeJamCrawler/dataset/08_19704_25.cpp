#include<stdio.h>
#include<string.h>

int main()
{
	int t,p;
	int n,m;
	int i,j,k,w,a;
	bool flag;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&m,&a);
		flag=false;
		printf("Case #%d: ",p);
		for (i=0;i<=n;i++)
		{
			for (j=i;j<=n;j++)
			{
				for (k=0;k<=m;k++)
				{
					for (w=k;w<=m;w++)
					{
						int r;
						r=j*m-i*k;
						if (r==a)
						{
							flag=true;
							printf("0 0 %d %d %d %d\n",i,m,j,k);
						}
						if (flag) break;
						r=i*m-j*k;
						if (r<0) r=-r;
						if (r==a)
						{
							flag=true;
							printf("0 0 %d %d %d %d\n",i,k,j,m);
						}
						if (flag) break;
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (!flag) printf("IMPOSSIBLE\n");
	}
	return 0;
}
