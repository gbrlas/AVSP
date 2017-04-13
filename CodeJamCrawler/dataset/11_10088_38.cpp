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

const int MAXN = 610;

pair<int64, int64> b[MAXN][MAXN], bal[MAXN];
int n, m, good[MAXN][MAXN];
int64 a[MAXN][MAXN];

inline pair<int64, int64> operator + (const pair<int64, int64> &a, const pair<int64, int64> &b) {
	return mp(a.first + b.first, a.second + b.second);
}

inline pair<int64, int64> operator - (const pair<int64, int64> &a, const pair<int64, int64> &b) {
	return mp(a.first - b.first, a.second - b.second);
}

inline pair<int64, int64> get(int y, int l, int r) {
	pair<int64, int64> ans = b[r][y];
	if (l > 0) ans = ans - b[l - 1][y];
	return ans;
}

void read() {
	int d;
	cin >> n >> m >> d;
	forn(i, n)
		forn(j, m) {
			char c;
			scanf(" %c", &c);
			a[i][j] = c + d - '0';
		}
}

void solve() {
	for(int k = min(n, m); k >= 3; k--) {
		memset(good, 0, sizeof good);

		forn(it, 2) {
			forn(i, n)
				forn(j, m) {
					b[i][j] = mp(2 * a[i][j] * j, a[i][j]);
					if (i > 0) b[i][j] = b[i][j] + b[i - 1][j];
				}

			forn(x, n - k + 1) {
				forn(y, m)
					bal[y] = get(y, x, x + k - 1);

				pair<int64, int64> cur(0, 0);
				forn(y, k)
					cur = cur + bal[y];

				forn(y, m - k + 1) {
					int64 pos = y + y + k - 1;

					pair<int64, int64> t = cur;
					t = t - get(y, x, x);
					t = t - get(y, x + k - 1, x + k - 1);
					t = t - get(y + k - 1, x, x);
					t = t - get(y + k - 1, x + k - 1, x + k - 1);

					if (t.first == pos * t.second)
						if (it == 0)
							good[x][y]++;
						else
							good[y][x]++;

					cur = cur - bal[y];
					cur = cur + bal[y + k];
				}
			}

			forn(i, max(n, m))
				forn(j, i)
					swap(a[i][j], a[j][i]);

			swap(n, m);
		}

		forn(x, n - k + 1)
			forn(y, m - k + 1)
				if (good[x][y] == 2) {
					cout << k << endl;
					return;
				}
	}

	cout << "IMPOSSIBLE" << endl;
}

int main(){          
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	cout.precision(9);
	cout.setf(ios::fixed);

	cerr.precision(3);
	cerr.setf(ios::fixed);

	int tests;
	cin >> tests;
	forn(i, tests) {
		cerr << "Test #" << i + 1 << endl;
		time_t curTime = clock();

		cout << "Case #" << i + 1 << ": ";
		read();
		solve();

		cerr << "calced : " << (clock() - curTime + 0.0) / CLOCKS_PER_SEC << endl << endl;
	}

	return 0;
}
