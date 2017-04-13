#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps=0.0000000001;

long double fun(long double r, long double x)
{
    long double t=r*r;
    if(x*x>t) x=r;
    return (sqrt(t-x*x)*x + t*atan(x/(sqrt(t-x*x))))/2.;
}

long double intersection(long double y0, long double R)
{
    long double XL=0,XR=R,mid;
    while(XR-XL>eps)
    {
	mid=(XL+XR)/2.;
	if( sqrt(R*R-mid*mid)>y0) XL=mid;
	else XR=mid;
    }
    return (XR+XL)/2.;
}

main()
{
    int n;
    scanf("%d",&n);
    for(int test=1; test<=n; test++)
    {
	long double f,R,t,r,g,res=0.,R2;
	int k=0;
	scanf("%llf %llf %llf %llf %llf",&f,&R,&t,&r,&g);
	g-=2*f; r*=2; r+=2*f; t+=f;
	R2=R-t;	
	if(g<=0.) res=0.;
	else
	{    
	    long double x0=r/2., y0=r/2., x,y,x1;
	    while(y0+g+r< sqrt(R2*R2-x0*x0)) {y0+=g+r; k++;}
	    while(x0<R2)
	    {
		res+=g*g*(long double)(k+1);
		x=x0+g; y=y0+g;
		while(y0>=r/2.-eps && intersection(y0+g,R2)<x0+g)
		{
		    res-=g*g;
		    x=max(intersection(y0+g,R2),x0); x1=min(intersection(y0,R2),x0+g);
		    res+=(x-x0)*g + fun(R2,x1)-fun(R2,x)-y0*(x1-x);
		    y0-=r+g; k--;
		}
		y0+=r+g; k++;
		x0+=r+g;
		while(y0>sqrt(R2*R2-x0*x0)) {y0-=r+g; k--;}
	    }
	}
	res=1.- res/(R*R*M_PI/4.);
	printf("Case #%d: %.6llf\n",test,res);
    }
    return 0;
}
