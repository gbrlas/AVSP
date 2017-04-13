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

#define PROBLEM_NAME "C"

const int maxn = 1000*1000 + 100;
bool prime[maxn];
vector<int> p;

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	prime[2] = true;
	fori(i,3,maxn) {
		prime[i] = (i & 1) == 1;
	}
	p.pb(2);
	for(int i = 3; i < maxn; i += 2) {
		if (prime[i]) {
			p.pb(i);
//			printf ("%d ", i);
			int ti = i << 1;
			for(int j = i + ti; j < maxn; j += ti) {
				prime[j] = false;
			}
		}
	}
	fori(tt, 1, TT+1) {
		printf ("Case #%d: ", tt);
		int n;
		scanf ("%d", &n);
		if (n == 1) {
			printf ("%d\n", 0);
			continue;
		}
		int res = 1;
		fori(i,2,n+1) {
			if (prime[i]) {
				int k = i*i;
				while (k <= n) {
					res++;
					k *= i;
				}
			}
		}
		printf ("%d\n", res);
	}
	return 0;
}
