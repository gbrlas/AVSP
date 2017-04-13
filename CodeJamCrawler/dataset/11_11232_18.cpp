// GCJ_A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
using namespace std;
typedef int (*CMP)(const void*, const void*);
int x, s, r, t, n;
int in[1010][3];
int d[2020], dn;
map<int, int> hh;
double dp[2020];
int path[2020];
int sum[1000];
int cmp(int *a, int *b) {
	return a[1] - b[1];
}

void init() {
	set<int> tmp;
	tmp.clear();
	tmp.insert(0);
	tmp.insert(x);
	for(int i = 0; i < n; ++i) {
		if(tmp.find(in[i][0]) == tmp.end()) tmp.insert(in[i][0]);
		if(tmp.find(in[i][1]) == tmp.end()) tmp.insert(in[i][1]);
	}
	dn = 0;
	hh.clear();
	for(set<int>::iterator i = tmp.begin(); i != tmp.end(); ++i) {
		hh[*i] = dn;
		d[dn++] = *i;
	}
}

double solve() {
	init();
	qsort(in, n, sizeof(in[0]), (CMP)cmp);
	memset(dp, 0, sizeof(dp));
	memset(path, -1, sizeof(path));
	for(int i = 1; i < dn; ++i) {
		dp[i] = dp[i - 1] + 1.0 * (d[i] - d[i - 1]) / s;
		for(int j = 0; j < n; ++j) {
			if(in[j][1] > d[i]) break;
			double tmp = dp[hh[in[j][0]]] + 1.0 * (in[j][1] - in[j][0]) / (in[j][2] + s) + 1.0 * (d[i] - in[j][1]) / s;
			if(tmp < dp[i]) {
				dp[i] = tmp;
				path[i] = j;
			}
		}
	}

	memset(sum, 0, sizeof(sum));
	int i = dn - 1;
	while(i > 0) {
		if(path[i] < 0) {
			sum[0] += (d[i] - d[i - 1]);
			--i;
		} else {
			int j = path[i];
			sum[0] += (d[i] - in[j][1]);
			sum[in[j][2]] += (in[j][1] - in[j][0]);
			i = hh[in[j][0]];
		}
	}
	double ans = 0.0, tt = t;
	for(int i = 0; i < 300; ++i) {
		if(sum[i] == 0) continue;
		double dt = 1.0 * sum[i] / (i + r);
		if(dt > tt) dt = tt;
		ans += dt + (1.0 * sum[i] - dt * (i + r)) / (i + s);
		tt -= dt;
	}
	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for(int tt = 0; tt < T; ++tt) {
		scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
		for(int i = 0; i < n; ++i) scanf("%d %d %d", in[i], in[i] + 1, in[i] + 2);
		printf("Case #%d: %lf\n", tt + 1, solve());
	}
	return 0;
}

