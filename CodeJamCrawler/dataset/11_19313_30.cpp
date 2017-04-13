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
/* Prewritten code ends */

int main() {
	int T, n, pd, pg;
	SCI(T);
	FOR(cs,1,T) {
		SCI(n); SCI(pd); SCI(pg);
		printf("Case #%d: ", cs);
		if((pd > 0 && pg == 0) || (pd < 100 && pg == 100)) { printf("Broken\n"); continue; }
		int flag = 0;
		FOR(d,1,n) if(pd*d%100 == 0) {
			flag = 1;
			break;
		}
		printf("%s\n",flag ? "Possible" : "Broken");
	}
	return 0;
}
