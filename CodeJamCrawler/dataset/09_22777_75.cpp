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
#define double long double

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

char buf[1100000];
bool u[110];
vector<int> g[110];
int r[110], a[110][110];

bool kun(int v) {
	if (u[v])
		return false;
	u[v] = true;
	forn(i, g[v].size())
		if (r[g[v][i]] == -1 || kun(r[g[v][i]])) {
			r[g[v][i]] = v;
			return true;
		}
	return false;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int n, m;
		scanf("%d%d", &n, &m);
		forn(i, n)
			forn(j, m) 
				scanf("%d", &a[i][j]);

		forn(i, n)
			g[i].clear();

		forn(i, n)
			forn(j, n) {
				bool ok = true;
				forn(k, m)
					if (a[i][k] >= a[j][k]) {
						ok = false;
						break;
					}
				if (ok)
					g[i].pb(j);
			}

		int ans = n;
		memset(r, -1, sizeof(r));
		forn(i, n) {
			memset(u, 0, sizeof(u));
			ans -= kun(i);
		}

		printf("Case #%d: %d\n", ii + 1, ans);
	}
	
	return 0;
}