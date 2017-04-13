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
#define PII         pair<int,int>
#define X           first
#define SCI(x)      scanf("%d",&x)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define PB          push_back
#define MP          make_pair
#define ALL(x)      (x).begin(),(x).end()
#define FORE(i,c)   for(VAR(i,(c).begin()); i!=(c).end(); ++i)
#define VAR(i,v)    __typeof(v) i=(v)
#define Y           second
/* Prewritten code ends */

const int maxN = 1010;
int b[maxN], e[maxN], w[maxN];
vector<PII > a;
int main() {
	int T, R, X, S, t, N, total;
	SCI(T);
	FOR(cs,1,T) {
		SCI(X); SCI(S); SCI(R); SCI(t); SCI(N);
		a.clear();
		total = X;
		REP(i,N) {
			SCI(b[i]); SCI(e[i]); SCI(w[i]);
			total -= e[i]-b[i];
			a.PB(MP(w[i], e[i]-b[i]));
		}
		a.PB(MP(0,total));
		sort(ALL(a));
	
		double rem = t, res = 0;
		FORE(i,a) {
			double tim1 = 1.*i->Y / (R+i->X);
			if(tim1 <= rem) {
				res += tim1;
				rem -= tim1;
			} else {
				res += rem;
				res += (i->Y-rem*(R+i->X))/(S+i->X);
				rem = 0;
			}
		}
		printf("Case #%d: ", cs);
		printf("%.7lf\n", res);
	}
	return 0;
}
