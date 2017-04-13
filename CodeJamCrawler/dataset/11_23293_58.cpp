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

#define FILE_IN  "A-large.in"
#define FILE_OUT "A-large.out"

#define MAXN 1002

typedef pair<int, int> pii;

int X, S, R, Tr, N;
int B[MAXN];
int E[MAXN];
int W[MAXN];

pii ww[MAXN];

void solve() {
	scanf("%d%d%d%d%d", &X, &S, &R, &Tr, &N);
	int p = 0;
	int Dw = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &B[i], &E[i], &W[i]);
		ww[i] = pii(W[i], E[i] - B[i]);
		Dw += B[i] - p;
		p = E[i];
	}
	Dw += X - p;
	ww[N] = pii(0, Dw);
	sort(ww, ww + N + 1);
	double Tl = Tr;
	double Tt = 0;
	for (int i = 0; i <= N; ++i) {
		int w = ww[i].first;
		int d = ww[i].second;
		double Tm = (double) d / (w + R);
		double tr = min(Tm, Tl);
		Tt += (double) (d - tr * (R - S)) / (w + S);
		Tl -= tr;
	}
	printf("%.8lf\n", Tt);
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
