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

#define MAXN 102
#define MAXM (2 * MAXN)
#define E 1e-9

int w, ln, un, g;
int lx[MAXN], ly[MAXN];
int ux[MAXN], uy[MAXN];

int m;
int x[MAXM];
double h[MAXM];

double get(double a) {
	for (int i = 0; i + 1 < m; ++i) {
		double ap = (double) (h[i] + h[i + 1]) / 2 * (x[i + 1] - x[i]);
		if (a >= ap) {
			a -= ap;
			continue;
		}
		if (a < E)
			return x[i];
		double hh = (h[i + 1] - h[i]) / (x[i + 1] - x[i]);
		double d = h[i] * h[i] + 2 * a * hh;
		return x[i] + (sqrt(d) - h[i]) / hh;
	}
	return x[m - 1];
}

void solve() {
	scanf("%d%d%d%d", &w, &ln, &un, &g);
	for (int i = 0; i < ln; ++i)
		scanf("%d%d", &lx[i], &ly[i]);
	for (int i = 0; i < un; ++i)
		scanf("%d%d", &ux[i], &uy[i]);
	m = 0;
	for (int i = 0; i < ln; ++i)
		x[m++] = lx[i];
	for (int i = 0; i < un; ++i)
		x[m++] = ux[i];
	sort(x, x + m);
	m = unique(x, x + m) - x;
	for (int i = 0, ui = 0; ui + 1 < un; ++ui) {
		while (x[i] < ux[ui + 1]) {
			h[i] = (double) (uy[ui + 1] - uy[ui]) * (x[i] - ux[ui]) / (ux[ui + 1] - ux[ui]) + uy[ui];
			++i;
		}
	}
	h[m - 1] = uy[un - 1];
	for (int i = 0, li = 0; li + 1 < ln; ++li) {
		while (x[i] < lx[li + 1]) {
			h[i] -= (double) (ly[li + 1] - ly[li]) * (x[i] - lx[li]) / (lx[li + 1] - lx[li]) + ly[li];
			++i;
		}
	}
	h[m - 1] -= ly[ln - 1];
	double area = 0;
	for (int i = 0; i + 1 < m; ++i)
		area += (double) (h[i] + h[i + 1]) / 2 * (x[i + 1] - x[i]);
	for (int i = 1; i < g; ++i)
		printf("%.8lf\n", get(area * i / g));
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;
}
