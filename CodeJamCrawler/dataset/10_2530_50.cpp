//#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

const double pi=3.1415926535897932384626433832795;

struct point{
	double x,y;
	point(double a=0.,double b=0.){x=a,y=b;}
	void get(){scanf("%lf%lf",&x,&y);}
	void show(){printf("%.4lf %.4lf\n",x,y);}
	double dis(){return x*x+y*y;}
	double dist(){return sqrt(dis());}
	point operator+(point b){return point(x+b.x,y+b.y);}
	point operator-(point b){return point(x-b.x,y-b.y);}
	point operator*(double t){return point(x*t,y*t);}
	point operator/(double t){return point(x/t,y/t);}	
};

point a,b,c;
double r1,r2;

double getans(){
	r1=(a-c).dist();
	r2=(b-c).dist();
	if (r1+r2<=(a-b).dist()) return 0;
	if (r1+(a-b).dist()<=r2) return pi*r1*r1;
	if (r2+(a-b).dist()<=r1) return pi*r2*r2;
	double c1,c2;
	c1=(r1*r1-r2*r2+(a-b).dis())/(a-b).dist()/r1/2.0;
	c2=(r2*r2-r1*r1+(a-b).dis())/(a-b).dist()/r2/2.0;
	double s1,s2;
	s1=acos(c1);
	s2=acos(c2);
	double ans=0;
	/*if (s1<pi/2.) ans+=s1*r1*r1-r1*r1*sin(s1);
	else ans+=s1*r1*r1+r1*r1*sin(s1);
	if (s2<pi/2.) ans+=s2*r2*r2-r2*r2*sin(s2);
	else ans+=s2*r2*r2+r2*r2*sin(s2);*/
	ans+=s1*r1*r1-r1*r1*sin(s1)*cos(s1);
	ans+=s2*r2*r2-r2*r2*sin(s2)*cos(s2);
	return ans;
}

int o,n,m;

int main(){
	int T=0;
	for (scanf("%d",&o);o--;){
		scanf("%d%d",&n,&m);
		a.get();b.get();
		printf("Case #%d:",++T);
		for (;m--;){
			c.get();
			printf(" %.10lf",getans());
		}
		printf("\n");
	}
	return 0;
}
