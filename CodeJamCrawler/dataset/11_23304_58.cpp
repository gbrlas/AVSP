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

#define FILE_IN  "D-large.in"
#define FILE_OUT "D-large.out"

#define MAXP 404
#define LOTS 0x3fffffff

int p;
bool wh[MAXP][MAXP];
int dist[MAXP];
int th[MAXP][MAXP][MAXP];
int mt;

void dists() {
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while (dist[1] == LOTS && !q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < p; ++i) if (dist[i] == LOTS && wh[x][i]) {
			dist[i] = dist[x] + 1;
			q.push(i);
		}
	}
	for (int i = 2; i < p; ++i)
		if (dist[i] >= dist[1])
			dist[i] = LOTS;
}

void threats() {
	queue<int> q;
	q.push(0); q.push(0); q.push(0);
	th[0][0][0] = 0;
	while (!q.empty()) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		int c = q.front(); q.pop();
		int &r = th[a][b][c];
		for (int i = 0; i < p; ++i) if (wh[c][i])
			if ((b == c || (i != b && !wh[b][i])) && (a == b || (i != a && !wh[a][i])))
				++r;
		if (wh[c][1]) {
			mt = max(mt, r);
			continue;
		}
		for (int i = 0; i < p; ++i) if (wh[c][i] && dist[i] == dist[c] + 1) {
			bool qq = th[b][c][i] < 0;
			th[b][c][i] = max(th[b][c][i], r - 1);
			if (qq) {
				q.push(b); q.push(c); q.push(i);
			}
		}
	}
}

void solve() {
	fill(wh[0], wh[MAXP], false);
	fill(dist, dist + MAXP, LOTS);
	fill(th[0][0], th[MAXP][0], -1);
	mt = 0;
	int w;
	scanf("%d%d", &p, &w);
	for (int i = 0; i < w; ++i) {
		int a, b;
		scanf(" %d,%d", &a, &b);
		wh[a][b] = wh[b][a] = true;
	}
	dists();
	threats();
	printf("%d %d\n", dist[1] - 1, mt);
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
