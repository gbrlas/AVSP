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
/* Prewritten code ends */

const int maxN = 1111;
int a[maxN];
int main() {
	int T, n, s;
	SCI(T);
	FOR(cs,1,T) {
		SCI(n);
		s = 0;
		REP(i,n) SCI(a[i]), s ^= a[i];
		printf("Case #%d: ", cs);
		if(s) printf("NO\n"); else printf("%d\n",accumulate(a,a+n,0)-*min_element(a,a+n));
	}
	return 0;
}
