#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define ROF(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define PER(i,a) ROF(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))
#define st first
#define nd second
#define LL long long

typedef pair<int,int> PII;

int main (void) {
	int TC; scanf("%d",&TC);
	REP(iTC,TC) {
		int res=0;
		int N; scanf("%d",&N);
		PII W[1000];
		REP(i,N) {
			scanf("%d %d",&W[i].st,&W[i].nd);
			REP(j,i) {
				res+=
					((W[i].st<W[j].st&&W[i].nd>W[j].nd)
					||
					(W[i].st>W[j].st&&W[i].nd<W[j].nd));
			}
		}
		printf("Case #%d: %d\n",(iTC+1),res);
	}
	return 0;
}
