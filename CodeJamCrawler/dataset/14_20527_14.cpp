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

double c,f,x;
double calc(int p){
	double t=0.5;
	double m=2;
	REP(i,p-1){
		m+=f;
		t+=1/m;
	}
	t=t*c+x/(m+f);
	return t;
}
double ans;
main(){
	freopen("in.txt","r",stdin);
	freopen("o.txt","w",stdout);
	DRI(t);
	int a=0;
	while (t--){
		cin>>c>>f>>x;
		ans=x/2;
		int fm=0;
		while (1){
			fm++;
			double t=calc(fm);
			if (t>ans) {fm--;break;}
			ans=t;
		}
		a++;
		printf("Case #%d: %.7f\n",a,ans);
	}
}
