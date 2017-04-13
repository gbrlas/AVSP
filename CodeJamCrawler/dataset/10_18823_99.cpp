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
#define REP(i,n)    for(int i=0; i<(n); ++i)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
/* Prewritten code ends */

int main() {
	int p[32], N, K, T;
	REP(i,32) p[i] = 1<<i;
	scanf("%d",&T);
	FOR(cs,1,T) {
		scanf("%d%d",&N,&K);
		printf("Case #%d: %s\n",cs,((K&(p[N]-1))==p[N]-1)?"ON":"OFF");
	}
	return 0;
}
