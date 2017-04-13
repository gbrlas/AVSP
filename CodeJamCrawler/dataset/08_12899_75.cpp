#include <stdio.h>
#include <string.h>
#include <math.h>

const double EPS=1e-10;
const double PI=asin(1.0)*2;
bool flag[4];
double pos[4];

double R,RR;

double dist(double x1,double y1,double x2,double y2)
{
	double dx=x1-x2,dy=y1-y2;
	return sqrt(dx*dx+dy*dy);
}

double com(double l)
{
	double a=asin(l/R/2)*2;
	return RR*(a-sin(a))/2;
}

double solve()
{
	double r,t,f,g;
	
	scanf("%lf%lf%lf%lf%lf",&f,&R,&t,&r,&g);
	t+=f;
	r+=f;
	g-=f*2;

	double totArea=PI*R*R;

	R-=t;
	if(R<EPS) return 1;
	if(g<EPS) return 1;
	if(r+EPS>R) return 1;

//	printf("%.7lf %.7lf %.7lf\n",R,r,g);

	RR=R*R;
	double gg=g*g;
	double area=0;
	double x,y;

	x=r;
	while(x+EPS<R) {
		double x2=x+g;		
		double maxY=sqrt(R*R-x*x);

		y=r;
		while(y+EPS<maxY) {
			double y2=y+g;

			double dd=x2*x2+y2*y2;
			if(dd<RR+EPS) {
				area+=gg;
			}
			else {
				memset(flag,0,sizeof(flag));
				if(x+EPS<R) {
					double w=sqrt(RR-x*x);
					if(w+EPS>y && w<y2+EPS) {
						flag[0]=1;
						pos[0]=w;
					}
				}
				if(x2+EPS<R) {
					double w=sqrt(RR-x2*x2);
					if(w+EPS>y && w<y2+EPS) {
						flag[2]=1;
						pos[2]=w;
					}
				}
				if(y+EPS<R) {
					double w=sqrt(RR-y*y);
					if(w+EPS>x && w<x2+EPS) {
						flag[1]=1;
						pos[1]=w;
					}
				}
				if(y2+EPS<R) {
					double w=sqrt(RR-y2*y2);
					if(w+EPS>x && w<x2+EPS) {
						flag[3]=1;
						pos[3]=w;
					}
				}

				double s,len;
				if(flag[0] && flag[1]) {
					s=(pos[0]-y)*(pos[1]-x)/2;
					len=dist(x,pos[0],pos[1],y);
				}
				else if(flag[0] && flag[2]) {
					s=((pos[0]-y)+(pos[2]-y))*g/2;
					len=dist(x,pos[0],x2,pos[2]);
				}
				else if(flag[3] && flag[2]) {
					s=(pos[3]-x)*g;
					s+=(pos[2]-y+g)*(g-(pos[3]-x))/2;
					len=dist(pos[3],y2,x2,pos[2]);
				}
				else if(flag[3] && flag[1]) {
					s=((pos[3]-x)+(pos[1]-x))*g/2;
					len=dist(pos[3],y2,pos[1],y);
				}
				else {
					printf("ERROR\n");
				}

				s+=com(len);

//				printf("%.6lf %.6lf : %.6lf\n",x,y,s);
				area+=s;
			}

			y=y2+r+r;
		}
		x=x2+r+r;
	}
	
	area*=4;
	return (totArea-area)/totArea;
}

int main()
{
	int T;	
	scanf("%d",&T);

	for(int casen=1;casen<=T;casen++) printf("Case #%d: %.8lf\n",casen,solve());
	return 0;
}
