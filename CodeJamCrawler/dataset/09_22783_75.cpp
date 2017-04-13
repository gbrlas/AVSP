#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:60000000")

#ifdef __GNUC__
typedef long long int64;
#else //MS Visual Studio
typedef __int64 int64;
#endif

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

char buf[1100000];
int x[110], y[110], r[110];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int n;
		cin >> n;
		forn(i, n)
			scanf("%d%d%d", &x[i], &y[i], &r[i]);

		double ans = 1E40;

		if (n == 3)
			forn(i, n)
				forn(j, i) {
					double di = sqrt(1. * (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
					di += r[i] + r[j];
					di /= 2;
					double cur = max(di, 1. * r[3 - i - j]);
					ans = min(ans, cur);
				}
		else
		if (n == 1)
			ans = r[0];
		else
			ans = max(r[0], r[1]);

		printf("Case #%d: %.9lf\n", ii + 1, ans);
	}
	
	return 0;
}