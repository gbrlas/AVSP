#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<iterator>
#include<streambuf>
#include<sstream>
#include<list>
#include<stack>
#include<ostream>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

inline double EUCDIST(double x1,double y1,double x2,double y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline double dist(double x1,double y1,double r1,double x2,double y2,double r2){
	double total= r1 + r2 + EUCDIST(x1,y1,x2,y2);
	return total/2.0;
}

struct node {
	double x1,y1,r1;
	node(double a,double b,double c):x1(a),y1(b),r1(c){}
};

inline double getdist(const node &p,const node &q){ return dist(p.x1,p.y1,p.r1,q.x1,q.y1,q.r1); }
inline double maxrad2(const node &a,const node &b){ return max(a.r1,b.r1); }
inline double maxrad3(const node &a,const node &b,const node&c){ 
		// {a,b} {c}
		double dist1=max(getdist(a,b),c.r1);
		// {a,c} {b}
		double dist2=max(getdist(a,c),b.r1);
		// {a} {b,c}
		double dist3=max(getdist(b,c),a.r1);
//		printf("%.5f %.5f %.5f\n",dist1,dist2,dist3);
		return min(dist1,min(dist2,dist3));
}

int main(){
	int tc=1;
	int no;
	cin >> no;
	while(no--){
	int n;
	cin >> n;
	int i;
	vector<node> v;
	for(i=0;i<n;i++){
		double x,y,r;
		cin >> x>>y>>r;
		node tmp(x,y,r);
		v.push_back(tmp);
	}
	double ans=1e10;
	if(n==1){
		ans=v[0].r1;
	}
	else if(n==2){
		ans=maxrad2(v[0],v[1]);
	}
	else if(n==3){
		ans=maxrad3(v[0],v[1],v[2]);
	}
	printf("Case #%d: %.6f\n",tc++,ans);
	}
	return 0;
}

