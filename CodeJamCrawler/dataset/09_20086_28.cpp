#include<stdio.h>
#include<math.h>

int x[4],y[4],r[4];

int main()
{
	int t,p;
	int n,i;
	double mm,m;
	double d;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
		printf("Case #%d: ",p);
		if (n<=2)
		{
			mm=0;
			for (i=1;i<=n;i++)
				if (mm<r[i]) mm=r[i];
			printf("%lf\n",mm);
		}
		else
		{
			mm=10000;
			d=sqrt((double)(x[1]-x[2])*(x[1]-x[2])+(y[1]-y[2])*(y[1]-y[2]))+r[1]+r[2];
			if (d/2<r[3]) m=r[3];
			else m=d/2;
			if (m<mm) mm=m;
			d=sqrt((double)(x[1]-x[3])*(x[1]-x[3])+(y[1]-y[3])*(y[1]-y[3]))+r[1]+r[3];
			if (d/2<r[2]) m=r[2];
			else m=d/2;
			if (m<mm) mm=m;
			d=sqrt((double)(x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]))+r[3]+r[2];
			if (d/2<r[1]) m=r[1];
			else m=d/2;
			if (m<mm) mm=m;
			printf("%lf\n",mm);
		}
	}
	return 0;
}

			
