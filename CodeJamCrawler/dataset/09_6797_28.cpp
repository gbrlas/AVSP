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

int n;
long double x[110], y[110], r[110], ans;

long double dist(long double x1, long double y1, long double x2, long double y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

inline void readData(){
	cin >> n;
	forn(i, n)
		cin >> x[i] >> y[i] >> r[i];
}

inline void writeData(){
	cout.precision(9);
	cout << fixed << ans << endl;
}

inline void init(){
	ans = 1E90;
}

inline long double solve(vector<long double> x, vector<long double> y, vector<long double> r){
	long double t = dist(x[0], y[0], x[1], y[1]) + r[0] + r[1];
	return t * 0.5;
}

inline void solve(){
	init();
	readData();

	if (n == 1) ans = r[0];
	if (n == 2) ans = max(r[0], r[1]);
	if (n == 3){
		forn(i, n){
			vector<long double> xx, yy, rr;
			long double t = r[i];
			forn(j, n)
				if (i != j){
					xx.pb(x[j]);
					yy.pb(y[j]);
					rr.pb(r[j]);
				}

			t = max(t, solve(xx, yy, rr));
			ans = min(ans, t);
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