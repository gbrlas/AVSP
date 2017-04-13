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
const int v[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<char> > solve1(vector<pair<int, int> > p) {
	vector<int> xx;
	forn(i, p.size())
		xx.pb(p[i].fs);

	sort(all(xx));
	xx.erase(unique(all(xx)), xx.end());

	vector<vector<char> > a(201);
	forn(i, 201)
		a[i].resize(201);
	forn(i, xx.size() - 1) {
		int lx = xx[i];
		int rx = xx[i + 1];

		vector<int> f;
		forn(j, p.size() - 1)
			if (p[j].sc == p[j + 1].sc && 
				min(p[j].fs, p[j + 1].fs) <= lx && rx <= max(p[j].fs, p[j + 1].fs))
				f.pb(p[j].sc);

		sort(all(f));
		f.erase(unique(all(f)), f.end());

		for (int j = 1; j < (int)f.size() - 1; j += 2)
			for (int x = lx; x < rx; x++)
				for (int y = f[j]; y < f[j + 1]; y++)
					a[x + 100][y + 100] = 1;
	}

	return a;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int t;
	scanf("%d", &t);
	forn(tt, t) {
		cerr << tt << endl;

		vector<pair<int, int> > p;
		int m;
		scanf("%d", &m);
		string s;
		forn(i, m) {
			int t;
			char buf[100];
			scanf("%s%d", buf, &t);
			forn(j, t)
				s += buf;
		}

		int x, y, d;
		x = y = d = 0;

		p.pb(mp(0, 0));
		forn(i, s.size()) {
			if (s[i] == 'F') {
				x += v[d][0];
				y += v[d][1];
				p.pb(mp(x, y));
			}
			if (s[i] == 'L')
				d = (d + 3) % 4;
			if (s[i] == 'R')
				d = (d + 1) % 4;
		}

		vector<vector<char> > a = solve1(p);
		forn(i, p.size())
			swap(p[i].fs, p[i].sc);
		vector<vector<char> > b = solve1(p);
		forn(i, b.size())
			forn(j, i)
				swap(b[i][j], b[j][i]);

		int ans = 0;
		forn(i, a.size())
			forn(j, a[i].size())
				if (a[i][j] || b[i][j])
					ans++;

		printf("Case #%d: %d\n", tt + 1, ans);
	}
	
	return 0;
}