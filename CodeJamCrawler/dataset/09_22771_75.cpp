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

char buf[1100000];
int fall[100][100], d[50][50][50], n, m;
char s[100][100];

void enlarge(int x, int &l, int &r) {
	while (l > 0 && s[x][l - 1] == '.' && s[x + 1][l - 1] == '#')
		l--;
	while (r < m - 1 && s[x][r + 1] == '.' && s[x + 1][r + 1] == '#')
		r++;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int f;
		scanf("%d%d%d\n", &n, &m, &f);
		forn(i, n)
			gets(s[i]);

		ford(i, n)
			forn(j, m)
				if (i == n - 1 || s[i + 1][j] == '#')
					fall[i][j] = i;
				else
					fall[i][j] = fall[i + 1][j];

		forn(i, n)
			forn(j, m)
				forn(t, m)
					d[i][j][t] = INF;
		d[0][0][0] = 0;

		set<pair<int, pair<int, pair<int, int> > > > q;
		q.insert(mp(0, mp(0, mp(0, 0))));

		int ans = -1;
		while (!q.empty()) {
			int dcur = q.begin()->fs;
			int x = q.begin()->sc.fs;
			int yl = q.begin()->sc.sc.fs;
			int yr = q.begin()->sc.sc.sc;
			q.erase(q.begin());

			if (x == n - 1) {
				ans = dcur;
				break;
			}

			enlarge(x, yl, yr);

			if (0 < yl && s[x][yl - 1] == '.') {
				int nyl = yl - 1;
				int nyr = yl - 1;
				int nx = fall[x][yl - 1];

				if (nx - x <= f)
					if (d[nx][nyl][nyr] > dcur) {
						q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
						d[nx][nyl][nyr] = dcur;
						q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
					}
			}
			if (yr < m - 1 && s[x][yr + 1] == '.') {
				int nyl = yr + 1;
				int nyr = yr + 1;
				int nx = fall[x][yr + 1];

				if (nx - x <= f)
					if (d[nx][nyl][nyr] > dcur) {
						q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
						d[nx][nyl][nyr] = dcur;
						q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
					}
			}

			for (int i = yl; i <= yr; i++) {
				int nyl = i;
				int nyr = i;
				int nx = fall[x + 1][i];

				if (nx - x <= f && yr - yl > 0)
					if (d[nx][nyl][nyr] > dcur + 1) {
						q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
						d[nx][nyl][nyr] = dcur + 1;
						q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
					}
			}

			if (x < n - 2) {
				for (int i = yl + 1; i < yr; i++)
					if (s[x + 2][i] == '#' && s[x + 2][i + 1] == '.') {
						int nyl = i + 1;
						int nyr = i + 1;
						int nx = fall[x + 1][i + 1];

						if (nx - (x + 1) <= f)
							if (d[nx][nyl][nyr] > dcur + 2) {
								q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
								d[nx][nyl][nyr] = dcur + 2;
								q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
							}
					}
				for (int i = yl + 1; i < yr; i++)
					if (s[x + 2][i] == '.' && s[x + 2][i + 1] == '#') {
						int nyl = i;
						int nyr = i;
						int nx = fall[x + 1][i];

						if (nx - (x + 1) <= f)
							if (d[nx][nyl][nyr] > dcur + 2) {
								q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
								d[nx][nyl][nyr] = dcur + 2;
								q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
							}
					}
				for (int l = yl; l <= yr; l++)
					if (s[x + 2][l] == '#')
						for (int r = l; r <= yr; r++) {
							if (s[x + 2][r] == '.')
								break;

							if (l == yl && r == yr)
								continue;

							int nyl = l;
							int nyr = r;
							int nx = x + 1;

							if (d[nx][nyl][nyr] > dcur + (r - l + 1)) {
								q.erase(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
								d[nx][nyl][nyr] = dcur + (r - l + 1);
								q.insert(mp(d[nx][nyl][nyr], mp(nx, mp(nyl, nyr))));
							}
						}
			}
		}

		printf("Case #%d: ", ii + 1);
		if (ans == -1)
			puts("No");
		else
			printf("Yes %d\n", ans);
	}
	
	return 0;
}