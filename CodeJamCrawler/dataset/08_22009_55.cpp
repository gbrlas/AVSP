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

string perm(string s, vector<int> p) {
	string c;
	forn(i, s.size() / p.size())
		forn(j, p.size())
			c += s[(int)p.size() * i + p[j]];
	return c;
}

int get(string &s) {
	int k = 1, ans = 1;
	for (int i = 1; i < (int)s.size(); i++)
		if (s[i] == s[i - 1])
			k++;
		else {
			ans++;
			k = 1;
		}
	return ans;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		int k;
		string s;
		cin >> k >> s;

		vector<int> p(k);
		int ff = 1;
		forn(i, k) {
			p[i] = i;
			ff *= i + 1;
		}

		int ans = INF, sz;
		string c;
		forn(it, ff) {
			c = perm(s, p);
			sz = get(c);
			ans = min(ans, sz);
			next_permutation(all(p));
		}

		printf("Case #%d: %d\n", tt + 1, ans);
	}
	
	return 0;
}