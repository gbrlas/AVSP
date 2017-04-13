#include <string>	
#include <string.h>
#include <cstdio>	
#include <iostream>	
#include <memory>	
#include <cstdlib>	
#include <cmath>	
#include <algorithm>
#include <set>		
#include <map>		
#include <vector>
#include <ctime>	
#include <cassert>

using namespace std;

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define I64 "%I64d"
#else
#define I64 "%Ld"
#endif

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define fori(i,b,e) for(int i = (b); i < (e); i++)
#define forall(p,s) for(typeof((s).begin()) p = (s).begin(); p != (s).end(); p++)
#define memclr(a) memset((a), 0, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fi first
#define se second

typedef long double ldb;
typedef long long int64;
typedef pair<int,int> pii;

#define PROBLEM_NAME "A"

const int maxn = 1000;
int w, n, m, g;
pii a[maxn], b[maxn];
double need;

inline double getSq (double x1, double y11, double y12, double x2, double y21, double y22) {
//	printf ("%lf %lf %lf %lf %lf %lf\n", x1, y11, y12, x2, y21, y22);
	return (x2-x1) * (y12 - y11 + y22 - y21) / 2.;
}

inline double gety(double x1, double y1, double x2, double y2, double x) {
	return ((x - x1) * y2 + (x2 - x) * y1) / (x2 - x1);
}

inline double get (int i, int j, double x) {
	double x1 = max(a[i].fi, b[j].fi);
	double y11 = gety(a[i].fi, a[i].se, a[i+1].fi, a[i+1].se, x1);
	double y12 = gety(b[j].fi, b[j].se, b[j+1].fi, b[j+1].se, x1);
	double y21 = gety(a[i].fi, a[i].se, a[i+1].fi, a[i+1].se, x);
	double y22 = gety(b[j].fi, b[j].se, b[j+1].fi, b[j+1].se, x);
	return getSq(x1, y11, y12, x, y21, y22);
}

double look (vector<double>& ans, int i, int j, double x, double cur) {
	double val = get(i, j, x);
	if (cur + val < need) {
		return cur + val;
	} else {
		int num = int((cur + val) / need);
		fori(s,1,num+1) {
			double l = max(a[i].fi, b[j].fi), r = x;
			while (r - l > 1e-7) {
				double mid = (r+l) / 2;
				double cv = get(i,j,mid);
				if (cv + cur < s * need) {
					l = mid;
				} else {
					r = mid;
				}
			}
			ans.pb((l+r)/2);
		}
		return cur + val - num * need;
	}
}

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		printf ("Case #%d:\n", tt);
		scanf ("%d%d%d%d", &w, &n, &m, &g);
		fori(i,0,n) {
			scanf ("%d%d", &a[i].fi, &a[i].se);
		}
		fori(i,0,m) {
			scanf ("%d%d", &b[i].fi, &b[i].se);
		}
		a[n].fi = w+100;
		b[m].fi = w+100;
		double total = 0;
		int j = 0;
		fori(i,1,n) {
			while (j < m && b[j].fi < a[i].fi) {
				total += get(i-1, j, min(a[i].fi, b[j+1].fi));
				j++;
			}
			if (j < m && a[i].fi < b[j].fi) {
				total += get(i, j-1, min(a[i+1].fi, b[j].fi));
			}
		}
		need = total / g;
		vector<double> ans;
		ans.clear();
		double cur = 0;
		j = 0;
//		dbg(total);
		fori(i,0,n) {
			while (j < m && b[j].fi < a[i].fi) {
				cur = look(ans, i-1, j, min(a[i].fi, b[j+1].fi), cur);
				j++;
			}
			if (j < m && a[i].fi < b[j].fi) {
				cur = look(ans, i, j-1, min(a[i+1].fi, b[j].fi), cur);
			}
		}
		fori(i,0,g-1) {
			printf ("%.10lf\n", ans[i]);
		}
	}
	return 0;
}
