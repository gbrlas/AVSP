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

#define FILE_IN  "B-small-attempt3.in"
#define FILE_OUT "B-small-attempt3.out"

struct DS {
	vector<int> parent;
	vector<int> bits;
	DS(int n): parent(n), bits(n, 0) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}
	int getParent(int i) {
		stack<int> S;
		while (i != parent[i]) {
			S.push(i);
			i = parent[i];
		}
		while (!S.empty()) {
			parent[S.top()] = i;
			S.pop();
		}
		return i;
	}
	void join(int i, int j) {
		int pi = getParent(i);
		int pj = getParent(j);
		if (pi == pj) return;
		bits[pi] = bits[pj] = bits[pi] | bits[pj];
		if (rand() & 1)
			parent[pi] = pj;
		else
			parent[pj] = pi;
	}
};

int nbits(int x) {
	int c = 0;
	while (x) {
		c += x & 1;
		x >>= 1;
	}
	return c;
}

#define D 6
int dr[D] = {0, 1, 1, 0, -1, -1};
int dc[D] = {1, 1, 0, -1, -1, 0};

#define LOTS 0x3fffffff

#define MAXS 50
#define MAXM 100

int s, m;

int dsi[2*MAXS][2*MAXS];
int dsr[4*MAXS*MAXS];
int dsc[4*MAXS*MAXS];

bool stone[2*MAXS][2*MAXS];

int mr[MAXM];
int mc[MAXM];

bool debug = false;

void solve() {
	scanf("%d%d", &s, &m);
	if (debug) printf("%d %d\n", s, m);
	int ss = 2 * s - 1;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &mr[i], &mc[i]);
		if (debug) printf("%d %d\n", mr[i], mc[i]);
	}
	fill(dsi[0], dsi[2*s], -1);
	fill(stone[0], stone[2*s], false);
	int dsn = 0;
	for (int i = 1; i <= ss; ++i)
		for (int j = max(i - s + 1, 1), jj = min(i + s - 1, ss); j <= jj; ++j) {
			dsr[dsn] = i;
			dsc[dsn] = j;
			dsi[i][j] = dsn++;
		}
	DS dd(dsn), ddd(dsn);
	dd.bits[dsi[1][1]] |= 1;
	dd.bits[dsi[1][s]] |= 1 << 1;
	dd.bits[dsi[s][ss]] |= 1 << 2;
	dd.bits[dsi[ss][ss]] |= 1 << 3;
	dd.bits[dsi[ss][s]] |= 1 << 4;
	dd.bits[dsi[s][1]] |= 1 << 5;
	ddd.bits[dsi[1][1]] |= 1;
	ddd.bits[dsi[1][s]] |= 1;
	ddd.bits[dsi[s][ss]] |= 1;
	ddd.bits[dsi[ss][ss]] |= 1;
	ddd.bits[dsi[ss][s]] |= 1;
	ddd.bits[dsi[s][1]] |= 1;
	for (int i = 2; i < s; ++i) {
		dd.bits[dsi[1][i]] |= 1 << 6;
		dd.bits[dsi[i][i + s - 1]] |= 1 << 7;
		dd.bits[dsi[i + s - 1][ss]] |= 1 << 8;
		dd.bits[dsi[ss][i + s - 1]] |= 1 << 9;
		dd.bits[dsi[i + s - 1][i]] |= 1 << 10;
		dd.bits[dsi[i][1]] |= 1 << 11;
		ddd.bits[dsi[1][i]] |= 1;
		ddd.bits[dsi[i][i + s - 1]] |= 1;
		ddd.bits[dsi[i + s - 1][ss]] |= 1;
		ddd.bits[dsi[ss][i + s - 1]] |= 1;
		ddd.bits[dsi[i + s - 1][i]] |= 1;
		ddd.bits[dsi[i][1]] |= 1;
	}
	int bridge = LOTS;
	int fork = LOTS;
	for (int i = 0; i < m; ++i) {
		int ii = dsi[mr[i]][mc[i]];
		stone[mr[i]][mc[i]] = true;
		for (int d = 0; d < D; ++d) {
			int rr = mr[i] + dr[d];
			int cc = mc[i] + dc[d];
			if (rr < 1 || rr > ss || cc < 1 || cc > ss || dsi[rr][cc] < 0)
				continue;
			if (!stone[rr][cc])
				continue;
			dd.join(ii, dsi[rr][cc]);
		}
		int bm = dd.bits[dd.getParent(ii)];
		if (bridge == LOTS && nbits(bm & 077) >= 2)
			bridge = i + 1;
		if (fork == LOTS && nbits((bm >> 6) & 077) >= 3)
			fork = i + 1;
	}
	for (int i = 0; i < dsn; ++i) {
		if (stone[dsr[i]][dsc[i]])
			continue;
		for (int d = 0; d < D; ++d) {
			int rr = dsr[i] + dr[d];
			int cc = dsc[i] + dc[d];
			if (rr < 1 || rr > ss || cc < 1 || cc > ss || dsi[rr][cc] < 0)
				continue;
			if (stone[rr][cc])
				continue;
			ddd.join(i, dsi[rr][cc]);
		}
	}
	int ring = LOTS;
	for (int i = 0; i < dsn; ++i) {
		if (stone[dsr[i]][dsc[i]])
			continue;
		if (!ddd.bits[ddd.getParent(i)])
			ring = m;
	}
	for (int i = m-1; i >= 0; --i) {
		int ii = dsi[mr[i]][mc[i]];
		stone[mr[i]][mc[i]] = false;
		int before = 0, after = 0;
		for (int d = 0; d < D; ++d) {
			int rr = mr[i] + dr[d];
			int cc = mc[i] + dc[d];
			if (rr < 1 || rr > ss || cc < 1 || cc > ss || dsi[rr][cc] < 0)
				continue;
			if (stone[rr][cc])
				continue;
			if (ddd.bits[ddd.getParent(dsi[rr][cc])])
				++before;
		}
		for (int d = 0; d < D; ++d) {
			int rr = mr[i] + dr[d];
			int cc = mc[i] + dc[d];
			if (rr < 1 || rr > ss || cc < 1 || cc > ss || dsi[rr][cc] < 0)
				continue;
			if (stone[rr][cc])
				continue;
			ddd.join(ii, dsi[rr][cc]);
		}
		for (int d = 0; d < D; ++d) {
			int rr = mr[i] + dr[d];
			int cc = mc[i] + dc[d];
			if (rr < 1 || rr > ss || cc < 1 || cc > ss || dsi[rr][cc] < 0)
				continue;
			if (stone[rr][cc])
				continue;
			if (ddd.bits[ddd.getParent(dsi[rr][cc])])
				++after;
		}
		if (debug && !ddd.bits[ddd.getParent(ii)])
			printf(">> %d %d\n", mr[i], mc[i]);
		if (before < after)
			ring = i + 1;
		if (!ddd.bits[ddd.getParent(ii)])
			ring = i;
	}
	int win = min(bridge, min(fork, ring));
	if (bridge > win) bridge = LOTS;
	if (fork > win) fork = LOTS;
	if (ring > win) ring = LOTS;
	bool dash = false;
	if (bridge < LOTS) {
		printf("bridge");
		dash = true;
	}
	if (fork < LOTS) {
		if (dash) printf("-");
		printf("fork");
		dash = true;
	}
	if (ring < LOTS) {
		if (dash) printf("-");
		printf("ring");
	}
	if (win < LOTS) {
		printf(" in move %d\n", win);
	} else {
		printf("none\n");
	}
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
		fprintf(stderr, "done %d\n", i);
		fflush(stderr);
	}
	return 0;
}
