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
const int mod = 10009;

char buf[1100000];
string s;
int n, k, a[110][110];
vector<int> cur;
int64 sum[20];

void rec(int pos) {
	if (pos) {
		int64 su = 0, mn = 1;
		forn(i, s.size())
			if (s[i] == '+') {
				su += mn;
				su %= mod;
				mn = 1;
			}
			else {
				mn *= cur[s[i] - 'a'];
				mn %= mod;
			}
		sum[pos] += su;
		sum[pos] %= mod;
	}

	if (pos == k)
		return;

	forn(i, n) {
		forn(j, 26)
			cur[j] += a[i][j];

		rec(pos + 1);

		forn(j, 26)
			cur[j] -= a[i][j];
	}
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		cin >> s >> k >> n;
		s += "+";
		memset(a, 0, sizeof(a));
		forn(i, n) {
			string c;
			cin >> c;
			forn(j, c.size())
				a[i][c[j] - 'a']++;
		}

		cur = vector<int> (26, 0);
		memset(sum, 0, sizeof(sum));
		rec(0);

		printf("Case #%d: ", ii + 1);
		fore(i, 1, k + 1)
			cout << sum[i] << ' ';
		puts("");
	}
	
	return 0;
}