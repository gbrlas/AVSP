// GCJ Round 2 2010 -- Sat Jun 5 2010
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
LL cost[1024 * 1024];
LL dp[16][16 * 1024];
LL solve(int missed, int pos, int offset)
{
	if (pos >= offset)
	{
		if (missed > cost[pos])
			return OO;
		return 0;
	}
	LL &ret = dp[missed][pos];
	if (ret != -1)
		return ret;
	ret = OO;
	ret = min(ret, solve(missed + 1, 2 * pos, offset) + solve(missed + 1, 2 * pos + 1, offset));
	ret = min(ret, solve(missed, 2 * pos, offset) + solve(missed, 2 * pos + 1, offset) + cost[pos]);
	return ret;
}
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int p;
		cin >> p;
		int n = 1 << p;
		VI M(n);
		for (int i=0; i<n; i++)
			cin >> M[i];
		vector<VI> w;
		for (int j=0, k=n; j<p; j++)
		{
			k /= 2;
			VI v;
			for (int t=0; t<k; t++)
			{
				int tmp;
				cin >> tmp;
				v.push_back(tmp);
			}
			w.push_back(v);
		}
		reverse(w.begin(), w.end());
		int offset = 1;
		for (int i=0; i<p; i++)
			FORIT(it, w[i])
			{
				cost[offset] = *it;
				offset++;
			}
		int o = offset;
		FORIT(it, M)
		{
			cost[offset] = *it;
			offset++;
		}
		printf("Case #%d: ", tkase+1);
		for (int i=0; i<16; i++)
			for (int j=0; j<16*1024; j++)
				dp[i][j] = -1;
		cout << solve(0, 1, o) << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
