/*
 * GCC version:			4.6
 * Command line:		g++ -std=c++0x -m64 -02 -fno-strict-aliasing -Wl,--stack=268435456 Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for(int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define CL(a, b)		memset(a, b, sizeof a)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define parallelize if (hocus pokus = true)

template <class hocus = bool> struct Solver {
	
	void run() {
		char s[64];
		cin >> s;
		ll msk = 0, num = 0;
		int n = 0;
		for (char *i = s; *i; ++i) {
			++n;
			msk *= 2;
			num *= 2;
			if (*i == '?') continue;
			num |= *i - '0';
			msk |= 1;
		}
		ll x = 0;
		parallelize {
			for (; ((x * x) & msk) != num; ++x);
		}
		x *= x;
		for (int i = n; i --> 0; ) {
			putchar((x & 1ll << i) ? '1' : '0');
		}
		cout << endl;
	}
};

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	cout.precision(12);	
	cout.setf(ios::fixed);
	int i = 0, n;
	for (cin >> n; i < n; ) {
		printf("Case #%d: ", ++i);
		Solver<> *s = new Solver<>;
		s->run();
		delete s;
	}
	return 0;
}
