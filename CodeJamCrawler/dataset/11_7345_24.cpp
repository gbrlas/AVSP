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

#define PROBLEM_NAME "D"
char s[200];
int64 m, v;

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		dbg(tt);
		printf ("Case #%d: ", tt);
		scanf ("%s", s);
		int n = strlen(s);
		reverse(s,s+n);
		m = 0;
		v = 0;
		fori(i,0,n)  {
			if (s[i] == '?') {
				m |= 1LL << i;
			} else
			if (s[i] == '1') {
				v |= 1LL << i;
			}
		}
		int64 res, sq;
		for (int64 sub = m; ; sub = (sub-1) & m) {
//			dbg(sub);
			res = v | sub;
			sq = (int64)(roundl(sqrtl(res)));
			if (res == sq*sq || res == (sq-1)*(sq-1) || res == (sq+1)*(sq+1)) {
				fori(i,0,n) {
					printf ("%d", int((res >> (n-i-1)) & 1));
				}
				printf ("\n");
				break;
			}
			if (sub == 0) {
				assert(false);
			}
		}
	}
	return 0;
}
