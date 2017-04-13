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

const int MAXN = 1010;

int n, m, a[MAXN][MAXN];

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

vector<int> X, Y, W;

bool correct() {
	int cx = (*min_element(all(X)) + *max_element(all(X))) / 2;
	int cy = (*min_element(all(Y)) + *max_element(all(Y))) / 2;

	int sx = 0, sy = 0, sw = 0;
	forn(i, X.size()) {
		sx += W[i] * X[i];
		sy += W[i] * Y[i];
		sw += W[i];
	}

	return (sw * cx == sx) && (sw * cy == sy);
}

void solve() {
	for(int k = min(n, m); k >= 3; k--)
		forn(x, n - k + 1)
			forn(y, m - k + 1) {
				X.clear();
				Y.clear();
				W.clear();
				for(int xx = x; xx < x + k; xx++)
					for(int yy = y; yy < y + k; yy++) {
						if (xx == x && yy == y) continue;
						if (xx == x + k - 1 && yy == y) continue;
						if (xx == x && yy == y + k - 1) continue;
						if (xx == x + k - 1 && yy == y + k - 1) continue;

						X.pb(2 * xx);
						Y.pb(2 * yy);
						W.pb(a[xx][yy]);
					}

				if (correct()) {
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
