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


int64 n, pd, pg; 

bool check(int64 d, int64 g) {
	if ((d * pd) % 100 != 0) return false;
	if ((g * pg) % 100 != 0) return false;
	return (g >= d) && (g * pg >= d * pd) && (g * (100 - pg) >= d * (100 - pd));
}

void read() {
	cin >> n >> pd >> pg;
}

void solve() {
	int gd = 1;
	for(int i = 1; i <= 100; i++)
		if (pd % i == 0 && 100 % i == 0)
			gd = i;

	int gg = 1;
	for(int i = 1; i <= 100; i++)
		if (pg % i == 0 && 100 % i == 0)
			gg = i;

	int64 d = 100 / gd;
	int64 g = 100LL * INF / gg;
	if (d <= n && check(d, g))
		cout << "Possible" << endl;
	else
		cout << "Broken" << endl;

	return;

	bool ans = false;
	for(int64 d = 1; d <= n; d++)
		for(int64 g = d; g <= 1000000; g++) 
			if (check(d, g)) {
				ans = true;
				break;
			}
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
