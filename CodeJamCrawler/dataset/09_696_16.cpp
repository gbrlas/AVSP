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

int valid(int N,int V[50]) {
	FOR(i,1,N)
		if(V[i]>i) return false;
	return true;
}

int main (void) {
	int TC=1,NC; scanf("%d",&NC);
	while(NC--) {
		int N; scanf("%d",&N);
		
		int V[50]; _m(V,0);
		
		FOR(i,1,N) {
			char s[50]; scanf("%s",s);
			REP(j,N) V[i]=(s[j]=='1'?(j+1):V[i]);
		}
		
		int res=0;
		
//		FOR(i,1,N) printf("%d ",V[i]); puts("");
		
		FOR(i,1,N) {
			if(V[i]>i) {
				FOR(j,i+1,N)
					if(V[j]<=i) {
						int temp=V[j];
						for(int k=j;k>i;k--) {
							V[k]=V[k-1];
							res++;
						}
						V[i]=temp;
						break;
					}
			}
		}
		
		printf("Case #%d: %d\n",TC++,res);
	}
	return 0;
}
