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

int l, d, ans;
bool valid[20][300];
string a[100100], s;

inline void readData(){
	int pos = -1, h = 0;
	getline(cin, s);

	forn(i, s.size())
		if (s[i] == '(') h++, pos++;
		else if (s[i] == ')') h--;
		else {
			if (h == 0) pos++;
			valid[pos][s[i]] = true;
		}
}

inline void writeData(){
	printf("%d\n", ans);
}

inline void init(){
	ans = 0;
	memset(valid, 0, sizeof valid);
}

void solve(){
	init();
	readData();

	forn(i, d){
		bool fl = true;
		forn(j, a[i].size())
			fl = fl && valid[j][a[i][j]];

		ans += fl;
	}

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("c:/documents and settings/nalp/рабочий стол/output.txt", "wt", stdout);

	int tests;
	scanf("%d%d%d\n", &l, &d, &tests);
	forn(i, d)
		getline(cin, a[i]);

	forn(test, tests){
		printf("Case #%d: ", test + 1);
		solve();
	}
	
	return 0;
}