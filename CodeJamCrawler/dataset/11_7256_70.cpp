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
typedef pair<int,int> pii;
const int inf = (int)1e9;

#define PROBLEM_NAME "a"

const int maxn = 1000;
int n;
pii seq[maxn];
int pos[2], extr[2];

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		scanf ("%d", &n);
		char ss[5];
		int but;
		fori(i,0,n) {
			scanf ("%s%d", ss, &but);
			if ((string)ss == "O") {
				seq[i] = mp(0, but-1);
			} else {
				seq[i] = mp(1, but-1);
			}
		}
		pos[0] = pos[1] = 0;
		extr[0] = extr[1] = 0;
		int time = 0;
		fori(i,0,n) {
			int cur = seq[i].fi, an = 1 - cur, but = seq[i].se;
			int dif = abs(but - pos[cur]) - extr[cur];
			if (0 < dif) {
				time += dif;
				extr[an] += dif;
			}
			time++;
			extr[an]++;
			extr[cur] = 0;
			pos[cur] = but;
		}
		printf ("Case #%d: %d\n", tt, time);
	}
	return 0;
}
