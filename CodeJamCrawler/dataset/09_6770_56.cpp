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

int n;
vector<int> num;

inline void readData(){
	char buf[111];
	gets(buf);

	forn(i, strlen(buf))
		num.pb(buf[i] - '0');
}

inline void writeData(){
	forn(i, num.size())
		printf("%d", num[i]);

	printf("\n");
}

inline void init(){
	num.clear();
}

void solve(){
	init();
	readData();

	if (!next_permutation(all(num))){
		sort(all(num));
		int t = (int) num.size();
		while (num[0] == 0) num.erase(num.begin());
		while (num.size() != t + 1) num.insert(num.begin() + 1, 0);
	}

	writeData();
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tests;
	scanf("%d\n", &tests);
	forn(test, tests){
		printf("Case #%d: ", test + 1);
		solve();
	}
	
	return 0;
}