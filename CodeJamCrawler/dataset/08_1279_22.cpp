#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<vector>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define UNIQUE(a)   sort(all(a)),(a).erase(unique(all(a)),a.end())
#define fr(i,n)     for(int i=0;i<n;++i)
#define fo(n)       fr(i,n)
#define foj(n)      fr(j,n)
#define fok(n)      fr(k,n)
#define x           first
#define y           second

typedef long long ll;
typedef pair<int,int>   pii;

double det(double a,double b,double c,double d){ return a*d-b*c; }

double dist(double x,double y){ return x*x+y*y; }

void solve(double a0,double b0,double c0,double a1,double b1,double c1,double&x,double&y){
	double d=det(a0,b0,a1,b1);
	x=det(-c0,b0,-c1,b1)/d;
	y=det(a0,-c0,a1,-c1)/d;
}

struct triangle{
	double x0,y0,x1,y1,x2,y2;
	void read(){
		cin>>x0>>y0>>x1>>y1>>x2>>y2;
	}
	double X(){ return (x0+x1+x2)/3; }
	double Y(){ return (y0+y1+y2)/3; }
	double sq(){ return det(x0,y0,x1,y1)+det(x1,y1,x2,y2)+det(x2,y2,x0,y0); }
	double a(){ return dist(x1-x0,y1-y0); }
	double b(){ return dist(x1-x2,y1-y2); }
	double c(){ return dist(x0-x2,y0-y2); }
	void norm(){
		double X[]={x0,x1,x2},Y[]={y0,y1,y2};
		int p[]={0,1,2};
		do{
			double d[3];
			for(int i=0;i<3;++i){
				int j=(i+1)%3;
				d[i]=dist(X[p[i]]-X[p[j]],Y[p[i]]-Y[p[j]]);
			}
			if(fabs(d[0]-d[1])<1e-9){
				x0=X[p[0]],y0=Y[p[0]];
				x1=X[p[1]],y1=Y[p[1]];
				x2=X[p[2]],y2=Y[p[2]];
				break;
			}
		}while(next_permutation(p,p+3));
		if(sq()<0)swap(x0,x2),swap(y0,y2);
	}
	void K(double x,double y,double&k0,double&k1,double&k2){
		solve(x0-x2,x1-x2,x2-x,y0-y2,y1-y2,y2-y,k0,k1);
		k2=1-k0-k1;
	}
	double X(double k0,double k1,double k2){ return x0*k0+x1*k1+x2*k2; }
	double Y(double k0,double k1,double k2){ return y0*k0+y1*k1+y2*k2; }
};

void test(){
	triangle a,b;
	a.read(),b.read();
	a.norm(),b.norm();
	for(int k=0;k<1000000 && fabs(a.sq())>0;++k){
		triangle c;
		double k0,k1,k2;
		a.K(b.x0,b.y0,k0,k1,k2);
		c.x0=b.X(k0,k1,k2);
		c.y0=b.Y(k0,k1,k2);
		a.K(b.x1,b.y1,k0,k1,k2);
		c.x1=b.X(k0,k1,k2);
		c.y1=b.Y(k0,k1,k2);
		a.K(b.x2,b.y2,k0,k1,k2);
		c.x2=b.X(k0,k1,k2);
		c.y2=b.Y(k0,k1,k2);
		a=c;
		swap(a,b);
	}
	printf("%.6lf %.6lf\n",b.X(),b.Y());
}

int main(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t++<T;){
		printf("Case #%d: ",t);
		test();
	}
	return 0;
}
