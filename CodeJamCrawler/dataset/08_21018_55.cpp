#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXM 10010
#define LEFT(x) (2*(x))
#define RIGHT(x) (LEFT(x)+1)
#define LOTS 0x3fffffff

int dp[MAXM][2];
bool ir[MAXM];
bool keiciam[MAXM];
int m;

bool read() {
	fill(dp[0], dp[MAXM], -2);
	int v;
	scanf("%d%d", &m, &v);
	for (int i = 1; i <= (m-1)/2; ++i) {
		int g, c;
		scanf("%d%d", &g, &c);
		ir[i] = g == 1;
		keiciam[i] = c == 1;
	}
	for (int i = 0, j = (m+1)/2; i < (m+1)/2; ++i, ++j) {
		int v;
		scanf("%d", &v);
		dp[j][v] = 0;
		dp[j][!v] = -1;
	}
	return v;
}

int get(int m, bool v) {
	if (dp[m][v] >= -1)
		return dp[m][v];
	int res = LOTS;
	if (v) {
		if (ir[m]) {
			int a1 = get(LEFT(m), 1);
			int b1 = get(RIGHT(m), 1);
			if (a1 >= 0 && b1 >= 0)
				res = min(res, a1 + b1);
			if (keiciam[m]) {
				int a0 = get(LEFT(m), 0);
				int b0 = get(RIGHT(m), 0);
				if (a1 >= 0 && b0 >= 0)
					res = min(res, a1 + b0 + 1);
				if (a0 >= 0 && b1 >= 0)
					res = min(res, a0 + b1 + 1);
			}
		}
		else {
			int a0 = get(LEFT(m), 0);
			int b0 = get(RIGHT(m), 0);
			int a1 = get(LEFT(m), 1);
			int b1 = get(RIGHT(m), 1);
			if (a1 >= 0 && b1 >= 0)
				res = min(res, a1 + b1);
			if (a0 >= 0 && b1 >= 0)
				res = min(res, a0 + b1);
			if (a1 >= 0 && b0 >= 0)
				res = min(res, a1 + b0);
		}
	}
	else {
		if (ir[m]) {
			int a0 = get(LEFT(m), 0);
			int b0 = get(RIGHT(m), 0);
			int a1 = get(LEFT(m), 1);
			int b1 = get(RIGHT(m), 1);
			if (a1 >= 0 && b0 >= 0)
				res = min(res, a1 + b0);
			if (a0 >= 0 && b0 >= 0)
				res = min(res, a0 + b0);
			if (a0 >= 0 && b1 >= 0)
				res = min(res, a0 + b1);
		}
		else {
			int a0 = get(LEFT(m), 0);
			int b0 = get(RIGHT(m), 0);
			if (a0 >= 0 && b0 >= 0)
				res = min(res, a0 + b0);
			if (keiciam[m]) {
				int a1 = get(LEFT(m), 1);
				int b1 = get(RIGHT(m), 1);
				if (a1 >= 0 && b0 >= 0)
					res = min(res, a1 + b0 + 1);
				if (a0 >= 0 && b1 >= 0)
					res = min(res, a0 + b1 + 1);
			}
		}
	}
	if (res == LOTS)
		res = -1;
	return dp[m][v] = res;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		bool v = read();
		int r = get(1, v);
		printf("Case #%d: ", i);
		if (r < 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", r);
	}
	return 0;
}
