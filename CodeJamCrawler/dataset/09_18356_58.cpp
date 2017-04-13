#include<stdio.h>
#include<math.h>
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c;
	scanf("%d",&c);
	for(int cc=1;cc<=c;cc++)
	{
		int n;
		scanf("%d",&n);
		int x[3],y[3],r[3];
		for(int i=0;i<n;i++)scanf("%d%d%d",x+i,y+i,r+i);
		switch(n)
		{
		case 1:
			printf("Case #%d: %d\n",cc,r[0]);
			break;
		case 2:
			printf("Case #%d: %d\n",cc,((r[0]>r[1])?r[0]:r[1]));
			break;
		case 3:
			double mi=1e300;
			for(int i=0;i<3;i++)
			{
				double z=r[i]+r[(i+1)%3]+sqrt((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3])+(y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3]));
				z/=2;
				double m=((z>r[(i+2)%3])?z:r[(i+2)%3]);
				if(mi>m)mi=m;
			}
			printf("Case #%d: %lf\n",cc,mi);
			break;
		}
	}
}
