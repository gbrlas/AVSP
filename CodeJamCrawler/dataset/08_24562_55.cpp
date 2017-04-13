#include <stdio.h>
#include <math.h>
#define eps 1e-7


double xx[4],yy[4];

double det(double x0,double y0,double x1,double y1)
{
	return x0*y1-y0*x1;
}

double GetPrimS(double x0,double y0,double x1,double y1,double r)
{
	double d=det(x0,y0,x1,y1)/2;
	if (r<-0.1)
		return d;
	double alpha = acos(1.0 - ((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1))/(2.0*r*r) );
	double ret=alpha*r*r/2;
	if (d<0)
		return -ret;
	return ret;
}
void GetXY(double r,double x0,double y0,double x1,double y1,double &x,double &y)
{
	double a,b,c,d,t;
	double vx=x1-x0,vy=y1-y0;
	a=vx*vx+vy*vy;
	b=2*(x0*vx+y0*vy);
	c=x0*x0+y0*y0-r*r;
	d=b*b-4*a*c;
	if (fabs(d)<eps)
		d=0.0;
	else
		d=sqrt(d);
	t=(-b-d)/(2*a);
	if (t<0.0 || t>1.0)
		t=(-b+d)/(2*a);
	x=x0+vx*t;
	y=y0+vy*t;
}

double GetS(double *x,double *y,double r)
{
	int i;
	double ret=0.0;
	double x0,y0,x1,y1;

	for (i=0;i<4;i++)
	if (x[i]*x[i]+y[i]*y[i]>r*r+eps)
		break;
	if (i==4)
		return fabs(x[0]-x[2])*fabs(y[0]-y[2]);

	for (i=0;i<4;i++)
	if (x[i]*x[i]+y[i]*y[i]<r*r-eps)
		break;
	if (i==4)
		return 0.0;

	for (i=0;i<4;i++)
	{
		if ((x[i]*x[i]+y[i]*y[i]<r*r+eps)&&(x[(i+1)%4]*x[(i+1)%4]+y[(i+1)%4]*y[(i+1)%4]>r*r-eps))
		{
			GetXY(r,x[i],y[i],x[(i+1)%4],y[(i+1)%4],x0,y0);
			ret+=GetPrimS(x[i],y[i],x0,y0,-1.0);
			for (i++;!((x[i]*x[i]+y[i]*y[i]>r*r-eps)&&(x[(i+1)%4]*x[(i+1)%4]+y[(i+1)%4]*y[(i+1)%4]<r*r+eps));i++);
			if (i==4)
			{
				i=3;
			}
			GetXY(r,x[i],y[i],x[(i+1)%4],y[(i+1)%4],x1,y1);
			ret+=GetPrimS(x0,y0,x1,y1,r);
			ret+=GetPrimS(x1,y1,x[(i+1)%4],y[(i+1)%4],-1.0);
		}else
			ret+=GetPrimS(x[i],y[i],x[(i+1)%4],y[(i+1)%4],-1.0);
	}
	return fabs(ret);
}

double Solve(double r,double h,double dh)
{
	double ret=0.0;
	double x,y;
	double y1,y2;
	int i,j;
	for (i=0;dh/2+i*(h+dh)<=r+eps;i++)
	for (j=0;dh/2+j*(h+dh)<=r+eps;j++)
	{
		x=dh/2+i*(h+dh);
		y=dh/2+j*(h+dh);
		xx[0]=x; yy[0]=y;
		xx[1]=x; yy[1]=y+h;
		xx[2]=x+h; yy[2]=y+h;
		xx[3]=x+h; yy[3]=y;
		ret+=GetS(xx,yy,r);
	}
	ret*=4;

	return ret;
}
double f, R, t, r, g;

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int n,N;
	scanf("%d",&N);
	double res;
	for (n=1;n<=N;n++)
	{
		scanf("%lf %lf %lf %lf %lf",&f,&R,&t,&r,&g);
		if (g<2*f+eps || R<t+f+eps)
			res=1.0;
		else
			res=1.0-Solve(R-t-f,g-2*f,2*(r+f))/(4*atan(1.0)*R*R);
		printf("Case #%d: %.6lf\n",n,res);
	}
	return 0;
}