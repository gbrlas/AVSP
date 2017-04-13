#include<iostream>
#include<fstream>
#include<cmath>
#define EPS 0.000001
#define ABS(a) ((a)>0?(a):(-(a)))
#define isZero(a) (ABS(a)<EPS)
using namespace std;

int main(){
	ifstream fin("B.in");
	freopen("B.out", "w", stdout);
	int ca,n;
	fin>>ca;
	double xt0, yt0, zt0, xtv, ytv, ztv;
	for(int cas=1; cas<=ca; ++cas){
		double x0=0, xv=0, y0=0,yv=0,z0=0,zv=0;
		fin>>n;
		for(int i=0; i<n; ++i){
			fin>>xt0>>yt0>>zt0>>xtv>>ytv>>ztv;
			x0+=xt0;
			y0+=yt0;
			z0+=zt0;
			xv+=xtv;
			yv+=ytv;
			zv+=ztv;
		}
		double A=xv*xv+yv*yv+zv*zv;
		double B=x0*xv+y0*yv+z0*zv;
		double C=x0*x0+y0*y0+z0*z0;
		double t=0;
		if(isZero(A))
			t=0;
		else 
			t=-B/A;
		t=t<0?0:t;
		if(isZero(t))
			t=0;
		double nn=n;
		double xx=(x0+t*xv)/nn;
		double yy=(y0+t*yv)/nn;
		double zz=(z0+t*zv)/nn;
		double dis2=sqrt(xx*xx+yy*yy+zz*zz);
		printf("Case #%d: %.8f %.8f\n",cas,dis2, t);
	}

}
