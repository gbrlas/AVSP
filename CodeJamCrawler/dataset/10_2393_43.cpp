
// headers {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}


const int pmx=1000000;
bool P[pmx];
void sito(int n){
    
	FOR(i,2,n-1)
		if(!P[i]){
			for(LL j=(LL)i*i;j<n;j+=i) P[j]=1;
		}
}

const int nmx=13;



LL power_mod(LL a, LL k, LL md){
    LL r = 1;
    while(k){
        if(k&1LL) r = (a*r)%md;
        a = (a*a)%md;
        k>>=1;
    };
    return r;
}

#define MODT LL
MODT modulo(MODT a,MODT n){
	if(a<0) a+= n*((-a)/n+1);
	return a%n;
}
int K[nmx];
int k,d;
int ok(int p){
    REP(i,k) if(K[i] >= p) return -1;    
    if( k==1) return -2;
    if( k==2){
        if(K[0]==K[1]) return K[0];
        if(K[0]!=0) return -2;
        return (K[1]*2)%p;
    }
    if(k>=3){
        LL now = (K[0]-K[1]+p)%p;
        LL now2= (K[1]-K[2]+p)%p;
        if(now==0){
            REP(i,k) if(K[i] !=K[0]) return -1;
            return K[0];



        }
        LL a= now2*power_mod(now,p-2,p);
        a%=p;
        LL b=modulo(K[1]-a*K[0], p);
        
        REP(i,k-1){
            if( (a*K[i] + b)%p != K[i+1]) return -1;
        }
        return (a*K[k-1]+b)%p;
    }
    assert(0);
    return p;
}

int main() {
    sito(pmx);

    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        scanf("%d%d",&d,&k);
        REP(i,k)scanf("%d",K+i);
        int x=1;
        REP(i,d) x*=10;
        set<int> S;
        FOR(p,2,x)
            if(!P[p]){
                int r=ok(p);
                if(r==-2){
                    S.insert(1);
                    S.insert(2);
                }
                else if(r!=-1)
                    S.insert(r);
            }

        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        printf("Case #%d: ",zz+1);
        if(SIZE(S)!=1)
            puts("I don't know.");
        else printf("%d\n",*S.begin());
    }
    return 0;
}
