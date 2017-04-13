#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;
#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("l.in", "r", stdin);
    freopen("l.out", "w", stdout);
}

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

struct A {
	double v, l;
	A(double l_, double v_): l(l_), v(v_)
	{ }
	bool operator < (const A& aa) const {
		return v < aa.v;
	}
};


int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt= 1; tt <= T; ++tt) {
		vector<A> w;
		double res = 0.0;
		double  x, s, r, t;
		int n;
		double sum = 0.0;
		cin >> x >> s >> r >> t >> n;
		for (int i = 0; i < n; ++i) {
			double a, b, v;
			cin >> a >> b >> v;
			w.pb(A(b - a, v));
			sum += b - a;
		}
		sum = x - sum;
		w.pb(A(sum, 0.0));
		sort(all(w));

		for (int i = 0; i < w.size(); ++i) {
			double speed = (w[i].v + r);
			double time = w[i].l / speed;
			if (time > t) {
				double length = speed * t;
				t = 0.0;
				res += length / speed;
				res += (w[i].l - length) / (w[i].v + s);
			}
			else {
				res += time;
				t -= time;
			}
		}
		printf("Case #%d: %.10lf\n", tt, res);
	}

    return 0;
}