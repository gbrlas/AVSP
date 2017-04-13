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
#define SCI(x)      scanf("%d",&x)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define SCS(x)      scanf("%s",x)
#define PII         pair<int,int>
#define MP          make_pair
#define X           first
#define Y           second
/* Prewritten code ends */

const int maxN = 505;
char s[maxN][maxN];
int main() {
	int T, R, C, D, res;
	SCI(T);
	FOR(cs,1,T) {
		res = 0;
		SCI(R); SCI(C); SCI(D);
		REP(r,R) SCS(s[r]);
		REP(rc,R) REP(cc,C) {
			FOR(k,1,min(min(rc,R-1-rc),min(cc,C-1-cc))) {
				PII acc = MP(0,0);
				FOR(r,rc-k,rc+k) FOR(c,cc-k,cc+k) if(abs(r-rc)!=k || abs(c-cc) != k) {
					acc.X += (r-rc)*(D+s[r][c]-'0');
					acc.Y += (c-cc)*(D+s[r][c]-'0');
				}
				if(acc == MP(0,0)) {
					res = max(res, k);
				}
			}
		}
		res = 2*res+1;
		for(int k = 1; k <= min(R,C)/2; k++) {
			REP(r,R-2*k+1) REP(c,C-2*k+1) {
				PII acc = MP(0,0);
				int realr = 2*(r+k), realc = 2*(c+k);
				REP(i,2*k) REP(j,2*k) {
					if(i == 0 && j == 0) continue;
					if(i == 0 && j == 2*k-1) continue;
					if(i == 2*k-1 && j == 0) continue;
					if(i == 2*k-1 && j == 2*k-1) continue;
					acc.X += (2*(r+i)+1-realr)*(D+s[r+i][c+j]-'0');
					acc.Y += (2*(c+j)+1-realc)*(D+s[r+i][c+j]-'0');
				}
				if(acc == MP(0,0)) res = max(res, 2*k);
			}
		}
		printf("Case #%d: ", cs);
		if(res >= 3) printf("%d\n",res);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
