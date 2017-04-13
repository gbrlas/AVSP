#include <string>	
#include <string.h>
#include <cstdio>	
#include <iostream>	
#include <memory>	
#include <cstdlib>	
#include <cmath>	
#include <algorithm>
#include <set>		
#include <map>		
#include <vector>
#include <ctime>	
#include <cassert>

using namespace std;

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define I64 "%I64d"
#else
#define I64 "%Ld"
#endif

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define fori(i,b,e) for(int i = (b); i < (e); i++)
#define forall(p,s) for(typeof((s).begin()) p = (s).begin(); p != (s).end(); p++)
#define memclr(a) memset((a), 0, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fi first
#define se second

typedef long double ldb;
typedef long long int64;
const int inf = (int)1e9;

#define PROBLEM_NAME ""

const int maxn = 8;
int be[maxn];
bool a[maxn][maxn];
vector<int> g[maxn];
bool was[maxn][maxn];
int col[maxn];
int n, cnt, ans;

inline int next(int x) { return (x+1)%n; }
inline int prev(int x) { return (x+n-1)%n; }

bool check () {
	static bool has[maxn];
	fori(i,0,cnt) {
		fori(j,0,ans) {
			has[j] = false;
		}
		fori(j,0,sz(g[i])) {
			has[col[g[i][j]]] = true;
		}
		fori(j,0,ans) {
			if (!has[j]) {
				return false;
			}
		}
	}
	return true;
}

bool iter (int p) {
	if (p == n) return check();
	fori(i,0,ans) {
		col[p] = i;
		bool good = iter(p+1);
		if (good) {
			return true;
		}
	}
	return false;
}

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		int m;
		scanf ("%d%d", &n, &m);
		memset(a,0,sizeof a);
		memset(was,0,sizeof was);

		fori(i,0,n) {
			a[i][(i+1)%n] = 1;
			a[(i+1)%n][i] = 1;
		}
		fori(i,0,m) {
			scanf ("%d", be+i);
		}
		fori(i,0,m) {
			int u = be[i], v;
			scanf ("%d", &v);
			u--; v--;
			a[u][v] = a[v][u] = 1;
		}
		cnt = 0;
		int mindeg = 100000;
		fori(i,0,n) {
			for(int j = next(i); j != prev(i); j = next(j)) {
				if (!a[i][j] || was[i][j]) continue;
				g[cnt].clear();
				int cur = i, nxt = j;
				was[i][j] = true;
				g[cnt].pb(i);
				while (nxt != i) {
					g[cnt].pb(nxt);
					int s = cur;
					cur = nxt;
					for (int k = prev(s); k != s; k = prev(k)) {
						if (a[nxt][k]) {
							nxt = k;
							break;
						}
					}
					was[cur][nxt] = true;
				}
				mindeg = min(mindeg, sz(g[cnt]));
				cnt++;
			}
		}
		printf ("Case #%d: ", tt);
		for(ans = mindeg; ans >= 0; ans--) {
			col[0] = 0;
			bool good = iter(1);
			if (good) {
				printf ("%d\n", ans);
				fori(i,0,n) {
					printf ("%d ", col[i]+1);
				}
				printf ("\n");
				break;
			}
		}
#if 0
		fori(i,0,cnt) {
			printf ("%d: ", i);
			fori(j,0,sz(g[i])) {
				printf ("%d ", g[i][j]);
			}
			printf ("\n");
		}
#endif
		
	}
	return 0;
}
