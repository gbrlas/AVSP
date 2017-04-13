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
	
	int n, m, D;
	char a[555][555];
	
	int s[555][555];
	ll sx[555][555], sy[555][555];
	
	inline int sum(int x0, int y0, int x1, int y1) {
		int res = s[x1][y1] + s[x0][y0] - s[x1][y0] - s[x0][y1];
		--x1, --y1;
		return res + a[x0][y0] + a[x1][y1] + a[x0][y1] + a[x1][y0];
	}
	inline ll sumx(int x0, int y0, int x1, int y1) {
		ll res = sx[x1][y1] + sx[x0][y0] - sx[x1][y0] - sx[x0][y1];
		--x1, --y1;
		res += (a[x0][y0] + a[x0][y1]) * (2 * x1 + 1);
		res += (a[x1][y0] + a[x1][y1]) * (2 * x0 + 1);
		return res;
	}
	inline ll sumy(int x0, int y0, int x1, int y1) {
		ll res = sy[x1][y1] + sy[x0][y0] - sy[x1][y0] - sy[x0][y1];
		--x1, --y1;
		res += (a[x0][y0] + a[x1][y0]) * (2 * y1 + 1);
		res += (a[x0][y1] + a[x1][y1]) * (2 * y0 + 1);
		return res;
	}
	
	bool check(int x0, int y0, int k) {
		int x1 = x0 + k, y1 = y0 + k;
		int S = sum(x0, y0, x1, y1);
		return 
			sumx(x0, y0, x1, y1) == S * ll(x0 + x1) &&
			sumy(x0, y0, x1, y1) == S * ll(y0 + y1);
	}
	
	void run() {
		cin >> n >> m >> D;
		CL(s, 0);
		CL(sx, 0);
		CL(sy, 0);
		REP (i, n) {
			scanf("%s", a[i]);
			REP (j, m) {
				a[i][j] -= '0';
				s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
				sx[i + 1][j + 1] = sx[i][j + 1] + sx[i + 1][j] - sx[i][j] + a[i][j] * (i * 2 + 1);
				sy[i + 1][j + 1] = sy[i][j + 1] + sy[i + 1][j] - sy[i][j] + a[i][j] * (j * 2 + 1);
			}
		}
		int res = 2;
		parallelize {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					for (int k = min(n - i, m - j); k > res; --k) {
						if (check(i, j, k)) {
							res = k;
							break;
						}
					}
				}
		}
		if (res < 3) puts("IMPOSSIBLE");
		else cout << res << endl;
	}
};

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
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
