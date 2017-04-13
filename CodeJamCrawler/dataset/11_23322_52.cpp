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

#define FILE_IN  "C-large.in"
#define FILE_OUT "C-large.out"

#define MAXN 102
#define D 8
#define MOD 1000003

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int dr[D] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[D] = {-1, 0, 1, 1, 1, 0, -1, -1};
char ds[D] = {'\\', '|', '/', '-', '\\', '|', '/', '-'};

int norm(int i, int lim) {
	if (i < 0) i += lim;
	if (i >= lim) i -= lim;
	return i;
}

int r, c;
char dir[MAXN][MAXN];
int inc[MAXN][MAXN];
vpii adj[MAXN][MAXN];
bool vis[MAXN][MAXN];

int powm(int a, int p, int m) {
	if (p == 0)
		return 1;
	if (p == 1)
		return a;
	int aa = (long long) a * a % m;
	int x = powm(aa, p / 2, m);
	if (p % 2 == 1)
		x = (long long) x * a % m;
	return x;
}

int solve() {
	fill(inc[0], inc[MAXN], 0);
	fill(adj[0], adj[MAXN], vpii());
	fill(vis[0], vis[MAXN], false);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i)
		scanf(" %s", dir[i]);
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			for (int d = 0; d < D; ++d)
				if (dir[i][j] == ds[d])
					++inc[norm(i+dr[d], r)][norm(j+dc[d], c)];
	queue<int> q;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (inc[i][j] == 0)
				return 0;
			if (inc[i][j] == 1) {
				q.push(i);
				q.push(j);
			}
		}
	while (!q.empty()) {
		int i = q.front(); q.pop();
		int j = q.front(); q.pop();
		int d, ni, nj;
		for (d = 0; d < D; ++d)
			if (dir[ni = norm(i+dr[d], r)][nj = norm(j+dc[d], c)] == ds[d])
				break;
		dir[ni][nj] = 'x';
		int nni = norm(ni+dr[d], r);
		int nnj = norm(nj+dc[d], c);
		--inc[nni][nnj];
		if (inc[nni][nnj] == 0)
			return 0;
		if (inc[nni][nnj] == 1) {
			q.push(nni);
			q.push(nnj);
		}
	}
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (inc[i][j] != 2)
				continue;
			int d1, ni1, nj1;
			int d2, ni2, nj2;
			for (d1 = 0; d1 < D; ++d1)
				if (dir[ni1 = norm(i+dr[d1], r)][nj1 = norm(j+dc[d1], c)] == ds[d1])
					break;
			for (d2 = d1 + 1; d2 < D; ++d2)
				if (dir[ni2 = norm(i+dr[d2], r)][nj2 = norm(j+dc[d2], c)] == ds[d2])
					break;
			adj[ni1][nj1].push_back(pii(ni2, nj2));
			adj[ni2][nj2].push_back(pii(ni1, nj1));
		}
	int cc = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			if (dir[i][j] == 'x' || vis[i][j])
				continue;
			vis[i][j] = true;
			int ii = adj[i][j][0].first;
			int jj = adj[i][j][0].second;
			int pi = i, pj = j;
			while (ii != i || jj != j) {
				vis[ii][jj] = true;
				pii next;
				if (adj[ii][jj][0] == pii(pi, pj))
					next = adj[ii][jj][1];
				else
					next = adj[ii][jj][0];
				pi = ii, pj = jj;
				ii = next.first;
				jj = next.second;
			}
			++cc;
		}
	return powm(2, cc, MOD);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		printf("%d\n", solve());
	}
	return 0;
}
