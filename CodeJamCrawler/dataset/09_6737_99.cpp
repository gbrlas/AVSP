#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <list>

#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define I (int)
#define I64 (int64)
#define LD (long double)
#define VI vector<int>

const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

const int dx[4] = {-1,  0, 0, 1};
const int dy[4] = { 0, -1, 1, 0};

int n, m, h[110][110];
char ans[110][110];
vector<pair<int, int> > g[110][110];
bool used[110][110];

bool valid(int x, int y){
	return (0 <= x && x < n && 0 <= y && y < m);
}

void DFS(int x, int y, char c){
	if(used[x][y]) return;
	used[x][y] = true;
	ans[x][y] = c;
	forn(i, g[x][y].size())
		DFS(g[x][y][i].first, g[x][y][i].second, c);
}

inline void readData(){
	cin >> n >> m;
	forn(i, n)
		forn(j, m){
			cin >> h[i][j];
			g[i][j].clear();
	}
}

inline void writeData(){
	forn(i, n){
		forn(j, m)
			printf("%c ", ans[i][j]);
		printf("\n");
	}
}

inline void init(){
	memset(ans, 0, sizeof ans);
	memset(used, 0, sizeof used);
}

void solve(){
	init();
	readData();

	forn(x, n)
		forn(y, m){
			int dir = -1, hh = h[x][y];
			forn(i, 4){
				int xx = x + dx[i];
				int yy = y + dy[i];

				if (valid(xx, yy) && h[xx][yy] < hh){
					hh = h[xx][yy];
					dir = i;
				}
			}

			if (dir != -1){
				g[x + dx[dir]][y + dy[dir]].pb(mp(x, y));
				g[x][y].pb(mp(x + dx[dir], y + dy[dir]));
			}
	}

	int num = 0;
	forn(i, n)
		forn(j, m)
			if (ans[i][j] == 0){
				DFS(i, j, num + 'a');
				num++;
			}

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d", &tests);
	forn(test, tests){
		printf("Case #%d:\n", test + 1);
		solve();
	}
	
	return 0;
}