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

int m, z[11000][2], a[11000], tp[11000], ch[11000];
bool en[11000];


int op(int a, int b, int tp) {
	if (tp)
		return a & b;
	return a | b;
}

int rec(int v, int w) {
	if (v >= m) {
		if (w == 0)
			return 0;
		return INF;
	}

	if (z[v][w] != -1)
		return z[v][w];

	int res;
	if (en[v]) {
		if (w == a[v])
			res = 0;
		else
			res = INF;
		z[v][w] = res;
		return res;
	}

	res = INF;
	forn(i, 2)
		forn(j, 2) {
			int cc = rec((v + 1) * 2 - 1, i) + rec((v + 1) * 2, j);
			if (cc > INF)
				cc = INF;
			int we;
			if (op(i, j, tp[v]) == w)
				we = 0;
			else
			if (ch[v] == 1 && op(i, j, 1 - tp[v]) == w)
				we = 1;
			else
				we = INF;

			cc += we;
			if (cc > INF)
				cc = INF;

			if (cc < res)
				res = cc;
		}

	z[v][w] = res;
	return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int v;
		scanf("%d%d", &m, &v);
		memset(en, 0, sizeof(en));
		forn(i, (m - 1) / 2)
			scanf("%d%d", &tp[i], &ch[i]);
		for (int i = (m - 1) / 2; i < m; i++) {
			scanf("%d", &a[i]);
			en[i] = true;
		}

		memset(z, 255, sizeof(z));
		int ans = rec(0, v);

		if (ans >= INF)
			printf("Case #%d: IMPOSSIBLE\n", tt + 1);
		else
			printf("Case #%d: %d\n", tt + 1, ans);
	}
	
	return 0;
}