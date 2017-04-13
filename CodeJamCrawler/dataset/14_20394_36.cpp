#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<vector<int> >    VVI;
typedef vector<char>            VC;

int main() {
	int tnum, ans1, ans2;
	int a[4][4], b[4][4];
	cin >> tnum;
	FOR(ti,1,tnum) {
		cin >> ans1;
		REP(i,4) REP(j,4)
			cin >> a[i][j];
		cin >> ans2;
		--ans1; --ans2;
		REP(i,4) REP(j,4)
			cin >> b[i][j];
		int same = 0;
		int num = -1;
		REP(i,4) {
			REP(j,4) {
				if (a[ans1][i] == b[ans2][j]) {
					++same;
					num = a[ans1][i];
				}
			}
		}
		if (!same)
			printf("Case #%d: Volunteer cheated!\n", ti);
		else if (same == 1)
			printf("Case #%d: %d\n", ti, num);
		else
			printf("Case #%d: Bad magician!\n", ti);
	}
    return 0;
}
