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

struct Point
{
    int x;
    int y;
    Point(int x_, int y_): x(x_), y(y_)
    { }
};

typedef pair<int, int> ii;
const int MAX = 200 + 10;
ii a[MAX];


int main()
{
    initialize();

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int n, d;
		cin >> n >> d;
		for (int i = 0; i < n; ++i) {
			int x, c;
			cin >> x >> c;
			a[i] = ii(x, c);
		}
		sort(a, a + n);
		double down = 0.0, up = 5e6;
		while (up - down > 1e-8) {
			double mid = (up + down) / 2.0;
			bool ok = true;
			double r = -1e9;
			for (int i = 0; i < n && ok; ++i) {
				double w = (a[i].second - 1) * double(d) / 2.0;
				if (w > mid) ok = false;
				if (r + 2 * w - a[i].first > mid) ok = false;
				double s = max(a[i].first - mid, r);
				r = 2 * w + s + d;
			}
			if (ok) {
				up = mid;
			}
			else {
				down = mid;
			}
		}
		printf("Case #%d: %.10lf\n", tt, down);
	}

    return 0;
}