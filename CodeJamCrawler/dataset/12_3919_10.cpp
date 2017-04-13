// CodeJam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

#define SMALL
//#define LARGE
#define MAX 1010
int main(){
	#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("A-large-practice.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
	#endif
	int T;
	cin>>T;
	double p[MAX],s[MAX];
	double r[MAX] = {1.0};
	int tr[MAX];
	int tw[MAX];
	
	rep(i,T){
		int A,B;
		double m = 100000000.0;
		cin>>A>>B;
		rep(j,A){
			cin>>p[j];
		}
		rep(i,MAX){
			r[i] = 1.0;
		}
		rep(k,A+1){
			rep(j,A-k){
				r[k] *= p[j];
			}
			tr[k] = B-A+1+k*2;
			tw[k] = B-A+1+k*2+B+1;
			s[k] = r[k] * tr[k] +(1-r[k])*tw[k];
			if(s[k]<m)
				m = s[k];
		}
		double ss = 1+B+1;
		if(ss<m)
			m = ss;
		printf("Case #%d: %.6f\n",i+1,m);
		//cout<<"Case #"<<i+1<<": "<<m<<endl;
	}
	return 0;
}










