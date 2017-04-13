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

const int MAXN = 1100;
const string ZERO = string(30, '0');

int n, c[MAXN];
string s[MAXN];

void read() {
	cin >> n;
	forn(i, n) {
		int x;
		cin >> x;
		c[i] = x;

		s[i] = "";
		forn(j, ZERO.size())
			if ((x & (1 << j)) != 0)
				s[i] += "1";
			else
				s[i] += "0";
	}
}

void solve() {
	string v = ZERO;
	forn(i, n)
		forn(j, ZERO.size())
			if ((v[j] == '1') ^ (s[i][j] == '1'))
				v[j] = '1';
			else
				v[j] = '0';

	if (v != ZERO) {
		cout << "NO" << endl;
		return;
	}

	int sum = 0;
	forn(i, n)
		sum += c[i];

	sum -= *min_element(c, c + n);
	cout << sum << endl;
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
