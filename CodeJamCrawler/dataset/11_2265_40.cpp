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
	
	int can(map<int, int> c, int m) {
		map<int, int> p;
		for (; c.size(); ) {
			int x = c.begin()->first;
			for (; p[x] > 0 && c[x] > 0; ) {
				--c[x];
				--p[x];
				if (c.count(x + 1)) ++p[x + 1];
			}
			for (; c[x] > 0; ) {
				bool ok = true;
				REP (i, m) {
					if (c.count(x + i) == 0 || c[x + i] == 0) {
						ok = false;
						break;
					}
				}
				if (!ok) return false;
				REP (i, m) --c[x + i];
				p[x + m]++;
			}
			c.erase(c.begin());
		}
		return true;
	}
	
	void run() {
		int n;
		cin >> n;
		map<int, int> f;
		REP (i, n) {
			int x;
			cin >> x;
			++f[x];
		}
		int L = 1, R = n;
		parallelize {
			for (; L <= R; ) {
				int V = (L + R) / 2;
				can(f, V) ? L = V + 1 : R = V - 1;
			}
		}
		cout << R << endl;
	}
};

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
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
