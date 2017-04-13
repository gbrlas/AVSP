#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int prisoners[110];
int P, Q;
int dp[110][110];
const int HIVAL = 100000000;

int doit(int first, int last)
{
	if(dp[first][last] != -1) return dp[first][last];
	int res = prisoners[last] - 1 - prisoners[first] - 1;
	int lo = HIVAL;
	for(int i = first + 1; i < last; ++i)
	{
		int tlo = doit(first, i) + doit(i, last);
		if(tlo < lo) lo = tlo;
	}
	if(lo == HIVAL) { res = 0; lo = 0; }
	dp[first][last] = lo + res;
	return dp[first][last];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int tests = 1; tests <= T; ++tests)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &P, &Q);
		for(int i = 0; i < Q; ++i)
			scanf("%d", &prisoners[i + 1]);
		prisoners[Q + 1] = P + 1;
		int res = doit(0, Q + 1);
		printf("Case #%d: %d\n", tests, res);
	}

	return 0;
}