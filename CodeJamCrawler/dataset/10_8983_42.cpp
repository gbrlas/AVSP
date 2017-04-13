// GCJ Round 2 2010 -- Sat Jun 5 2010
// Problem D
//
// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<long double> tComp;
const long double PI = 2.0 * acos(0.0);
const long double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
tComp read_tComp()
{
	long double x, y;
	cin >> x >> y;
	return tComp(x, y);
}
long double f(long double d, long double r, long double R)
{
	long double x = (d * d + r * r - R * R) / (2 * d * r);
	long double y = (d * d + R * R - r * r) / (2 * d * R);
	long double z = (-d + r + R) * (d + r - R) * (d - r + R) * (d + r + R);
	return r * r * acosl(x) + R * R * acosl(y) - 0.5 * sqrtl(z);
}
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int n, m;
		cin >> n >> m;
		vector<tComp> P(n), Q(m);
		for (int i=0; i<n; i++)
			P[i] = read_tComp();
		for (int j=0; j<m; j++)
			Q[j] = read_tComp();
		tComp P0 = P[0];
		FORIT(it, P)
			*it -= P0;
		FORIT(it, Q)
			*it -= P0;
		long double alpha = arg(P[1]);
		FORIT(it, P)
			*it *= polar(1.0l, -alpha);
		FORIT(it, Q)
			*it *= polar(1.0l, -alpha);
		printf("Case #%d:", tkase+1);
		long double d = real(P[1]);
		FORIT(it, Q)
		{
			long double R = abs(*it - P[0]);
			long double r = abs(*it - P[1]);
			long double A = f(d, r, R);
			assert(A >= 0.0);
			printf(" %.7Lf", A);
		}
		cout << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
