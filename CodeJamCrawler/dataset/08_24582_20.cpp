#include <stdio.h>


int n,m;
int a;

int x1,y1,x2,y2;


int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);

	int c,C;
	int xx1,yy1,xx2,yy2;

	scanf("%d",&C);
	for (c=1;c<=C;c++)
	{
		scanf("%d %d %d",&n,&m,&a);
		xx1=-1;
		xx2=-1;
		yy1=-1;
		yy2=-1;

		for (x1=0;x1<=n;x1++) for (y2=0;y2<=m;y2++)
		if (x1*y2>=a)
		{
			for (x2=0;x2<=n;x2++)
			{
				if (x2==0)
				{
					if (x1*y2==a)
					{
					xx1=x1;
					xx2=x2;
					yy1=m;
					yy2=y2;
					}
				}else if ((x1*y2-a)%x2==0)
				{
					if ((x1*y2-a)/x2<=m)
					{
						xx1=x1;
						xx2=x2;
						yy1=(x1*y2-a)/x2;
						yy2=y2;
					}
				}
			}
		}
		printf("Case #%d: ",c);
		if (xx1<0)
		{
			printf("IMPOSSIBLE\n");
		}else
		{
			printf("0 0 %d %d %d %d\n",xx1,yy1,xx2,yy2);
		}
	}


	return 0;
}