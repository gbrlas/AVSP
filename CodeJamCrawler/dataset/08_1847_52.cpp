
// Headers {{{
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<numeric>
using namespace std;


#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define REP(I,N) for(int I=0;I<(N);++I)
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();++I)
#define CLR(A,v) memset((A),v,sizeof((A)))

#define SIZE(x) ((int)((x).size()))
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef vector<int> VI;
typedef pair<int,int> PI;
typedef long long LL;
typedef vector<string> VS;
// }}}

const int inf=2000;
int POW_TREE[10006],max_pt=10002;
//+ fun_pt {{{
inline int fun_pt(int x)
{
	return (((x-1)^x)+1) >> 1;
}
//+ }}}
//+ update_pt {{{
void update_pt(int x,int vl)
{
	while (x <= max_pt) { POW_TREE[x]=min(POW_TREE[x],vl); x+=fun_pt(x);}	
}
//+ }}}
//+ pref_pt {{{
int pref_pt(int x)
{
	int res=inf;
	while(x) {res=min(POW_TREE[x],res); x-=fun_pt(x); }
	return res;
}
//+ }}}
const int fn=10002;
const int nmx=200;
map<string,int> M;
int A[nmx],B[nmx],n,nc,C[nmx];
VI K[nmx];

bool cmp(int a,int b){
	return A[a] > A[b];
}


int main()
{
	int z; scanf("%d",&z);
	REP(zz,z)
	{
		fprintf(stderr,"Working on %d / %d\n",zz+1,z);
		M.clear();
		REP(i,nmx) K[i].clear();
		scanf("%d",&n);
		char tmp[100];
		nc=0;
		REP(i,n){
			scanf("%s%d%d",tmp,A+i,B+i);
			if(M.find(tmp)!=M.end()) C[i]=M[tmp];
			else{
				M[tmp]=nc;
				C[i]=nc++;
			}
			K[C[i]].PB(i);
		}
		int res=inf;
		FOR(a,0,nc-1)
			FOR(b,a,nc-1)
			FOR(c,b,nc-1){
				VI ord;
//				printf("a:%d b:%d c:%d\n",a,b,c);
				FORE(i,K[a]) ord.PB(*i);
				if(a!=b)
				FORE(i,K[b]) ord.PB(*i);
				if(b!=c)
				FORE(i,K[c]) ord.PB(*i);
				sort(ALL(ord),cmp);
				FOR(i,1,fn) POW_TREE[i]=inf;
				POW_TREE[10001]=0;
				int m=SIZE(ord);
				REP(j,m){
					int v=ord[j];
		
					int cn=pref_pt(B[v]+1)+1;
//							printf("  v:%d %d %d cn:%d\n",v,A[v],B[v],cn);
	
					update_pt(A[v],cn);
				}
				res=min(res,pref_pt(1));
			}
		if (res==inf) 
		printf("Case #%d: IMPOSSIBLE",zz+1);
		else	printf("Case #%d: %d",zz+1,res);
		puts("");
		
	}
	return 0;
}
