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

const int MAXN = 100100;


int n, a[MAXN];
bool used[MAXN];

void read() {
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
}

void solve() {
	int ans = 0;
	memset(used, 0, sizeof used);
	forn(i, n)
		if (!used[i]) {
			int v = i, len = 0;
			while (!used[v]) {
				len++;
				used[v] = true;
				v = a[v];
			}

			
		}

	forn(i, n)
		if (i != a[i])
			ans++;

	cout << ans << ".000000" << endl;
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

	long double z = 24, ans = 0, cur = 1 / z;
	for(int i = 1; i < 10000; i++) {
		ans += i * cur;
		cur *= (z - 1) / z;
	}

	cerr << ans << endl;


	return 0;
}
