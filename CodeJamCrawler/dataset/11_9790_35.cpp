#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cassert>

#define fi first
#define se second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define forn(i, n) for (int i = 0; i < n; ++i)
#define foreach(i, c) for (typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define DEBUG

#ifdef DEBUG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

using namespace std;

typedef long long llong;

int main () {
	int T;
	cin >> T;
	forn(t, T) {
		double d;
		int n;
		vector<double> x;
		cin >> n;
		cin >> d;
		forn (i, n) {
			int p, v;
			cin >> p >> v;
			forn (j, v)
				x.pb(p);
		}
		double l = 0;
		double r = double(x.size() + 2) * d;
		while (r - l > 1e-9) {
			double cur = (l + r) / 2;
			double last = -1e13;
			bool ok = true;
			for (int i = 0; i < x.size(); ++i) {
				if (x[i] + cur < last + d)
					ok = false;
				last = max(last + d, x[i] - cur);
			}

			if (ok)
				r = cur;
			else
				l = cur;
			
		}
		assert(l <= r);

		vector<double> y;
		double last = -1e16;
		for (int i = 0; i < x.size(); ++i) {
			last = max(last + d, x[i] - (l + r) / 2);
			y.pb(last);
		}

		double eps = 1e-8;
		double ans = (l + r)/2;
		for (int i = 0; i < x.size(); ++i) {
			assert(abs(x[i] - y[i]) <= ans + eps);
		}
		for (int i = 0; i < x.size() - 1; ++i) {
			assert(abs(y[i] - y[i + 1]) >= d);
		}

		printf("Case #%d: %.8f\n", t + 1, ans); 
	}
}

