#include<stdio.h>
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int C;
	scanf("%d",&C);
	for(int c=1;c<=C;c++)
	{
		int n,m,a;
		scanf("%d%d%d",&n,&m,&a);
		int x1,y1,x2,y2;
		bool pd=true;
		for(x1=0;pd&&x1<=n;x1++)for(y2=0;pd&&y2<=m&&x1*y2+a<=n*m;y2++)
			for(x2=1;pd&&x2<=n;x2++)if((x1*y2+a)%x2==0)
			{
				y1=(x1*y2+a)/x2;
				if(y1<=m)pd=false;
			}
		if(pd)printf("Case #%d: IMPOSSIBLE\n",c);
		else printf("Case #%d: 0 0 %d %d %d %d\n",c,x1-1,y1,x2-1,y2-1);
	}
}
