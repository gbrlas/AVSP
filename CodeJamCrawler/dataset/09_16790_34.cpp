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

const int MAXN = 105;
bool edge[MAXN][MAXN];
vector<int> ciag[MAXN];
bool visited[MAXN];
int mate1[MAXN], mate2[MAXN];
int n, k;

bool jest(int a, int b) {
	REP(i,k) if(ciag[a][i] <= ciag[b][i]) return false;
	return true;
}

bool dfs(int v) {
	REP(i,n) if(edge[v][i] && !visited[i]) {
		visited[i] = true;
		if(mate2[i] == -1 || dfs(mate2[i])) {
			mate1[v] = i;
			mate2[i] = v;
			return true;
		}
	}
	return false;
}

int compute_bcm() {
	fill_n(mate1,n,-1);
	fill_n(mate2,n,-1);
	int result = 0;
	REP(i,n) {
		fill_n(visited,n,false);
		result += dfs(i);
	}
	return result;
}

void testcase() {
	scanf("%d%d", &n, &k);
	REP(i,n) {
		int x;
		ciag[i].clear();
		REP(j,k) {
			scanf("%d", &x);
			ciag[i].PB(x);
		}
	}
	REP(i,n) REP(j,n) edge[i][j] = false;
	REP(i,n) REP(j,n) if(jest(i,j)) edge[i][j] = true;
	printf("%d\n", n-compute_bcm());
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