#include<stdio.h>
#include<math.h>
const double pi=acos(0)*2;
double cmj(double r,double x)
{
	return acos(x/r)/(pi/2)*pi*r*r/4-x*sqrt(r*r-x*x)/2;
}
double tmj(double r,double x,double y)
{
	return cmj(r,x)-cmj(r,y);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int tt=1;tt<=n;tt++)
	{
		double f,R,t,r,g;
		scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
		if(f+f>=g)
		{
			printf("Case #%d: 1.000000\n",tt);
			continue;
		}
		g-=f+f,r+=f;
		f=R-t-f;
		double mj=0;
		for(int i=0;r+i*(g+r+r)<f;i++)for(int j=0;(r+i*(g+r+r))*(r+i*(g+r+r))+(r+j*(g+r+r))*(r+j*(g+r+r))<f*f;j++)
			if((r+g+i*(g+r+r))*(r+g+i*(g+r+r))+(r+g+j*(g+r+r))*(r+g+j*(g+r+r))<=f*f)mj+=g*g;
			else
			{
				double x;
				if((r+g+i*(g+r+r))*(r+g+i*(g+r+r))+(r+j*(g+r+r))*(r+j*(g+r+r))<=f*f)x=tmj(f,r+i*(g+r+r),r+g+i*(g+r+r))-g*(r+j*(g+r+r));
				else
				{
					double y=sqrt(f*f-(r+j*(g+r+r))*(r+j*(g+r+r)));
					x=tmj(f,r+i*(g+r+r),y)-(y-(r+i*(g+r+r)))*(r+j*(g+r+r));
				}
				if((r+i*(g+r+r))*(r+i*(g+r+r))+(r+g+j*(g+r+r))*(r+g+j*(g+r+r))<=f*f)
				{
					double y=sqrt(f*f-(r+g+j*(g+r+r))*(r+g+j*(g+r+r)));
					x-=tmj(f,r+i*(g+r+r),y)-(y-(r+i*(g+r+r)))*(r+g+j*(g+r+r));
				}
				mj+=x;
			}
		double zmj=R*R*pi/4;
		printf("Case #%d: %.6lf\n",tt,(zmj-mj)/zmj);
	}
}
