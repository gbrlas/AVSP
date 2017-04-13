#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "E-small-attempt0.in"
#define FILE_OUT "E-small-attempt0.out"

#define MAXN 15

int mon, days;
char cal[MAXN][MAXN];
int hap[MAXN][MAXN][1<<MAXN];

int calc(int m, int d, int bm) {
	if (m < 0) return bm ? -1 : 0;
	if (d < 0) return calc(m-1, days-1, bm);
	int &r = hap[m][d][bm];
	if (r >= -1)
		return r;
	r = -1;
	if ((bm & 1) && cal[m][d] != '.') {
		int c = d ? ((bm >> 1) & 1) : 0;
		int p1 = calc(m, d-1, bm >> 1);
		if (p1 >= 0)
			p1 += 4 - 2 * c;
		int p2 = calc(m, d-1, (bm >> 1) | (1 << (days - 1)));
		if (p2 >= 0)
			p2 += 2 - 2 * c;
		r = max(p1, p2);
	} else if (!(bm & 1) && cal[m][d] != '#') {
		int p1 = calc(m, d-1, bm >> 1);
		int p2 = calc(m, d-1, (bm >> 1) | (1 << (days - 1)));
		r = max(p1, p2);
	}
	return r;
}

void solve() {
	fill(hap[0][0], hap[MAXN][0], -2);
	scanf("%d%d", &mon, &days);
	for (int i = 0; i < mon; ++i)
		for (int j = 0; j < days; ++j)
			scanf(" %c", &cal[i][j]);
	int best = 0;
/*	for (int i = mon; i <= mon; ++i)
		for (int j = -1; j < 0; ++j)
			for (int k = 0; k < (1 << days); ++k)
				printf("%d %d %x => %d\n", i, j, k, calc(i, j, k));*/
	for (int i = 0; i < (1 << days); ++i) {
		best = max(best, calc(mon, -1, i));
	}
	printf("%d\n", best);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
