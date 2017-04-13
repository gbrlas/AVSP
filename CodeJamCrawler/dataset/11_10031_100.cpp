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

int n;
char next[300][300], p[MAXN];
bool bad[300][300];

void read() {
	memset(next, 255, sizeof next);
	memset(bad, 0, sizeof bad);

	int c;
	cin >> c;
	forn(i, c) {
		string s;
		cin >> s;
		next[s[0]][s[1]] = next[s[1]][s[0]] = s[2];
	}

	int d;
	cin >> d;
	forn(i, d) {
		string s;
		cin >> s;
		bad[s[0]][s[1]] = bad[s[1]][s[0]] = true;
	}

	cin >> n >> p;
}

vector<char> a;

void add(char c) {
	if (a.empty())
		a.pb(c);
	else {
		char last = a.back();
		if (next[last][c] != -1) {
			a.pop_back();
			add(next[last][c]);
		}
		else
			a.pb(c);
	}

	forn(i, a.size())
		forn(j, i)
			if (bad[a[i]][a[j]]) {
				a.clear();
				return;
			}
}

void solve() {
	a.clear();
	forn(i, n)
		add(p[i]);

	cout << "[";
	forn(i, a.size()) {
		if (i != 0) cout << ", ";
		cout << a[i];
	}
	cout << "]" << endl;
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
