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
/* Prewritten code ends */

int main() {
	char s[20];
	int T, n, cur_time, last[2], pos[2], np;
	SCI(T);
	FOR(cs,1,T) {
		SCI(n);
		cur_time = 0;
		REP(i,2) last[i] = 0, pos[i] = 1;
		REP(i,n) {
			SCS(s); SCI(np);
			int id = s[0] == 'O' ? 0 : 1;
			int move_cost = max(0,abs(pos[id]-np)-(cur_time-last[id]));
			last[id] = (cur_time += move_cost + 1);
			pos[id] = np;
		}
		printf("Case #%d: %d\n",cs,cur_time);
	}
	return 0;
}
