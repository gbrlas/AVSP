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
string c;
set<string> d;

void skip(int &l) {
	int bal = 0;
	while (true) {
		if (c[l] == '(')
			bal++;
		else
		if (c[l] == ')')
			bal--;
		if (bal == 0)
			break;
		l++;
	}
	l++;
}

double dfs(int l) {
	l++;
	string bs;
	while (isdigit(c[l]) || c[l] == '.') {
		bs += c[l];
		l++;
	}

	double b;
	sscanf(bs.c_str(), "%lf", &b);

	if (c[l] == ')')
		return b;

	bs = "";
	while (isalpha(c[l])) {
		bs += c[l];
		l++;
	}

	if (d.find(bs) != d.end())
		return b * dfs(l);

	skip(l);
	return b * dfs(l);
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		cerr << ii << endl;

		int l;
		scanf("%d", &l);
		gets(buf);

		string s;
		forn(i, l) {
			gets(buf);
			s += buf;
		}

		c = "";
		forn(i, s.size())
			if (s[i] != ' ')
				c += s[i];

		printf("Case #%d:\n", ii + 1);

		scanf("%d", &l);
		gets(buf);
		forn(i, l) {
			scanf("%s", buf);
			int k;
			scanf("%d", &k);
			d.clear();
			forn(j, k) {
				scanf("%s", buf);
				d.insert(buf);
			}

			double ans = dfs(0);
			printf("%.7lf\n", ans);
		}
	}
	
	return 0;
}