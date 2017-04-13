
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
const int kmx=203;

int k, B[kmx][kmx];
int K[kmx][kmx];

inline void vertical(int x,int y,int &xt, int &yt,int kk){   
    xt=y;
    yt=x;
}

inline void hori(int x,int y,int &xt, int &yt,int kk){   
    xt= kk-1-y;
    yt= kk-1-x;
}

inline bool dog(int x,int y,int xt,int yt){
    if(K[y][x]==-1) {swap(x,xt), swap(y,yt);}
    if(K[y][x]==-1) return 1;
    if(K[yt][xt]==-1){
        K[yt][xt]=K[y][x];
        return 1;
    }
    return K[y][x]==K[yt][xt];
}

bool check(int kk){ 
    bool ok=1;
    REP(d,2){
        REP(y,kk){
            if(ok)
                REP(x,kk){
                    int xt,yt;
                    vertical(x,y,xt,yt,kk);
                    ok&=dog(x,y,xt,yt);
                    hori(x,y,xt,yt,kk);
                    ok&=dog(x,y,xt,yt);

                }
        }
    }
    return ok;
}



int main() {
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        scanf("%d",&k);
        FOR(y,1,2*k-1){
            if(y<=k)
                FOR(x,1,y) scanf("%d",&B[y-x][x-1]);
            else
                FOR(x,1,2*k-y) scanf("%d",&B[k-x][y-k -1+x]);
        }
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        int res=k;
        for(;;){
            bool ok=0;
            FOR(x,0,res-k){
                if(ok) break;
                FOR(y,0,res-k){
                    CLR(K,-1);
                    REP(xi,k)REP(yi,k) K[y+yi][x+xi]=B[yi][xi];
                    if(check(res)) ok=1;
                }
            }
            if(ok) break;
            res++;
        }
        printf("Case #%d: %d\n",zz+1, res*res - k*k);
    }
    return 0;
}
