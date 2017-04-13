// GCJ Round 1B 2010 -- Sat May 22 2010
// Problem C
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
const int MOD = 100003;
const int N = 512;
LL bin[N][N];
void init_binomial()
{
	for (int i=0; i<N; i++)
	{
		bin[i][0] = bin[i][i] = 1;
		for (int j=1; j<i; j++)
			bin[i][j] = bin[i-1][j-1] + bin[i-1][j] % MOD;
	}
}
LL mem[512][512];
int solve(int n, int r)
{
	if (r > n)
		return 0;
	if (r == 1)
		return 1;
	if (mem[n][r] >= 0)
		return mem[n][r];
	// n: rank r
	// r: rank i
	LL ret = 0;
	for (int i=1; i<r; i++)
	{
		ret += bin[r - i -1][n - r - 1] * solve(r, i);
	}
	return mem[n][r] = ret % MOD;
}
int main()
{
	memset(mem, -1, sizeof mem);
	init_binomial();
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int n;
		cin >> n;
		printf("Case #%d: ", tkase+1);
		int sum = 0;
		for (int j=1; j<=n; j++)
		{
			sum += solve(n, j);
			sum %= MOD;
		}
		cout << sum << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
