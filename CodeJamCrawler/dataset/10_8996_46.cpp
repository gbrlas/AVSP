// GCJ Round 3 2010 -- Sat Jun 12 2010
// Problem B
//
// pre-written code follows
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
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		LL L;
		int n;
		cin >> L >> n;
		vector<int> b(n);
		for (int i=0; i<n; i++)
			cin >> b[i];
		const LL MAX = min(L, 100LL * 100 + 1);
		VI r(MAX + 1, -1);
		r[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty())
		{
			int act = q.front();
			q.pop();
			for (int i=0; i<n; i++)
				if (act + b[i] <= MAX && r[act + b[i]] == -1)
				{
					r[act + b[i]] = r[act] + 1;
					q.push(act + b[i]);
				}
		}
		LL res = LLONG_MAX;
		for (int i=0; i<=MAX; i++)
		{
			if (r[i] == -1)
				continue;
			LL d = L - i;
			for (int j=0; j<n; j++)
				if (d % b[j] == 0)
					res = min(res, r[i] + d / b[j]);
		}
		printf("Case #%d: ", tkase+1);
		if (res == LLONG_MAX)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
