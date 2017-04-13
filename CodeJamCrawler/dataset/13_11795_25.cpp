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
const int size = 37;

int64 calcCost(int right, int64 low, vector<int64> &x)
{
	int64 ret = 0;

	for(int i = 0; i <= right; ++i)
		ret += low - x[i];
	for(int i = right + 1; i < size; ++i)
		ret += max((low + 1) - x[i], 0LL);

	return ret;
}

double calcExpected(int right, int64 low, vector<int64> &x)
{
	double ret = 0;

	for(int i = 0; i <= right; ++i)
		ret += (low - x[i]) * (double)(size - 1);
	ret = ret / (right + 1);

	return ret;
}

int64 calcMax(int right, int64 budget, vector<int64> &x)
{
	int64 lb = x[right], ub = (int64)1e16;

	while(ub - lb > 1) {

		int64 mid = (ub + lb) / 2;
		if(calcCost(right, mid, x) <= budget)
			lb = mid;
		else
			ub = mid;
	}

	return lb;
}

double calc(int right, int64 budget, vector<int64> &x)
{
	int64 low = x[right];
	double ans = 0;
	vector<int64> val;

	for(int i = right; i < size; ++i)
		val.push_back(x[i]);
	for(int i = right + 1; i < size; ++i)
		val.push_back(x[i] - 1);
	val.push_back(calcMax(right, budget, x));

	for(int i = 0; i < val.size(); ++i) {
		double expected = calcExpected(right, val[i], x);
		int64 cost = calcCost(right, val[i], x);
		if(cost <= budget)
			ans = max(ans, expected - cost);
	}

	return ans;
}

int main()
{
	int casenum;

	scanf("%d", &casenum);

	for(int testcase = 1; testcase <= casenum; ++testcase) {

		int64 budget;
		int n;
		vector<int64> x;

		scanf("%lld%d", &budget, &n);
		x.resize(size);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &x[i]);
		for(int i = n; i < size; ++i)
			x[i] = 0LL;

		sort(x.begin(), x.end());

		double ans = 0;

		for(int i = 0; i < size; ++i)
			ans = max(ans, calc(i, budget, x));

		printf("Case #%d: %.8lf\n", testcase, ans);
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
