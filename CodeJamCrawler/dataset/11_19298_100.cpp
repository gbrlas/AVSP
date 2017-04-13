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
#define FORE(i,c)   for(VAR(i,(c).begin()); i!=(c).end(); ++i)
#define VAR(i,v)    __typeof(v) i=(v)
#define PB          push_back
#define SIZE(x)     (int)(x).size()
/* Prewritten code ends */

char s[1<<20];
int opposed[26][26];
char combine[26][26], tc;
int main() {
	vector<char> res;
	int T, C, D, N;
	SCI(T);
	FOR(cs,1,T) {
		REP(i,26) REP(j,26) combine[i][j] = '$';
		REP(i,26) REP(j,26) opposed[i][j] = 0;

		SCI(C);
		REP(i,C) {
			SCS(s);
			REP(j,2) combine[s[j]-'A'][s[1-j]-'A'] = s[2];
		}

		SCI(D);
		REP(i,D) {
			SCS(s);
			REP(j,2) opposed[s[j]-'A'][s[1-j]-'A'] = 1;
		}

		SCI(N);
		SCS(s);
		res.clear();
		REP(i,N) {
			if(!res.empty() && (tc = combine[res.back()-'A'][s[i]-'A']) != '$') res.back() = tc;
			else {
				int flag = 0;
				FORE(j,res) if(opposed[*j-'A'][s[i]-'A']) {
					res.clear();
					flag = 1;
					break;
				}
				if(!flag) res.PB(s[i]);
			}
		}
		printf("Case #%d: [",cs);
		REP(i,SIZE(res)) {
			if(i) printf(", ");
			printf("%c",res[i]);
		}
		printf("]\n");
	}
	return 0;
}
