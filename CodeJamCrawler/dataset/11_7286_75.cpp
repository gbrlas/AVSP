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

#define PROBLEM_NAME "rpi"

const int maxn = 200;
int n;
char c[maxn][maxn];
int cnt[maxn], good[maxn], opps[maxn];
ldb wp[maxn], owp[maxn], oowp[maxn];

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		scanf ("%d", &n);
		fori(i,0,n) {
			scanf ("%s", c[i]);
		}
		fori(i,0,n) {
			good[i] = cnt[i] = opps[i] = 0;
		}
		fori(i,0,n) {
			fori(j,0,n) {
				if (c[i][j] == '.') continue;
				cnt[i]++;
				opps[i]++;
				if (c[i][j] == '1') good[i]++;
			}
			wp[i] = (ldb)good[i] / cnt[i];
		}
		fori(i,0,n) {
			ldb res = 0;
			fori(j,0,n) {
				if (c[i][j] == '.') continue;
				if (c[i][j] == '0') {
					res += (ldb)(good[j]-1) / (cnt[j]-1);
				} else {
					res += (ldb)good[j] / (cnt[j]-1);
				}
			}
			owp[i] = res / opps[i];
		}
		fori(i,0,n) {
			ldb res = 0;
			fori(j,0,n) {
				if (c[i][j] == '.') continue;
				res += owp[j];
			}
			oowp[i] = res / opps[i];
		}
		printf ("Case #%d:\n", tt);
		fori(i,0,n) {
			printf ("%.10lf\n", (double)(wp[i] + 2*owp[i] + oowp[i]) / 4);
		}
	}
	return 0;
}
