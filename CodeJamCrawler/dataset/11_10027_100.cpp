#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>
#include <memory.h>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include <iostream>
#include <sstream>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define X first
#define Y second

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 110;
const int L = 100;

int n, pos[MAXN], who[MAXN];
int d[MAXN][MAXN][MAXN];
queue<int> qx, qy, qv;

void read() {
	cin >> n;
	forn(i, n) {
		string s;
		cin >> s >> pos[i];
		pos[i]--;

		who[i] = (s[0] == 'O') ? 0 : 1;
	}
}

void update(int x, int y, int v, int dist) {
	if ((0 <= x && x < L) && (0 <= y && y < L))
		if (d[x][y][v] > dist) {
			d[x][y][v] = dist;
			qx.push(x);
			qy.push(y);
			qv.push(v);
		}
}

void solve() {
	memset(d, 60, sizeof d);

	update(0, 0, 0, 0);
	while (!qx.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();
		int v = qv.front(); qv.pop();

		int dist = d[x][y][v];

		if (v < n && who[v] == 0 && x == pos[v])
			for(int dy = -1; dy <= 1; dy++)
				update(x, y + dy, v + 1, dist + 1);

		if (v < n && who[v] == 1 && y == pos[v])
			for(int dx = -1; dx <= 1; dx++)
				update(x + dx, y, v + 1, dist + 1);

		for(int dx = -1; dx <= 1; dx++)
			for(int dy = -1; dy <= 1; dy++)
				update(x + dx, y + dy, v, dist + 1);
	}

	int ans = INF;
	forn(i, L)
		forn(j, L)
			ans = min(ans, d[i][j][n]);

	cout << ans << endl;
}

int main(){          
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tests;
	cin >> tests;
	forn(test, tests) {
		cout << "Case #" << test + 1 << ": ";
		read();
		solve();
	}

	return 0;
}
