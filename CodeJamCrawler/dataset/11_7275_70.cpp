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

#define PROBLEM_NAME "c"

const int maxn = 2000;
int n;

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		scanf ("%d", &n);
		int minv = 10000*10000;
		int sum = 0, bx = 0;
		fori(i,0,n) {
			int x;
			scanf ("%d", &x);
			sum += x;
			bx ^= x;
			minv = min(x, minv);
		}
		printf ("Case #%d: ", tt);
		if (bx == 0) {
			printf ("%d\n", sum - minv);
		} else {
			printf ("NO\n");
		}
	}
	return 0;
}
