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

#define FILE_IN  "A-small-attempt0.in"
#define FILE_OUT "A-small-attempt0.out"

#define MAXN 12

int n;
int A[MAXN], B[MAXN], C[MAXN];

int check(int a, int b, int c) {
	int g = 0;
	for (int i = 0; i < n; ++i) {
		if (a >= A[i] && b >= B[i] && c >= C[i])
			++g;
	}
	return g;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
	int best = 0;
	for (int a = 0; a <= 10000; ++a)
		for (int b = 0; a + b <= 10000; ++b)
			best = max(best, check(a, b, 10000 - a - b));
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
