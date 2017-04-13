#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <list>
#include <cstdlib>
#include <cmath>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int,int> para;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<string> VS;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define fore(a,n) for(typeof(n.begin())a=n.begin();a!=n.end();++a)
#define REP(a,n) for(int a=0;a<(n);a++)
#define ALL(x) x.begin(),x.end()

/*Biblioteka do geometri*/

const long double EPS = 1e-12;

typedef long double coord;
typedef pair<coord,coord> point;

point operator-(point & a, point & b){
	return MP(a.F-b.F,a.S-b.S);
}
point & operator-=(point & a, point & b){
	return a=a-b;
}
point operator+(point & a, point & b){
	return MP(a.F+b.F,a.S+b.S);
}
point & operator+=(point & a, point & b){
	return a=a+b;
}
inline coord cross2d(point a, point b){//value of cross product
	return a.F*b.S-a.S*b.F;
}
inline coord isLeft(point p0,point p1, point q){//<0 if q is on the left side of line containing p0 i p1 
	return (p1.F-p0.F)*(q.S-p0.S)-(q.F-p0.F)*(p1.S-p0.S);//cross2d(p1-p0,q-p0);
}

coord polygon_area(vector<point> v){//2 * area of polygon v[0], v[1],..
	int n=v.size();
	v.PB(v[0]);
	v.PB(v[1]);
	coord res=(coord)(0.);
	for(int i=1;i<=n;i++)
		res+=v[i].F*(v[i+1].S-v[i-1].S);
	return res;
}

inline bool pointInCircle(point p,coord r){//is a point p in circle with centre at (0,0) and radius r?
	if((p.F*p.F+p.S*p.S)<=r*r+EPS)
		return true;
	return false;
}

inline coord dist(point a,point b){
//	cout<<a.F<<" "<<a.S<<" " <<b.F<<" "<<b.S<<endl;
 //	cout<<(a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S)<<endl;
	return sqrtl((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}

coord circularSegment(point a,point b,coord R){//area of circular segment
	coord D = dist(a,b);
//	cout<<D<<" "<<R<<endl;
	assert(D/2./R<=1.);
	assert(D/2./R>=-1.);
	long double alpha2 = asinl(D/2./R);
	assert(R*R-D*D/4.>=0.);
	return alpha2*R*R - D*sqrtl(R*R-D*D/4.)/2.;
}	

coord intersect(point p,point q, coord R){//returns the area of intersection of square and circle
	point r=MP(p.F,q.S),s=MP(q.F,p.S),a,b;
	coord pres=0.;
	bool f = false;
	if(!pointInCircle(r,R) && !pointInCircle(s,R)){
		a = MP(p.F,sqrt(R*R-p.F*p.F));
		b = MP(sqrtl(R*R-p.S*p.S),p.S);
		pres = (a.S-p.S)*(b.F-p.F)/2.;
	}
	else{
		vector<point> v;
		v.PB(p);
		if(pointInCircle(s,R)){
			v.PB(s);
			point pun = MP(q.F,sqrtl(R*R-q.F*q.F));
			v.PB(pun);
			if(!f){
				a = pun;
				f = true;
			}
			else
				b = pun;
		}
		else{
			point pun = MP(sqrtl(R*R-p.S*p.S),p.S);
			v.PB(pun);
			if(!f){
				a = pun;
				f = true;
			}
			else
				b = pun;
		}
		if(pointInCircle(r,R)){
			point pun = MP(sqrtl(R*R-q.S*q.S),q.S);
			v.PB(pun);
			if(!f){
				a = pun;
				f = true;
			}
			else
				b = pun;
			v.PB(r);
		}
		else{
			point pun = MP(p.F,sqrtl(R*R-p.F*p.F));
			v.PB(pun);
			if(!f){
				a = pun;
				f = true;
			}
			else
				b = pun;
		}
		pres = polygon_area(v)/2.;
	}
//	cout<<a.F<<" "<<a.S<<" " <<b.F<<" "<<b.S<<endl;
//	cout<<pres<<" "<<circularSegment(a,b,R)<<endl;
	return pres + circularSegment(a,b,R);
}

/*******************************************************/

const int N = 1507;

const long double pi = acosl(0.)*2.;

int D;
long double f,R,t,r,g,res,oR;

int main()
{
//	cout<<intersect(MP(0.,0.),MP(1.,1.),1.4142)<<endl;
	scanf("%d",&D);
	REP(I,D){
		scanf("%Lf %Lf %Lf %Lf %Lf",&f,&R,&t,&r,&g);
		if(2.*f >= (g-EPS)){
			res=1.;
			printf("Case #%d: %.6Lf\n",I+1,res);
			continue;
		}
		r+=f;//only the fly's center is important for us
		g-=2.*f;
		oR = R;//outer radius
		R -= t+f;
		res = 0.;
		long double jump = g + 2. * r,sqrg=g*g;
//		double denom =  pi * oR * oR / 4.;
		point p,q;
//		cout<<R<<endl;
		REP(i,N){
//			cout<<res<<endl;
			p = MP(r,r+jump*(long double)i);
			if(!pointInCircle(p,R))//out of the circle
				break;
			for(int j=0;j<N;j++,p.F += jump){
				if(!pointInCircle(p,R))//out of the circle
					break;
				q = MP(p.F+g,p.S+g);
				if(pointInCircle(q,R)){
					res+=sqrg;//whole square inside
//					cout<<res<<endl;
				}
				else{
//					cout<<p.F<<" "<<p.S<<" "<<q.F<<" "<<q.S<<endl;
					res+=intersect(p,q,R);
//					printf("%lf\n",res);
//					cout<<res<<endl;
				}
			}
		}
//		cout<<oR<<endl;
//		cout<< pi * oR * oR / 4.<<endl;
		res /= pi * oR * oR / 4.; 
		printf("Case #%d: %.6Lf\n",I+1,1.-res);
	}
	return 0;
}
