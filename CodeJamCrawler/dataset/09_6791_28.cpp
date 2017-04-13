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

inline bool has(int mask, int v){
	return ((mask & (1 << v)) != 0);
}

int n, k, d[100100];
int a[110][110];
bool corr[100100], good[110][110];

bool more(int t1, int t2){
	forn(i, k)
		if (a[t1][i] <= a[t2][i])
			return false;

	return true;
}

inline void readData(){
	cin >> n >> k;
	forn(i, n)
		forn(j, k)
			cin >> a[i][j];
}

inline void writeData(){
	cout << d[(1 << n) - 1] << endl;
}

inline void init(){
	memset(d, 60, sizeof d);
	memset(corr, 1, sizeof corr);
}

inline void solve(){
	init();
	readData();

	forn(i, n)
		forn(j, i)
			good[i][j] = good[j][i] = more(i, j) || more(j, i);

	forn(mask, 1 << n)
		forn(i, n)
			forn(j, i)
				if (has(mask, i) && has(mask, j) && !good[i][j])
					corr[mask] = false;

	d[0] = 0;
	forn(i, 1 << n)
		for(int j = i; j > 0; j = (j - 1) & i)
			if (corr[j])
				d[i] = min(d[i], d[i - j] + 1);

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