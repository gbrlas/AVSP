#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

vector<double> dp;

double calc(int state, int n)
{
	if(dp[state] != -1)
		return dp[state];

	double total = 0;

	if(state == (1 << n) - 1)
		return dp[state] = 0;

	for(int s = 0; s < n; ++s) {

		int e = s;
		while(state & (1 << e))
			e = (e + 1) % n;
		total += (n - (e + n - s) % n);
		total += calc(state | (1 << e), n);
	}

	return dp[state] = total / n;
}

int main()
{
	int casenum;

	scanf("%d", &casenum);

	for(int testcase = 1; testcase <= casenum; ++testcase) {

		char buf[64];

		scanf("%s", buf);
		int n = strlen(buf);
		int initstate = 0;
		for(int i = 0; i < n; ++i) {
			if(buf[i] == 'X')
				initstate = initstate | (1 << i);
		} 

		dp.resize(1 << n);
		fill(dp.begin(), dp.end(), -1);

		double ans = calc(initstate, n);

		printf("Case #%d: %.10lf\n", testcase, ans);
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
