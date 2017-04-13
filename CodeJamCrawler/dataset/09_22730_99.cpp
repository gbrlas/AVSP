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

char buf[110000];
bool u[20][30];
string s[6000];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int l, n, m;
	cin >> l >> n >> m;
	gets(buf);
	forn(i, n) {
		gets(buf);
		s[i] = buf;
	}

	forn(i, m) {
		gets(buf);
		string c = buf;

		int k = 0;
		memset(u, 0, sizeof(u));
		forn(j, c.size()) 
			if (c[j] == '(') {
				j++;
				while (j < (int)c.size() && c[j] != ')') {
					u[k][c[j] - 'a'] = true;
					j++;
				}

				k++;
			}
			else
				u[k++][c[j] - 'a'] = true;

		if (k != l)
			throw;

		int ans = 0;
		forn(j, n) {
			bool fl = true;
			forn(t, l)
				if (!u[t][s[j][t] - 'a']) {
					fl = false;
					break;
				}
			if (fl)
				ans++;
		}

		printf("Case #%d: %d\n", i + 1, ans);
	}

	return 0;
}