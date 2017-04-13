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

bool g[1100][1100], u[11000];
int64 a, b;

int64 gcd(int64 a, int64 b) {
	return (a == 0 ? b : gcd(b % a, a));
}

void dfs(int v) {
	u[v] = true;

	for (int i = a; i <= b; i++)
		if (g[v][i] && !u[i])
			dfs(i);
}

int64 mxx(int64 a) {
	int64 ans = 1;
	for (int64 i = 2; i * i <= a; i++)
		if (a % i == 0) {
			ans = i;
			while (a % i == 0)
				a /= i;
		}
	if (a > 1)
		ans = max(ans, a);
	return ans;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int64 p;
		scanf("%lld%lld%lld", &a, &b, &p);

		memset(g, 0, sizeof(g));
		for (int64 i = a; i <= b; i++)
			for (int64 j = a; j <= b; j++)
				if (mxx(gcd(i, j)) >= p)
					g[i][j] = true;

		memset(u, 0, sizeof(u));
		int cnt = 0;
		for (int i = a; i <= b; i++)
			if (!u[i])
				dfs(i), cnt++;

		printf("Case #%d: %d\n", tt + 1, cnt);
	}
	
	return 0;
}