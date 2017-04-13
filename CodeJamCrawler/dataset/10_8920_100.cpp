// GCJ Round 1B 2010 -- Sat May 22 2010
// Problem A
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
map<string, int> mp;
void insert(string s, int v)
{
	if (s.empty())
		return;
	mp[s] = v;
	while (1)
	{
		int n = s.size();
		bool done = s[n-1] == '/';
		s.resize(n-1);
		if (done)
			break;
	}
	insert(s, v);
}
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		mp.clear();
		int n, m;
		cin >> n >> m;
		VS exist(n), mkdir(m);
		for (int i=0; i<n; i++)
			cin >> exist[i];
		for (int i=0; i<m; i++)
			cin >> mkdir[i];
		FORIT(it, mkdir)
			insert(*it, 1);
		FORIT(it, exist)
			insert(*it, 0);
		int ret = 0;
		FORIT(it, mp)
			ret += it->second;
		printf("Case #%d: ", tkase+1);
		cout << ret << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
