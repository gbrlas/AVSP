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

#define FILE_IN  "B-small-attempt0.in"
#define FILE_OUT "B-small-attempt0.out"

#define MAXV 10004

int cnt[MAXV];
int diff[MAXV];

void solve() {
	int n;
	scanf("%d", &n);
	fill(cnt, cnt + MAXV, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	for (int i = 1; i < MAXV; ++i)
		diff[i] = cnt[i] - cnt[i-1];
	int pos = 0, neg = 0;
	int res = n ? MAXV : 0;
	while (neg < MAXV) {
		while (pos < MAXV && diff[pos] <= 0)
			++pos;
		while (neg < MAXV && diff[neg] >= 0)
			++neg;
		if (pos >= MAXV || neg >= MAXV)
			break;
		res = min(res, neg - pos);
		--diff[pos];
		++diff[neg];
	}
	printf("%d\n", res);
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
