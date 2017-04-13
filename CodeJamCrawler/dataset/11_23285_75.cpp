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

#define MAXN 10

typedef vector<int> vi;

int n, m;
int u[MAXN];
int v[MAXN];

int wall[MAXN][MAXN];

int rn;
vi rooms[MAXN];

int nip[MAXN];
int best;
int bnip[MAXN];

void check(int q) {
	int all = (1 << q) - 1;
	for (int i = 0; i < rn; ++i) {
		int m = 0;
		for (int j = 0, jj = rooms[i].size(); j < jj; ++j)
			m |= 1 << nip[rooms[i][j]];
		if (m != all)
			return;
	}
	if (q > best) {
		best = q;
		copy(nip, nip + n, bnip);
	}
}

void rec(int i, int q) {
	if (i == n) {
		check(q);
		return;
	}
	for (nip[i] = 0; nip[i] < q; ++nip[i])
		rec(i + 1, q);
	nip[i] = q;
	rec(i + 1, q + 1);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &u[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &v[i]);
	fill(wall[0], wall[MAXN], -1);
	wall[0][n-1] = 0;
	for (int i = 1; i < n; ++i)
		wall[i][i-1] = 0;
	for (int i = 0; i < m; ++i) {
		--u[i], --v[i];
		wall[u[i]][v[i]] = 0;
		wall[v[i]][u[i]] = 0;
	}
	for (int i = 0; i < n; ++i) {
		vi ne(1, (i + 1) % n);
		for (int j = i + 2; j < n; ++j)
			if (wall[i][j] >= 0)
				ne.push_back(j);
		for (int j = 0; j < i; ++j)
			if (wall[i][j] >= 0)
				ne.push_back(j);
		for (int j = 1, jj = ne.size(); j < jj; ++j)
			wall[ne[j-1]][i] = ne[j];
	}
	rn = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) if (wall[i][j] >= 0) {
			vi &room = rooms[rn++];
			room.assign(1, j);
			int a = i, b = j, c = wall[i][j];
			wall[i][j] = -1;
			while (c != j) {
				a = b;
				b = c;
				c = wall[a][b];
				wall[a][b] = -1;
				room.push_back(b);
			}
		}
	best = 0;
	rec(0, 0);
	printf("%d\n", best);
	for (int i = 0; i < n; ++i)
		printf("%d%c", bnip[i] + 1, i + 1 < n ? ' ' : '\n');
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
