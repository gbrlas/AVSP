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

int64 rec(vector<vector<int> > a, int x, int y, int k) {
	if (k == 3)
		return x == 0 && y == 0;
	int64 res = 0;
	forn(i, 3)
		forn(j, 3)
			if (a[i][j] > 0) {
				int64 mn = a[i][j];
				a[i][j]--;
				res += mn * rec(a, (x + i) % 3, (y + j) % 3, k + 1);
				a[i][j]++;
			}

	return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int n;
		int64 a, b, c, d, x0, y0, m;
		scanf("%d%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &n, &a, &b, &c, &d, &x0, &y0, &m);

		vector<vector<int> > x(3, vector<int> (3));
		forn(i, n) {
			x[x0 % 3][y0 % 3]++;
			x0 = (a * x0 + b) % m;
			y0 = (c * y0 + d) % m;
		}

		int64 a1 = rec(x, 0, 0, 0);
		a1 /= 6;

		printf("Case #%d: %I64d\n", tt + 1, a1);
	}
	
	return 0;
}