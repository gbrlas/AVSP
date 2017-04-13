/*
 * GCC version:			4.6
 * Command line:		g++ -std=c++0x -m64 -02 -fno-strict-aliasing -Wl,--stack=268435456 Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for(int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define parallelize if (hocus pokus = true)

struct point { double x, y; 
	point(double x, double y) : x(x), y(y) { }
};

inline double det(double a, double b, double c, double d) {
	return a * d - b * c;
}

template <class hocus = bool> struct Solver {
	int W, L, U, G;
	vector<pii> a, b;
	
	point g(const pii &p, const pii &q, double x) {
		double y = p.second + (q.second - p.second) * (x - p.first) / (q.first - p.first);
		return (point){x, y};
	}
	
	double ar(double x) {
		double res = 0;
		vector<point> p;
		int i = 0;
		for (; i < sz(a) && a[i].first < x; ++i)
			p.push_back(point(a[i].first, a[i].second));
		--i;
		assert(i >= 0);
		p.pb(g(a[i], a[i + 1], x));
		i = sz(b) - 2;
		for (; i > 0 && b[i].first > x; --i);
		p.pb(g(b[i], b[i + 1], x));
		for (; i >= 0; --i)
			p.pb(point(b[i].first, b[i].second));
		int m = sz(p);
		point t = p[0];
		p.push_back(t);
		REP (i, m) res += det(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);
		return fabs(res);
	}
	
	double f(double need) {
		double l = 0, r = W;
		REP (k, 128) {
			double v = (l + r) * 0.5;
			(ar(v) < need ? l : r) = v;
		}
		return (l + r) * 0.5;
	}
	
	void run() {
		cin >> W >> L >> U >> G;
		a.resize(L);
		b.resize(U);
		for (pii &p : a) cin >> p.first >> p.second;
		for (pii &p : b) cin >> p.first >> p.second;
		double area = ar(W) / G;
		assert(area >= 1e-9);
		cout << endl;
		REP (i, G - 1) cout << f(area * (i + 1)) << endl;
	}
};

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	cout.precision(12);	
	cout.setf(ios::fixed);
	int i = 0, n;
	for (cin >> n; i < n; ) {
		printf("Case #%d: ", ++i);
		Solver<> *s = new Solver<>;
		s->run();
		delete s;
	}
	return 0;
}
