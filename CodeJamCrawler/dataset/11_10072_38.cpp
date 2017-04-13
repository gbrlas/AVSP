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

const int MAXN = 1001000;

int n, add[MAXN], X;
long double s, r, t;

void read() {
	cin >> X >> s >> r >> t >> n;
	memset(add, 0, sizeof add);
	forn(i, n) {
		int l, r, w;
		cin >> l >> r >> w;

		for(int pos = l; pos < r; pos++)
			add[pos] = w;
	}
}

void solve() {
	sort(add, add + X);
	long double res = 0.0;
	forn(i, X) {
		long double cur = min(1.0 / (add[i] + r), t);
		long double fast = cur * (add[i] + r), low = 1 - fast;
		res += fast / (add[i] + r) + low / (add[i] + s);
		t -= cur;
	}

	cout << res << endl;
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
