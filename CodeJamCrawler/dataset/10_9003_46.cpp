// GCJ Round 3 2010 -- Sat Jun 12 2010
// Problem C
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
const int M = 1000000;
int a[4 * M];
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int p;
		cin >> p;
		memset(a, 0, sizeof a);
		priority_queue<PII> pq;
		for (int i=0; i<p; i++)
		{
			int pos, cnt;
			cin >> pos >> cnt;
			pos += 2 * M;
			a[pos] += cnt;
			if (a[pos] >= 2)
				pq.push(PII(a[pos], pos));
		}
		LL res = 0;
		while (!pq.empty())
		{
			PII act = pq.top();
			pq.pop();
			if (a[act.second] <= 1)
				continue;
			int r = a[act.second] / 2;
			a[act.second + 1] += r;
			a[act.second - 1] += r;
			res += r;
			a[act.second] %= 2;
			if (a[act.second + 1] >= 2)
				pq.push(PII(a[act.second + 1], act.second + 1));
			if (a[act.second - 1] >= 2)
				pq.push(PII(a[act.second - 1], act.second - 1));
		}
		printf("Case #%d: ", tkase+1);
		cout << res << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
