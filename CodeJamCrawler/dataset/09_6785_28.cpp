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

#define write_1d_array(message, a, n) { cout << endl << message << endl; forn(i, n) cout << a[i] << " "; cout << "\n\n";}
#define write_2d_array(message, a, n, m) { cout << endl << message << endl; forn(i, n){forn(j, m) cout << a[i][j] << " "; cout << endl; } cout << "\n\n";}

const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 3.1415926535897932384626433832795;

int n, st[110], ans, mt[110];
bool used[110], freeP[110];
vector<int> g[110];

inline void readData(){
	char buf[110];
	scanf("%d\n", &n);
	forn(i, n){
		gets(buf);
		st[i] = 0;
		forn(j, n)
			if (buf[j] == '1')
				st[i] = j;
	}	
}

inline void writeData(){
	cout << ans << endl;
}

inline void init(){
	ans = 0;
	memset(freeP, 1, sizeof freeP);
}

bool DFS(int v){
	if (used[v]) return false;
	used[v] = true;

	forn(i, g[v].size()){
		int u = g[v][i];
		if (mt[u] == -1 || DFS(u)){
			mt[u] = v;
			return true;
		}
	}

	return false;
}

inline bool can(int start){
	forn(i, n)
		g[i].clear();

	forn(i, n) if (i >= start)
		forn(j, n) if (freeP[j])
			if (st[i] <= j)
				g[i].pb(j);

	int ans = 0;
	memset(mt, 255, sizeof mt);
	forn(i, n){
		memset(used, 0, sizeof used);
		ans += (int)DFS(i);
	}

	return ans == n - start;
}

inline void solve(){
	init();
	readData();

	forn(i, n){
		int cnt = 0;
		forn(j, n)
		if (freeP[j]){
			freeP[j] = false;
			if (st[i] <= j && can(i + 1)){
				ans += cnt;
				break;
			}
			else {
				freeP[j] = true;
				cnt++;
			}
		}
	}

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d", &tests);
	forn(test, tests){
		printf("Case #%d: ", test + 1);
		solve();
	}
	
	return 0;
}