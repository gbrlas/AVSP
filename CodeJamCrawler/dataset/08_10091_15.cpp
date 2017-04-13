#include<stdio.h>
#include<string.h>
#include<math.h>
double x[100001];
double y[100001];
int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("hi.txt","w",stdout);
	double n,A,B,C,D,x0,y0,M;
	int t;
	scanf("%d",&t);
	int kk=1;
	while(kk<=t)
	{
		int i;
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&n,&A,&B,&C,&D,&x0,&y0,&M);
		x[0]=x0;
		y[0]=y0;
		for(i=1;i<=n-1;i++)
		{
			x[i]=fmod((A * x[i-1]+ B),M);
			y[i]=fmod((C * y[i-1]+ D),M);
		}
		int j,k;
		int s=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					double x1,y1;
					x1=fmod((x[i]+x[j]+x[k]),3);
					y1=fmod((y[i]+y[j]+y[k]),3);
					if(x1==0&&y1==0)
					{
						s++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",kk,s);
		kk++;
	}

}