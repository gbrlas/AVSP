#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)

int main (void) {
	int T; scanf("%d",&T);
	FOR(iT,1,T) {
		int N,K; scanf("%d %d",&N,&K);
		int C=(1<<N);
		printf("Case #%d: %s\n",iT,((K%C)==C-1?"ON":"OFF"));
	}
	return 0;
}
