
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

const LL mod=1000000007;
const int bmx=73;
const int maxmem = 10000;
LL n;
int k, m;
LL T[bmx][bmx*bmx][bmx];
LL TR[2][bmx][bmx*bmx];
LL SL[bmx];
int X[bmx];
LL F[bmx][maxmem][bmx];




const int dmx=103;
LL DW[dmx][dmx];

void initDW(){
	CLR(DW,0);
	DW[0][0]=1;
	FOR(y,1,dmx-1)
		FOR(x,0,y){
			DW[y][x]=DW[y-1][x]+((x)?DW[y-1][x-1]:0);	
            DW[y][x]%=mod;
		}
}

LL fun(int x,int sum,int ile){
    assert(sum<maxmem);
    if(x==m){
        if(ile) return 0;
        if(sum) return 0;
        return 1;
    }
    if(F[x][sum][ile] !=-1) {assert(F[x][sum][ile]!=-1); return F[x][sum][ile];}
    LL res=0;
    FOR(s,0,ile*k) if((s+sum)%k == X[x]){
        // bez zera
        LL moz = 0;
        FOR(i,1,k) moz += T[ile][s][i];
        moz%=mod;
        if(x)
        moz= ((moz%mod)*SL[ile])%mod;
       //printf("ile:%d s:%d %lld\n",ile,s,moz);
      
        FOR(u,0,ile){
            res = (res +(((moz*DW[ile][u])%mod)*fun(x+1, (s+sum)/k, u))%mod)%mod;
            assert(res>=0);
        }
        
        // z zerem
        if(ile){
            moz= T[ile][s][0];
            if(x)
                moz= ((moz%mod)*SL[ile])%mod;

            FOR(u,1,ile){
                LL wyn=( ((moz*DW[ile-1][ile-u])%mod)*fun(x+1, (s+sum)/k, u))%mod;
                res=(res+wyn)%mod;
//                printf("%%lld %lld %lld %lld\n",moz, DW[ile-1][ile-u] , wyn);
                assert(res>=0);
            }


        }
    }
    return F[x][sum][ile]=res;
}

int main() {
    initDW();
    SL[0]=1;
    FOR(i,1,bmx-1) SL[i]=(SL[i-1]*i)%mod;
    int z; scanf("%d",&z);
    REP(zz,z)
    {
      // ---- Cleaning !!! ----
        CLR(F,-1);
        scanf("%lld%d\n",&n,&k);
        m=0;
        while(n){
            X[m++]=n%k;
            n/=k;
        }

        CLR(T,0);
        T[0][0][k]=1;
        FOR(u,0,k-1)
            FOR(s,0,k*k)
                FOR(l,0,k)
                    if(T[u][s][l]){
                        REP(a,l)
                            T[u+1][s+a][a] = (T[u+1][s+a][a] + T[u][s][l])%mod;
                    }


        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        LL res=0;
        FOR(u,1,k){
            LL r= fun(0,0,u);
            res=(r+res)%mod;
        }
        res%=mod;

        printf("Case #%d: %lld\n",zz+1,res);
    }
    return 0;
}
