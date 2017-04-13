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
int a[11000];

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int n;
		scanf("%d\n", &n);
		forn(i, n) {
			gets(buf);
			a[i] = -1;
			forn(j, n)
				if (buf[j] == '1')
					a[i] = j;
		}

		int ans = 0;
		forn(i, n) {
			if (a[i] <= i)
				continue;
			int p;
			fore(j, i + 1, n)
				if (a[j] <= i) {
					p = j;
					break;
				}

			while (p > i) {
				swap(a[p], a[p - 1]);
				p--;
				ans++;
			}
		}

		printf("Case #%d: %d\n", ii + 1, ans);
	}
	
	return 0;
}