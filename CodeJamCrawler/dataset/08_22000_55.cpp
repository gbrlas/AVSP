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



int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		cerr << tt << endl;
		int n, m, a;
		scanf("%d%d%d", &n, &m, &a);

		bool fl = false;
		for (int x2 = 0; x2 <= n; x2++)
			for (int y2 = 0; y2 <= m; y2++)
				for (int x3 = 0; x3 <= n; x3++)
					for (int y3 = 0; y3 <= m; y3++)
						if (abs(x3 * y2 - x2 * y3) == a && !fl) {
							fl = true;
							printf("Case #%d: 0 0 %d %d %d %d\n", tt + 1, x2, y2, x3, y3);
							goto ha;
						}

		ha:
		if (!fl)
			printf("Case #%d: IMPOSSIBLE\n", tt + 1);

/*
		int ai = -1, aj;
		for (int i = 1; i <= n; i++)
			if (a % i == 0 && (a / i) <= m) {
				ai = i;
				aj = a / i;
				break;
			}

		if (ai == -1) {
			printf("Case #%d: IMPOSSIBLE\n", tt + 1);
			continue;
		}

		printf("Case #%d: 0 0 %d 0 0 %d\n", tt + 1, ai, aj);
*/
	}
	
	return 0;
}