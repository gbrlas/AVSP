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

#define FILE_IN  "D-small-attempt0.in"
#define FILE_OUT "D-small-attempt0.out"

#define MAXN 40

int X[MAXN];
int Y[MAXN];
int R[MAXN];

double solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &X[i], &Y[i], &R[i]);
	if (n == 1)
		return R[0];
	if (n == 2)
		return max(R[0], R[1]);
	if (n > 3)
		return 0;
	double best = 1e100;
	for (int a = 0; a < n; ++a)
		for (int b = a + 1; b < n; ++b) {
			int c = 3 - a - b;
			best = min(best, max<double>((R[a] + R[b] + hypot(X[a] - X[b], Y[a] - Y[b])) / 2.0, R[c]));
		}
	return best;
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		printf("%.6lf\n", solve());
	}
	return 0;
}
