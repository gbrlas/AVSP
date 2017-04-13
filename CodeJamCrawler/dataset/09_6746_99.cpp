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

const string p = "welcome to code jam";

string s;
int d[1100][30];

inline void readData(){
	getline(cin, s);
}

inline void writeData(){
	stringstream st;
	st << d[s.size()][p.size()];
	string ans;
	st >> ans;
	while (ans.size() < 4) ans = "0" + ans;

	printf("%s\n", ans.c_str());
}

inline void init(){
	memset(d, 0, sizeof d);
	d[0][0] = 1;
}

void solve(){
	init();
	readData();

	forn(i, s.size())
		forn(j, p.size() + 1){
			d[i + 1][j] += d[i][j];
			d[i + 1][j] %= 10000;
			if (j != (int) p.size() && s[i] == p[j]) d[i + 1][j + 1] += d[i][j];
			d[i + 1][j + 1] %= 10000;
		}

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("c:/documents and settings/nalp/рабочий стол/output.txt", "wt", stdout);

	int tests;
	scanf("%d\n", &tests);
	forn(test, tests){
		printf("Case #%d: ", test + 1);
		solve();
	}
	
	return 0;
}