#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime> //clock()
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>

using namespace std;

#pragma comment(linker, "/STACK:33554432")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define it iterator
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()

const long double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const long double PI = 2 * acos(.0);
const int con = 60;
const long double c2 = 0.47;

int n, x[1100], y[1100], z[1100], p[1100];

long double f3(long double xx, long double yy, long double zz) {
	long double res = 0;
	forn(i, n)
		res = max(res, 1.0 * (abs(xx - x[i]) + abs(yy - y[i]) + abs(zz - z[i])) / p[i]);
	return res;
}

long double f2(long double xx, long double yy) {
	long double l = -1E6;
	long double r = 1E6;

	forn(it, con) {
		long double md = (r - l) * c2;
		long double m1 = l + md;
		long double m2 = r - md;

		if (f3(xx, yy, m1) < f3(xx, yy, m2))
			r = m2;
		else
			l = m1;
	}

	long double val = (l + r) / 2.0;
	long double ans = f3(xx, yy, val);

	return ans;
}

long double f1(long double xx) {
	long double l = -1E6;
	long double r = 1E6;

	forn(it, con) {
		long double md = (r - l) * c2;
		long double m1 = l + md;
		long double m2 = r - md;

		if (f2(xx, m1) < f2(xx, m2))
			r = m2;
		else
			l = m1;
	}

	long double val = (l + r) / 2.0;
	long double ans = f2(xx, val);

	return ans;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		cerr << tt << endl;
		scanf("%d", &n);
//		n = 1000;
		forn(i, n) {
			scanf("%d%d%d%d", &x[i], &y[i], &z[i], &p[i]);
//			x[i] = rand() % 1000000;
//			y[i] = rand() % 1000000;
//			z[i] = rand() % 1000000;
//			p[i] = rand() % 1000000;
		}

		long double l = -1E6;
		long double r = 1E6;

		forn(it, con) {
			long double md = (r - l) * c2;
			long double m1 = l + md;
			long double m2 = r - md;

			if (f1(m1) < f1(m2))
				r = m2;
			else
				l = m1;
		}

		long double xx = (l + r) / 2.0;

		long double ans = f1(xx);

		printf("Case #%d: %.6lf\n", tt + 1, ans);
	}

//	printf("%d\n", clock());
	
	return 0;
}