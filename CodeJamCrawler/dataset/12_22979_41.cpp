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

#define FILE_IN  "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"

#define MAXN 2000
#define MAXH 1000000000

int x[MAXN], rx[MAXN];
int h[MAXN], d[MAXN];

void solve() {
	int n;
	scanf("%d", &n);
	fill(rx, rx + n, 0);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", &x[i]);
		--x[i];
		++rx[x[i]];
	}
	h[n-1] = MAXH;
	d[n-1] = 0;
	stack<int> S;
	S.push(n-1);
	for (int i = n-2; i >= 0; --i) {
		while (!S.empty() && S.top() != x[i])
			S.pop();
		if (S.empty()) {
			printf(" Impossible\n");
			return;
		}
		S.push(i);
		h[i] = h[x[i]] - d[x[i]] * (x[i] - i);
		d[i] = d[x[i]];
		if (--rx[x[i]]) { --h[i]; ++d[i]; }
		if (h[i] < 0) { printf(" FAIL!!!\n"); return; }
	}
	for (int i = 0; i < n; ++i)
		printf(" %d", h[i]);
	printf("\n");
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}
