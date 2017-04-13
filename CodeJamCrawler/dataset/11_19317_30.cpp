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
#define VI          vector<int>
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define SCI(x)      scanf("%d",&x)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define SCS(x)      scanf("%s",x)
#define PB          push_back
#define FORE(i,c)   for(VAR(i,(c).begin()); i!=(c).end(); ++i)
#define VAR(i,v)    __typeof(v) i=(v)
/* Prewritten code ends */

const int maxN = 101000, maxM = 101;
int p[32], len[maxN], used[maxN];
char w[maxN][12], pat[111];
VI cand, ncand;
int main() {
	REP(i,32) p[i] = 1<<i;
	int T, N, M, mask, nmask, tres;
	SCI(T);
	FOR(cs,1,T) {
		SCI(N); SCI(M);
		REP(i,N) {
			SCS(w[i]);
			len[i] = strlen(w[i]);
			used[i] = 0;
			REP(j,len[i]) used[i] |= p[w[i][j]-'a'];
		}
		printf("Case #%d:", cs);
		REP(np,M) {
			SCS(pat);
			int res = 0, idx = 0;
			REP(nw,N) {
				cand.clear(); mask = used[nw]; tres = 0;
				REP(i,N) if(i != nw && len[i] == len[nw]) {
					cand.PB(i);
					REP(j,len[i]) mask |= used[i];
				}
				int cur_used = 0;
				for(int i = 0; i < 26 && mask; i++) if(mask & p[pat[i]-'a']) {
					cur_used |= p[pat[i]-'a'];
					if(!(used[nw] & p[pat[i]-'a'])) {
						tres++; 
					}
					ncand.clear(); nmask = used[nw];
					FORE(k,cand) {
						int ok = 1, let;
						REP(kk,len[nw]) if(cur_used & p[let = w[*k][kk]-'a']) {
							if(w[*k][kk] != w[nw][kk]) { ok = 0; break; }
						} else if(cur_used & p[w[nw][kk]-'a']) { ok = 0; break; }
						if(ok) {
							ncand.PB(*k);
							nmask |= used[*k];
						}
					}
					cand = ncand; mask = nmask;
				}
				if(tres > res) {
					res = tres;
					idx = nw;
				}
			}
			printf(" %s", w[idx]);
		}
		printf("\n");
	}
	return 0;
}
