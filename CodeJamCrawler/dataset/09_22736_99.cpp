#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker, "/STACK:65000000")

#include <algorithm>
#include <iostream>
#include <sstream>

#include <cmath>
#include <cassert>
#include <ctime>

#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long int64;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int dxy[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

char col;
int a[110][110], n, m;
char c[110][110];

bool isin(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

char dfs(int x, int y) {
	if (c[x][y])
		return c[x][y];
	int mi = a[x][y], ai = -1;
	forn(i, 4) {
		int nx, ny;
		nx = x + dxy[i][0];
		ny = y + dxy[i][1];
		if (isin(nx, ny) && a[nx][ny] < mi) {
			mi = a[nx][ny];
			ai = i;
		}
	}

	if (ai == -1)
		c[x][y] = col++;
	else
		c[x][y] = dfs(x + dxy[ai][0], y + dxy[ai][1]);

	return c[x][y];
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		scanf("%d%d", &n, &m);
		forn(i, n)
			forn(j, m)
				scanf("%d", &a[i][j]);

		col = 'a';
		memset(c, 0, sizeof(c));
		printf("Case #%d:\n", ii + 1);
		forn(i, n) {
			forn(j, m) {
				char res = dfs(i, j);
				printf("%c ", res);
			}
			puts("");
		}
	}

	return 0;
}