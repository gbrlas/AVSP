#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned long UL;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;

#define INT_MIN		-2147483648
#define INT_MAX		2147483647  
#define LLONG_MAX	9223372036854775807LL
#define LLONG_MIN	-9223372036854775808LL

#define foreach(it,c) for (it=(c).begin(); it!=(c).end(); it++)

const int MMAX = 11000;
const int INF = 20000;
int m, v;
int g[MMAX], c[MMAX];
int inner;
int dp[2][MMAX];

void dfs(int pos)
{
	int l = pos<<1;
	int r = l + 1;
	if (pos <= inner)
	{
		dfs(l);
		dfs(r);
		if (g[pos] == 1)
		{
			dp[1][pos] = dp[1][l] + dp[1][r];
			int tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = min(tmp, dp[0][l]+dp[0][r]);
			dp[0][pos] = tmp;

			if (c[pos] == 1)
			{
				tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = min(tmp, dp[1][l] + dp[1][r]);
				dp[1][pos] = min(dp[1][pos], tmp+1);
				dp[0][pos] = min(dp[0][pos], dp[0][l]+dp[0][r]+1);
			}
		}
		else
		{
			int tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
			tmp = min(tmp, dp[1][l] + dp[1][r]);
			dp[1][pos] = tmp;
			dp[0][pos] = dp[0][l] + dp[0][r];

			if (c[pos] == 1)
			{
				dp[1][pos] = min(dp[1][pos], dp[1][l]+dp[1][r]+1);
				tmp = min(dp[1][l]+dp[0][r], dp[0][l]+dp[1][r]);
				tmp = min(tmp, dp[0][l]+dp[0][r]);
				dp[0][pos] = min(dp[0][pos], tmp+1);
			}
		}
	}
	else
	{
		dp[ g[pos] ][pos] = 0;
		dp[ 1-g[pos] ][pos] = INF;
	}

	dp[0][pos] = min(dp[0][pos], INF);
	dp[1][pos] = min(dp[1][pos], INF);
}

int solve()
{
	int i, j;
	
	memset(dp, 0, sizeof(dp));
	dfs(1);
	if (dp[v][1] >= INF)
		return -1;
	return dp[v][1];
}

int main()
{
	int i, j, n;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	cin >> n;
	for (i=1; i<=n; i++)
	{
		cin >> m >> v;
		inner = m >> 1;
		for (j=1; j<=inner; j++)
			cin >> g[j] >> c[j];
		for (; j<=m; j++)
			cin >> g[j];
		int ret = solve();
		if (ret == -1)
			printf("Case #%d: IMPOSSIBLE\n", i);
		else
			printf("Case #%d: %d\n", i, ret);
	}
}
