#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-10;
const double pi = acos(-1.0);



int D, n;
void Solve() {
	cin >> n;
	vector<pair<int, int>> d(n), m(n);
	
	
	REP(i, n) {
		cin >> d[i].first >> d[i].second;
	}
	cin >> D;
	m[0] = mp(d[0].first, d[0].first);
	FOR(i, 1, n - 1) {
		FOR(j, 0, i - 1) {
			if (m[j].first + m[j].second >= d[i].first) {
				m[i] = mp(d[i].first, max(m[i].second, min(d[i].first - m[j].first, d[i].second)));
			}
		}
	}
	REP(i, n) {
		if (m[i].first + m[i].second >= D) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		printf("Case #%lld: ", test + 1);		
		Solve();
	}
	return 0;
}