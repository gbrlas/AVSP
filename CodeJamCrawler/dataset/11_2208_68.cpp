/*
 * GCC version:			4.6.2
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
	
	struct walkway { int B, E, w; };
	
	void run() {
		int X, S, R, N;
		double t;
		cin >> X >> S >> R >> t >> N;
		vector<walkway> a(N);
		for (auto &v : a) cin >> v.B >> v.E >> v.w;
		sort(all(a), [](walkway p, walkway q) { return p.B < q.B; });
		double res = 0;
		parallelize {
			int x = 0;
			priority_queue<pii, vector<pii>, greater<pii>> Q;
			for (auto &v : a) {
				if (v.B != x) Q.push(pii(S, v.B - x));
				Q.push(pii(S + v.w, v.E - v.B));
				x = v.E;
			}
			R -= S;
			if (x != X) Q.push(pii(S, X - x));
			for (; !Q.empty(); ) {
				pii v = Q.top();
				Q.pop();
				double q = min(t, double(v.second) / (v.first + R));
				res += q;
				res += (v.second - q * (v.first + R)) / v.first;
				t -= q;
			}
		}
		cout << res << endl;
	}
};

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
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
