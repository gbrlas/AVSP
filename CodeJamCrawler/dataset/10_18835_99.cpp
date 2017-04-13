#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/* Prewritten code begins */
#define LL          long long
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

const int maxN = 1024;
int g[2*maxN], nxt[maxN];
LL acc[maxN], ret;
int main() {
	int T, R, N, j, k, pos;
	scanf("%d",&T);
	FOR(cs,1,T) {
		scanf("%d%d%d",&R,&k,&N);
		REP(i,N) scanf("%d",&g[i]),g[N+i]=g[i];
		if((acc[0]=accumulate(g,g+N,0LL))<=k) { ret = acc[0]*R; goto C; }
		REP(i,N) {
			LL &x = acc[i]; x = g[i];
			for(j=1;x+g[i+j]<=k;++j) x += g[i+j];
			nxt[i] = (i+j)%N;
		}
		ret = 0;
		pos = 0;
		REP(i,R) { // tortoise without hare :-)
			ret += acc[pos];
			pos = nxt[pos];
		}
C:;		printf("Case #%d: %lld\n",cs,ret);
	}
	return 0;
}
