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

vector<int> next[100][100];
int hgs[100][100];
bool sciek[100][100];
int f[10000];
char literka[10000];
int h, w;

int xi[4] = {-1, 0, 0, 1};
int yi[4] = {0, -1, 1, 0};

inline int inside(int x, int n) {
	return x >= 0 && x < n;
}

inline int encode(int x, int y) {
	return x*w + y;
}

int find_set(int x) {
	if(f[x] != x) f[x] = find_set(f[x]);
	return f[x];
}

inline void make_union(int a, int b) {
	a = find_set(a); b = find_set(b);
	if(a != b) f[a] = b;
}

void testcase() {
	scanf("%d%d", &h, &w);
	REP(i,h) REP(j,w) scanf("%d", &hgs[i][j]);
	REP(i,h) REP(j,w) sciek[i][j] = true;
	REP(i,h) REP(j,w) {
		f[ encode(i,j) ] = encode(i,j);
		literka[ encode(i,j) ] = 'X';
	}
	REP(i,h) REP(j,w) {
		int minimW = hgs[i][j];
		int minimR = -1;
		REP(ruch,4) if(inside(i+xi[ruch],h) && inside(j+yi[ruch],w)) {
			if(hgs[i+xi[ruch]][j+yi[ruch]] < minimW) {
				minimW = hgs[i+xi[ruch]][j+yi[ruch]];
				minimR = ruch;
			}
		}
		if(minimR != -1) {
			sciek[i][j] = false;
			make_union( encode(i,j), encode(i+xi[minimR], j+yi[minimR]) );
		}
	}
	char aktual = 'a';
	REP(i,h) REP(j,w) if( literka[ find_set(encode(i,j)) ] == 'X') {
		literka[ find_set(encode(i,j)) ] = aktual++;
	}
	REP(i,h) {
		REP(j,w) printf("%c ", literka[ find_set(encode(i,j)) ]);
		printf("\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i) {
		printf("Case #%d:\n", i);
		testcase();
	}
	return 0;
}