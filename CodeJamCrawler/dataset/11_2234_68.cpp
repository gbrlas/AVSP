/*
 * GCC version:			4.6.1
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
		ll n;
		cin >> n;
		vector<bool> p(1 << 20);
		int res = 1;
		for (int x = 2; x < sz(p) && x * ll(x) <= n; ++x)
			if (!p[x]) {
				for (ll z = x; (z *= x) <= n; ++res);
				for (int y = x + x; y < sz(p); y += x)
					p[y] = true;
			}
		if (n == 1) res = 0;
		cout << res << endl;
	}
};

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
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
