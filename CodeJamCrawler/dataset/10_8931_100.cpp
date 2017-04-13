// GCJ Round 1B 2010 -- Sat May 22 2010
// Problem B
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
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
typedef vector<LL> VLL;
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int n, k;
		LL b, t;
		cin >> n >> k >> b >> t;
		VLL x(n), v(n);
		for (int i=0; i<n; i++)
			cin >> x[i];
		for (int i=0; i<n; i++)
			cin >> v[i];
		vector<int> flag(n, false);
		for (int i=0; i<n; i++)
		{
			if (x[i] + t * v[i] >= b)
			{
				flag[i] = true;
			}
		}
		int overtake = 0;
		int total = 0;
		for (int i=n-1; i>=0 && k>0; i--)
			if (flag[i])
			{
				total += overtake;
				k--;
			}
			else
				overtake++;
		printf("Case #%d: ", tkase+1);
		if (k == 0)
			cout << total << endl;
		else
			puts("IMPOSSIBLE");
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
