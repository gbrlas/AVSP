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
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
}

const double INF = 1e9;
const double EPS = 1e-8;

struct Point
{
    double x;
    double y;
    Point(double x_, double y_): x(x_), y(y_)
    { }
	bool operator < (const Point& p) const {
		if (x != p.x) return x < p.x;\
		return y < p.y;
	}
};

double value(const vector<Point>& points, double x) {
	int ind = lower_bound(all(points), Point(x, INF)) - points.begin();
	if (ind == points.size()) {
		return points.back().y;
	}
	if (ind == 0) {
		return points.front().y;
	}
	return points[ind - 1].y + (points[ind].y - points[ind - 1].y) * (x - points[ind - 1].x) / (points[ind].x - points[ind - 1].x);
}

double ss(const vector<Point>& l, const vector<Point>& u, double a, double b) {
	double ua = value(u, a), ub = value(u, b);
	double la = value(l, a), lb = value(l, b);
	return (b - a) * (ua + ub - la - lb) / 2.0;
}

int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		vector<Point> l ,u;
		vector<double> c;
		double g;
		int n, m, k;
		cin >> g >> n >> m >> k;
		for (int i = 0; i < n; ++i) {
			double x, y;
			cin >> x >> y;
			l.pb(Point(x, y));
			c.pb(x);
		}
		for (int i = 0; i < m; ++i) {
			double x, y;
			cin >> x >> y;
			u.pb(Point(x, y));
			c.pb(x);
		}
		sort(all(c));
		
		double area = 0.0;
		for (int i = 1; i < c.size(); ++i) {
			area += ss(l, u, c[i - 1], c[i]);
		}
		area /= k;

		vector<double> res;
		double x = 0.0;
		double cur = 0.0;
		for (int i = 1; i < c.size(); ++i) {
			if (cur + ss(l, u, x, c[i]) > area) {
				double down = x, up = c[i];
				while (up - down > EPS) {
					double med = (up + down) / 2.0;
					if (cur + ss(l, u, x, med) > area) up = med;
					else down = med;
				}
				res.pb(down);
				cur = 0.0;
				x = down;
				--i;
			}
			else {
				cur += ss(l, u, x, c[i]);
				x = c[i];
			}
		}
		res.resize(k - 1);
		printf("Case #%d:\n", tt);
		for (int i = 0; i < res.size(); ++i) {
			printf("%.10lf\n", res[i]);
		}
	}
 
    return 0;
}
