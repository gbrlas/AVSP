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

#define FILE_IN  "B-small-attempt1.in"
#define FILE_OUT "B-small-attempt1.out"

#define MAXN 505

int R, C;
int mass[MAXN][MAXN];
int sum[MAXN][MAXN];

int get_sum(int i1, int i2, int j1, int j2) {
	return sum[i2][j2] - sum[i2][j1] - sum[i1][j2] + sum[i1][j1];
}
int get_row(int i, int j1, int j2) { return get_sum(i, i + 1, j1, j2); }
int get_col(int i1, int i2, int j) { return get_sum(i1, i2, j, j + 1); }

bool can_do(int n) {
	for (int i = 0; i + n <= R; ++i)
		for (int j = 0; j + n <= C; ++j) {
			int top = 0, bottom = 0, left = 0, right = 0;
			for (int k = 0, v = n / 2; k < n / 2; ++k, --v) {
				top += get_row(i + k, j, j + n) * v;
				bottom += get_row(i + n - k - 1, j, j + n) * v;
				left += get_col(i, i + n, j + k) * v;
				right += get_col(i, i + n, j + n - k - 1) * v;
			}
			top -= (mass[i][j] + mass[i][j+n-1]) * (n / 2);
			bottom -= (mass[i+n-1][j] + mass[i+n-1][j+n-1]) * (n / 2);
			left -= (mass[i][j] + mass[i+n-1][j]) * (n / 2);
			right -= (mass[i][j+n-1] + mass[i+n-1][j+n-1]) * (n / 2);
			if (top == bottom && left == right)
				return true;
		}
	return false;
}

void solve() {
	scanf("%d%d%*d", &R, &C);
	for (int i = 0; i < R; ++i) {
		char line[MAXN];
		scanf(" %s", line);
		for (int j = 0; j < C; ++j)
			mass[i][j] = line[j] - '0';
	}
	for (int j = 0; j <= C; ++j)
		sum[0][j] = 0;
	for (int i = 1; i <= R; ++i) {
		sum[i][0] = 0;
		for (int j = 1; j <= C; ++j)
			sum[i][j] = sum[i][j-1] + mass[i-1][j-1];
	}
	for (int i = 1; i <= R; ++i)
		for (int j = 0; j <= C; ++j)
			sum[i][j] += sum[i-1][j];
	for (int s = min(R, C); s >= 3; --s)
		if (can_do(s)) {
			printf("%d\n", s);
			return;
		}
	printf("IMPOSSIBLE\n");
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
