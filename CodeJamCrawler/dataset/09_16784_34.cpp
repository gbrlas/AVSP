/* Piotr Zielinski, Uniwersytet Jagiellonski */

#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it,V) for( __typeof(V.begin()) it = V.begin(); it != V.end(); ++it)
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()

typedef long long ll;

const int MAXN = 1000;
int ile[MAXN];
vector< pair<int, int> > last;
int result;

void przesun_w_prawo(int x) {
	if(last[x+1].FI > x) przesun_w_prawo(x+1);
	else if(last[x+1].FI >= last[x].FI) przesun_w_prawo(x+1);
	else {
		swap(last[x], last[x+1]);
		++result;
	}
}

void testcase() {
	int n;
	scanf("%d", &n);
	fill_n(ile,n,0);
	last.clear();
	REP(i,n) {
		char buf[100];
		scanf("%s", buf);
		int dal = -1;
		REP(j,n) if(buf[j] == '1') dal = j;
		last.PB(MP(i,dal));
	}
	int result = INT_MAX;
	do {
		bool ok = true;
		REP(i,n) if(last[i].SE > i) ok = false;
		if(!ok) continue;
		int tmp_result = 0;
		REP(i,n) REP(j,i) if(last[i].FI < last[j].FI) ++tmp_result;
		result = min(result, tmp_result);
	} while(next_permutation(ALL(last)));
	printf("%d\n", result);
}

int main() {
	int t;
	scanf("%d", &t);
	REP(i,t) {
		printf("Case #%d: ", i+1);
		testcase();
	}
	return 0;
}