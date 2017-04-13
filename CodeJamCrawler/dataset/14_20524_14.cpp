    // #includes {{{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<math.h>
	#include<assert.h>
	#include<stdarg.h>
	#include<time.h>
	#include<limits.h>
	#include<ctype.h>
	#include<string>
	#include<map>
	#include<set>
	#include<queue>
	#include<algorithm>
	#include<vector>
	#include<iostream>
	#include<sstream>
	using namespace std;
	// }}}
	// #defines {{{
	#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
	#define SZ(x) ((int)(x).size())
	#define ALL(x) (x).begin(),(x).end()
	#define REP(i,n) for(int i=0;i<(n);i++)
	#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
	#define PER(i,n) for(int i=(n)-1;i>=0;i--)
	#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
	#define RI(x) scanf("%d",&x)
	#define DRI(x) int x;RI(x)
	#define RII(x,y) scanf("%d%d",&x,&y)
	#define DRII(x,y) int x,y;RII(x,y)
	#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
	#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
	#define RS(x) scanf("%s",x)
	#define PI(x) printf("%d\n",x)
	#define PIS(x) printf("%d ",x)
	#define CASET int ___T,cas=1;scanf("%d",&___T);while(___T--)
	#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
	#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
	#define MP make_pair
	#define PB push_back
	#define MS0(x) memset(x,0,sizeof(x))
	#define MS1(x) memset(x,-1,sizeof(x))

	#define F first
	#define S second
	typedef pair<int,int> PII;
	typedef long long LL;
	typedef unsigned long long ULL;
	// }}}
int o[20];
main(){
	freopen("in.txt","r",stdin);
	freopen("o.txt","w",stdout);
	DRI(t);
	int ca=0;
	while(t--){
		MS0(o);
		REP(q,2){
		DRI(a);
		REP(i,4){
			REP(j,4){
			DRI(c);
			if(i+1==a){
				o[c]++;
			}
			}
		}
		}
		int ans=0;
		REP1(i,1,16){
			if (o[i]==2){
				if (ans==0) ans=i;
				else ans=-1;
			}
		}
		ca++;
		printf("Case #%d: ",ca);
		if (ans==0)printf("Volunteer cheated!\n");
		else if (ans==-1) printf("Bad magician!\n");
		else printf("%d\n",ans);
	}
}
