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

int a[110000], d[110000], ne[110000];
bool u[110000];

int get(int v) {
	if (!u[v])
		return v;
	ne[v] = get(ne[v]);
	return ne[v];
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		cerr << tt << endl;
		int k, n;
		scanf("%d%d", &k, &n);
		forn(i, n)
			scanf("%d", &d[i]);

		int cnt = 0;
		forn(i, k) {
			a[i] = i;
			ne[i] = i;
		}

		int v = 0, g = 0;
		memset(u, 0, sizeof(u));
		memset(a, 255, sizeof(a));
		while (g < k) {
			cnt = 0;
			v = get(v);
			while (cnt != g) {
				v = (v + 1) % k;
				v = get(v);
				cnt++;
			}
			a[v] = g;
			g++;
			u[v] = true;
			ne[v] = ne[(v + 1) % k];
		}

		printf("Case #%d: ", tt + 1);
		forn(i, n)
			printf("%d ", a[d[i] - 1] + 1);
		puts("");
	}
	
	return 0;
}