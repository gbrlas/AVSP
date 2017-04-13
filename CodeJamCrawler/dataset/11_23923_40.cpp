#include<cstdio>
#include<cassert>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cctype>
#include<queue>
using namespace std;

int w,l,u,g;

double eps = 1e-8;
const int N = 1003;

struct pt{
	double x,y;
	pt(double a=-1, double b=-1):x(a), y(b){}
};
pt L[N], U[N];

double area (double x, pt* P, int n){
	double res=0;
	for(int i=0; i+1<n; i++){
		if(P[i+1].x<x+eps){
			res+= (P[i+1].x - P[i].x)*(P[i].y+P[i+1].y)/2.;
		} else {
			double d = x - P[i].x;
			double w = P[i+1].x - P[i].x;
			pt tmp(x, P[i].y + (P[i+1].y-P[i].y)*(d/w));
			res+= (tmp.x - P[i].x)*(P[i].y+tmp.y)/2.;
			break;
		}
	}
	//printf("%lf\n",res);
	return res;
}

double area(double x){
	//printf("UP\n");
	double up = area(x, U, u);
	//printf("LOW\n");
   	double low = area(x, L, l);
	return up - low;
}

void solve(){
	scanf("%d %d %d %d",&w,&l,&u,&g);
	for(int i=0; i<l; i++) scanf("%lf %lf", &L[i].x, &L[i].y);
	for(int i=0; i<u; i++) scanf("%lf %lf", &U[i].x, &U[i].y);

	int x = 0;
	double A = area(w)/g; //XXX
	//printf("A = %lf\n",A);
	for(int i=1; i<g; i++){
		double se = A*i;
		double L = 0, R = w, mid;
		while((R-L)>eps){
			mid = (L+R)/2.;
			double tmp  = area(mid);
			if(tmp>se) R=mid;
			else L=mid;
		}
		printf("%.9lf\n", (L+R)/2.);
	}
}

main(){
	int T;
	scanf("%d",&T);
	for(int testcase=1; testcase<=T; testcase++){
		printf("Case #%d:\n",testcase);
		solve();
	}
	return 0;
}
