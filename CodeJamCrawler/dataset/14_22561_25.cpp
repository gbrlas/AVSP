#include<stdio.h>
double cookie(double,double,double);
int main()
{
	double f[100],c[100],x[100],y[100];
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	scanf("%lf%lf%lf",&c[i],&f[i],&x[i]);
	for(i=1;i<=t;i++)
	y[i]=cookie(c[i],f[i],x[i]);
	for(i=1;i<=t;i++)
	printf("Case #%d: %.7lf\n",i,y[i]);
}
double cookie(double c,double f,double x)
{
	double y=0.0,fi=2.0;
	while(((c/fi)+(x/(fi+f)))<(x/fi))
	{
		y=y+(c/fi);
		fi=fi+f;
	}	
	y=y+x/fi;
	return y;
}
		
	
