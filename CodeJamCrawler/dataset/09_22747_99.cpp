#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker, "/STACK:65000000")

#include <algorithm>
#include <iostream>
#include <sstream>

#include <cmath>
#include <cassert>
#include <ctime>

#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long int64;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

string c = "welcome to code jam", s;

int z[5500][30];
char buf[1100000];

int rec(int i, int j) {
	if (j == (int)c.size())
		return 1;
	if (i == (int)s.size())
		return 0;
	if (z[i][j] != -1)
		return z[i][j];

	int res = rec(i + 1, j);
	if (s[i] == c[j])
		res = (res + rec(i + 1, j + 1)) % 10000;

	return z[i][j] = res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

	int tt;
	scanf("%d", &tt);
	gets(buf);
	forn(ii, tt) {
		memset(buf, 0, sizeof(buf));
		gets(buf);
		s = buf;

		memset(z, -1, sizeof(z));
		int res = rec(0, 0);
		printf("Case #%d: %04d\n", ii + 1, res);
	}

	return 0;
}