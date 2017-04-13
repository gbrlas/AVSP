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


int n, ans, p[110];
char a[110][110];

void shift(int fi, int st){
}

inline void readData(){
	scanf("%d\n", &n);
	forn(i, n)
		gets(a[i]);
}

inline void writeData(){
	cout << ans << endl;
}

inline void init(){
	ans = INF;
}

inline void solve(){
	init();
	readData();

	forn(i, n)
		p[i] = i;

	do {
		int t = 0;
		forn(i, n)
			forn(j, n)
				if (a[p[i]][j] == '1' && j > i)
					t = INF;

		vector<int> q(p, p + n);
		forn(i, n)
			for(int j = i + 1; j < n; j++)
				if (q[j] < q[i]){
					swap(q[j], q[i]);
					t++;
				}

		ans = min(ans, t);
	}
	while (next_permutation(p, p + n));

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