#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime> //clock()
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>

using namespace std;

#pragma comment(linker, "/STACK:33554432")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define it iterator
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()

const long double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const long double PI = 2 * acos(.0);
const int v[3][2] = {{1, 2}, {2, 1}};

int n, m, z[110][110];
bool u[110][110];

bool isin(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && !u[x][y];
}

int rec(int x, int y) {
	if (x == n - 1 && y == m - 1)
		return 1;

	if (z[x][y] != -1)
		return z[x][y];

	int res = 0;
	forn(i, 2) {
		int fx = x + v[i][0];
		int fy = y + v[i][1];

		if (isin(fx, fy))
			res = (res + rec(fx, fy)) % 10007;
	}

	z[x][y] = res;
	return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int r;
		scanf("%d%d%d", &n, &m, &r);
		memset(u, 0, sizeof(u));
		forn(i, r) {
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			u[x][y] = true;
		}

		memset(z, 255, sizeof(z));


		int res = rec(0, 0);
		if (u[0][0])
			res = 0;

		printf("Case #%d: %d\n", tt + 1, res);
	}
	
	return 0;
}