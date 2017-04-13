#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:60000000")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define double long double

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
const int LC = -110;
const int RC = 370;
const int DEEP = 130;
const int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

char buf[1100000], s[100][100];
int z[20][20][RC - LC + 1][DEEP];
int n, cura;
string zs[20][20][RC - LC + 1][DEEP];

bool isin(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int rec(int x, int y, int ost, int dp) {
	if (ost == 0)
		return dp;
	if (dp == DEEP)
		return DEEP + 1;
	if (ost < LC || RC < ost)
		return DEEP + 1;

	if (z[x][y][ost - LC][dp] != -1)
		return z[x][y][ost - LC][dp];

	int res = DEEP;
	forn(i, 4) {
		int nx = x + dxy[i][0];
		int ny = y + dxy[i][1];

		if (!isin(nx, ny))
			continue;

		if (isdigit(s[x][y]))
			res = min(res, rec(nx, ny, ost, dp + 1));
		else {
			int nost = ost;
			if (s[x][y] == '+')
				nost -= (s[nx][ny] - '0');
			else
				nost += (s[nx][ny] - '0');

			res = min(res, rec(nx, ny, nost, dp + 1));
		}
	}

	z[x][y][ost - LC][dp] = res;
	return res;
}

string recwrite(int x, int y, int ost, int dp) {
	if (ost == 0)
		return "";

	if (!zs[x][y][ost - LC][dp].empty())
		return zs[x][y][ost - LC][dp];

	int res = z[x][y][ost - LC][dp];
	string rr = "";
	forn(i, 4) {
		int nx = x + dxy[i][0];
		int ny = y + dxy[i][1];

		if (!isin(nx, ny))
			continue;

		if (isdigit(s[x][y])) {
			if (res == rec(nx, ny, ost, dp + 1)) {
				string bu = s[nx][ny] + recwrite(nx, ny, ost, dp + 1);
				if (rr.empty() || bu < rr)
					rr = bu;
			}
		}
		else {
			int nost = ost;
			if (s[x][y] == '+')
				nost -= (s[nx][ny] - '0');
			else
				nost += (s[nx][ny] - '0');

			if (res == rec(nx, ny, nost, dp + 1)) {
				string bu = s[nx][ny] + recwrite(nx, ny, nost, dp + 1);
				if (rr.empty() || bu < rr)
					rr = bu;
			}
		}
	}

	zs[x][y][ost - LC][dp] = rr;
	return rr;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int q;
		cin >> n >> q;
		gets(buf);
		forn(i, n)
			gets(s[i]);

		printf("Case #%d:\n", ii + 1);
		memset(z, -1, sizeof(z));
		forn(i, n)
			forn(j, n)
				forn(c, RC - LC + 1)
					forn(k, DEEP)
						zs[i][j][c][k] = "";
		forn(i, q) {
			int a;
			scanf("%d", &a);
			char f = '9';
			vector<pair<int, int> > co;
			cura = DEEP;
			forn(x, n)
				forn(y, n)
					if (isdigit(s[x][y])) {
						int cur = rec(x, y, a - (s[x][y] - '0'), 0);
						if (cur < cura) {
							cura = cur;
							f = s[x][y];
							co.clear();
						}
						if (cura == cur && (s[x][y] < f)) {
							f = s[x][y];
							co.clear();
						}
						if (cura == cur && s[x][y] == f)
							co.pb(mp(x, y));
					}
			string ans;
			forn(k, co.size()) {
				int ax = co[k].fs;
				int ay = co[k].sc;
				rec(ax, ay, a - (s[ax][ay] - '0'), 0);
				string pt = s[ax][ay] + recwrite(ax, ay, a - (s[ax][ay] - '0'), 0);
				if (ans.empty())
					ans = pt;
				if (ans > pt)
					ans = pt;
			}
			puts(ans.c_str());
		}
	}
	
	return 0;
}