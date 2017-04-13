// GCJ Round 3 2010 -- Sat Jun 12 2010
// Problem D
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
const int MOD = 1000000007;
const int N = 80;
LL bin[N][N];
LL factorial[N];
void init_binomial()
{
	for (int i=0; i<N; i++)
	{
		bin[i][0] = bin[i][i] = 1;
		for (int j=1; j<i; j++)
		{
			bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
			bin[i][j] %= MOD;
		}
	}
	factorial[0] = 1;
	for (int i=1; i<N; i++)
	{
		factorial[i] = factorial[i-1] * i;
		factorial[i] %= MOD;
	}
}
int B;
vector<vector<LL> > dp;
LL power_mod(LL a, LL b)
{
	if (b == 0)
		return 1 % MOD;
	LL tmp = power_mod(a, b >> 1);
	if (b & 1)
		return (((a * tmp) % MOD) * tmp) % MOD;
	return (tmp * tmp) % MOD;
}
map<LL, LL> mem[75][2][2];
void init_mem()
{
	for (int i=0; i<75; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				mem[i][j][k].clear();
}
int solve(LL r, int digits, bool zero_used, bool force=false)
{
	if (r < 0)
		return 0;
	if (r == 0)
	{
		if (zero_used)
			return 0;
		return 1;
	}
	if (mem[digits][zero_used][force].count(r))
		return mem[digits][zero_used][force][r];
	int m = r % B;
	LL &ret = mem[digits][zero_used][force][r];
	for (int i=1; i<=digits && i<B; i++)
	{
		for (int j=m; j<B*B; j+=B)
			if (dp[i][j])
			{
				if (i != digits && force)
					continue;
				LL r2 = r - j;
				if (r2 < 0)
					continue;
				assert(r2 % B == 0);
				r2 /= B;
				LL tmp = solve(r2, i, false);
				if (zero_used)
				{
					tmp *= i;
					tmp %= MOD;
					tmp *= bin[digits-1][i-1];
					tmp %= MOD;
					tmp *= factorial[i-1];
					tmp %= MOD;
				}
				else
				{
					tmp *= bin[digits][i];
					tmp %= MOD;
					tmp *= factorial[i];
					tmp %= MOD;
				}
				tmp *= dp[i][j];
				tmp %= MOD;
				ret += tmp;
				ret %= MOD;
			}
	}
	for (int i=0; i<digits; i++)
	{
		for (int j=m; j<B*B; j+=B)
			if (dp[i][j])
			{
				if (i + 1 != digits && force)
					continue;
				LL r2 = r - j;
				if (r2 < 0)
					continue;
				r2 /= B;
				LL tmp = solve(r2, i + 1, true);
				if (zero_used)
				{
					tmp *= i + 1;
					tmp %= MOD;
					tmp *= bin[digits-1][i];
					tmp %= MOD;
					tmp *= factorial[i];
					tmp %= MOD;
				}
				else
				{
					tmp *= bin[digits][i+1];
					tmp %= MOD;
					tmp *= factorial[i+1];
					tmp %= MOD;
				}
				tmp *= dp[i][j];
				tmp %= MOD;
				ret += tmp;
				ret %= MOD;
			}
	}
	return ret % MOD;
}
int main()
{
	init_binomial();
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		init_mem();
		LL N;
		cin >> N >> B;
		dp.assign(B, B * B);
		dp[0][0] = 1;
		for (int i=1; i<B; i++)
		{
			for (int ii=B-2; ii>=0; ii--)
				for (int j=0; j+i<B*B; j++)
				{
					dp[ii+1][j+i] += dp[ii][j];
					dp[ii+1][j+i] %= MOD;
				}
		}
		LL res = 0; 
		for (int len=1; len<=B; len++)
		{
			LL tmp = solve(N, len, false, true);
			tmp *= power_mod(factorial[len], MOD-2);
			tmp %= MOD;
			res += tmp;
		}
		res %= MOD;
		printf("Case #%d: ", tkase+1);
		cout << res << endl;
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
