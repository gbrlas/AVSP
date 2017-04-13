#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define _m(a,b) memset(a,b,sizeof(a))

int main (void) {
	int T; scanf("%d",&T);
	FOR(iT,1,T) {
		int R,K,N; scanf("%d %d %d",&R,&K,&N);
		int G[2001]; REP(i,N) { scanf("%d",&G[i]); G[N+i]=G[i]; }
		
		/**
		 * Total Sales From Index
		 * End Group Index From Index
		 */
		int TS[1001]; REP(i,N) TS[i]=-1;
		int EndToGroup[1001];
		
		REP(i,N) {
			int total=0;
			int nG;
			for(nG=i;nG<i+N&&total+G[nG]<=K;nG++)
				total+=G[nG];
			TS[i]=total;
			EndToGroup[i]=(nG%N);
		}
		/**************************************************/
		
		/**
		 * Find Circle
		 * C : Length Of Cycle
		 * CTS : Total Sales Of Cycle
		 * FC : Flag Of Cycle
		 */
		int nGC[1001]; _m(nGC,0);
		int nG=0;
		int no=0;
		while(nGC[nG]==0) {
			nGC[nG]=(++no);
			nG=EndToGroup[nG];
		}

		int C=no-nGC[nG]+1;
		int CTS=0;
		int FC[1001]; _m(FC,0);
		REP(iC,C) {
			CTS+=TS[nG];
			FC[nG]=1;
			nG=EndToGroup[nG];
		}
		/**************************************************/
		
		/**
		 * Grand Total Of Sales
		 */
		int res=0;
		int iGroupNow=0;
		while(R>0&&FC[iGroupNow]==0) {
			R--;
			res+=TS[iGroupNow];
			iGroupNow=EndToGroup[iGroupNow];
		}
		
		res+=((int)R/C)*CTS;
		R%=C;
		
		while(R>0) {
			R--;
			res+=TS[iGroupNow];
			iGroupNow=EndToGroup[iGroupNow];
		}
		/**************************************************/
		
		printf("Case #%d: %d\n",iT,res);
	}
	return 0;
}
