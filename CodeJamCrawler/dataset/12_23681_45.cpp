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



const double eps = 1.0e-11;
const double pi = acos(-1.0);


int Surprise(int x) {
	if (x == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}
	return (x + 4) / 3;
}


int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	REP(t, T) {
		int n, s, p;
		cin >> n >> s >> p;
		vector<int> data(n);
		REP(i, n) {
			cin >> data[i];
		}
		int res = 0;
		REP(i, n) {
			if ((data[i] + 2) / 3 >= p) {
				++res;
				continue;
			}
			if (s > 0 && Surprise(data[i]) >= p) {
				++res;
				--s;
			}
		}
		printf("Case #%lld: %d\n", t + 1, res);
	}
	return 0;
}