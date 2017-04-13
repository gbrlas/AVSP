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
typedef vector<pair<int, int> > state;
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

char buf[1100000];
int n, m;
string g[1100];

state getstate(char ch) {
	state res;
	forn(i, n)
		forn(j, m)
			if (g[i][j] == ch || g[i][j] == 'w')
				res.pb(mp(i, j));
	return res;
}

bool nei(pair<int, int> a, pair<int, int> b) {
	return abs(a.fs - b.fs) + abs(a.sc - b.sc) == 1;
}

bool emp(int x, int y, state &v) {
	return 0 <= x && x < n && 0 <= y && y < m && 
		g[x][y] != '#' && !binary_search(all(v), mp(x, y));
}

map<state, bool> z;

int dfs(int a, state &v, vector<char> &u) {
	if (u[a])
		return 0;
	u[a] = true;

	int res = 1;
	forn(i, 4) {
		int nx = v[a].fs + dir[i][0];
		int ny = v[a].sc + dir[i][1];

		int pos = int(lower_bound(all(v), mp(nx, ny)) - v.begin());
		if (pos < (int)v.size() && v[pos] == mp(nx, ny))
			res += dfs(pos, v, u);
	}

	return res;
}

bool isd(state v) {
	if (z.count(v))
		return z[v];
	vector<char> u(v.size());
	return z[v] = (dfs(0, v, u) != (int)v.size());
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	
	int tt;
	cin >> tt;
	gets(buf);
	forn(ii, tt) {
		z.clear();

		cerr << ii << endl;

		scanf("%d%d\n", &n, &m);
		forn(i, n)
			getline(cin, g[i]);

		state s = getstate('o');
		state t = getstate('x');

		map<state, int> d;
		d[s] = 0;
		set<pair<int, state> > q;
		q.insert(mp(0, s));

		int ans = -1;
		while (!q.empty()) {
			state v = q.begin()->sc;
			q.erase(q.begin());
			int dcur = d[v];
			if (v == t) {
				ans = dcur;
				break;
			}
			bool od = isd(v);

			forn(i, v.size()) {
				forn(j, 4) {
					int x = v[i].fs;
					int y = v[i].sc;
					int nx = x + dir[j][0];
					int ny = y + dir[j][1];
					int fx = x - dir[j][0];
					int fy = y - dir[j][1];

					if (emp(nx, ny, v) && emp(fx, fy, v)) {
						state ov = v;

						v[i] = mp(nx, ny);
						sort(all(v));

						bool nd = isd(v);

						if (!(nd && od)) {
							if (d.count(v) == 0 || d[v] > dcur + 1) {
								q.erase(mp(d[v], v));
								d[v] = dcur + 1;
								q.insert(mp(d[v], v));
							}
						}

						v = ov;
					}
				}
			}
		}

		printf("Case #%d: %d\n", ii + 1, ans);
	}
	
	return 0;
}