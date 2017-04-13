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
const int v[6][2] = {{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1}};

int n, m;

string s[100];

string made(string s) {
	string c = s;
	forn(i, s.size())
		c[i] = '0';
	forn(i, s.size())
		if (s[i] == '1') {
			if (i > 0)
				c[i - 1] = '1';
			if (i < (int)s.size() - 1)
				c[i + 1] = '1';
		}

	return c;
}

string str(int a) {
	string s;
	forn(i, m)
		s += "0";

	forn(i, m)
		if ((a & (1 << i)) != 0)
			s[i] = '1';

	return s;
}

bool dve(string s) {
	forn(i, s.size() - 1)
		if (s[i] == '1' && s[i + 1] == '1')
			return false;
	return true;
}

bool ok(string a, string b) {
	forn(i, a.size())
		if (b[i] == '1' && a[i] == '1')
			return false;
	return true;
}

bool ok2(string a, string b) {
	forn(i, a.size())
		if (a[i] == '1' && b[i] == 'x')
			return false;
	return true;
}

int z[5000][20], a[5000][5000], cn[5000];

int rec(int ma, int k) {
	if (!ok2(str(ma), s[k]))
		return -INF;

	if (k == n - 1)
		return cn[ma];

	if (z[ma][k] != -1)
		return z[ma][k];

	int res = cn[ma];
	forn(i, 1 << m)
		if (a[ma][i] == 1)
			res = max(res, cn[ma] + rec(i, k + 1));

	z[ma][k] = res;
	return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		cerr << tt << endl;

		scanf("%d%d", &n, &m);

		ford(i, n)
			cin >> s[i];

//		forn(i, n / 2)
//			swap(s[i], s[n - i - 1]);

		forn(i, 1 << m) {
			cn[i] = 0;
			forn(j, m)
				if ((i & (1 << j)) != 0)
					cn[i]++;
		}

		memset(a, 0, sizeof(a));
		forn(i, 1 << m)
			forn(j, 1 << m)
				if (dve(str(i)) && dve(str(j)) && ok(made(str(i)), str(j)))
					a[i][j] = 1;
				else
					a[i][j] = 0;

		int res = 0;
		memset(z, 255, sizeof(z));
		forn(i, 1 << m)
			if (dve(str(i)))
				res = max(res, rec(i, 0));

		printf("Case #%d: %d\n", tt + 1, res);

		continue;
	}
	
	return 0;
}