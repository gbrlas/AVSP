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

#define FILE_IN  "C-small-attempt1.in"
#define FILE_OUT "C-small-attempt1.out"

#define MAXN 5

int r, c;
int board[MAXN][MAXN];
bool mine[MAXN][MAXN];
int best;

void rec(int i, int j) {
	if (i == r) {
		for (int k = 0; k < c; ++k)
			if (board[i-1][k] > 0)
				return;
		int cc = 0;
		for (int k = 0; k < c; ++k)
			if (mine[r/2][k])
				++cc;
		best = max(best, cc);
		return;
	}
	if (j == c) {
		if (i > 0) {
			for (int k = 0; k < c; ++k)
				if (board[i-1][k] > 0)
					return;
		}
		rec(i+1, 0);
		return;
	}
	bool g = 1;
	for (int q = max(i-1, 0); q <= min(i+1, r-1); ++q)
		for (int w = max(j-1, 0); w <= min(j+1, c-1); ++w)
			if (--board[q][w] < 0)
				g = 0;
	mine[i][j] = 1;
	if (g)
		rec(i, j+1);
	mine[i][j] = 0;
	for (int q = max(i-1, 0); q <= min(i+1, r-1); ++q)
		for (int w = max(j-1, 0); w <= min(j+1, c-1); ++w)
			++board[q][w];
	rec(i, j+1);
}

void solve() {
	best = 0;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			scanf("%d", &board[i][j]);
	fill(mine[0], mine[MAXN], 0);
	rec(0, 0);
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
