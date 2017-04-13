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
#define FILL(a,v)   memset(a,v,sizeof(a))
/* Prewritten code ends */

const int maxN = 1001;
//long double res[maxN+1] = {0,0,2}, acc = 1;
int p[maxN], vis[maxN];
int main() {
/*
	FOR(i,3,maxN) {
		res[i] = (acc+1)/(i-1);
		if(i < 50) DEBUG(MP(i,res[i]));
		acc += res[i];
	}
*/
	int T, n, res;
	SCI(T);
	FOR(cs,1,T) {
		SCI(n);
		FOR(i,1,n) SCI(p[i]);
		FILL(vis,0);
		res = 0;
		FOR(i,1,n) if(!vis[i]) {
			int t = i, l = 0;
			while(!vis[t]) {
				vis[t] = 1;
				l++;
				t = p[t];
			}
			if(l > 1) res += l;
		}
		printf("Case #%d: %d.000000\n",cs,res);
	}
	return 0;
}
