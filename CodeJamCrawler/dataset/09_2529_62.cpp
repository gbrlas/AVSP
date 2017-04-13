
// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
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
typedef pair<int,int> PI;
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

const int nmx=16,kmx=30;

bool G[1<<nmx];

int E[nmx];
int T[nmx][kmx];
int n,k;
int F[1<<nmx];

int fun(int m){
    if(m==0) return 0;
    if(F[m]!=-1) return F[m];
    int r=n;
    for (int s = 0; ; s = (((s^m)-1)&m)^m){
        if(s==0) continue;
        if(G[s])
        r=min(r, 1 + fun (m ^ s));
        if(s==m) break;
    }
    return F[m]=r;
}


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        CLR(E,0);
        scanf("%d%d",&n,&k);
        REP(y,n)
            REP(x,k) scanf("%d",T[y]+x);
        REP(a,n)
            REP(b,n){
                bool ok=1;
                if(a!=b){
                    REP(i,k-1)
                    {
                        ok&=T[a][i]!=T[b][i];
                        ok&=T[a][i+1]!=T[b][i+1];
                        if(T[a][i] < T[b][i])
                            ok&=T[a][i+1]<T[b][i+1];
                        else
                            ok&=T[a][i+1]>T[b][i+1];
                    }
                }
                if(ok) E[a]|=(1<<b);
            }

        CLR(G,0);
        REP(m,1<<n){
            G[m]=1;
            REP(i,n) if(m&(1<<i)) G[m]&= ((E[i]&m)==m);
        }
        
        CLR(F,-1);
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        
   

        printf("Case #%d: %d\n",zz+1,fun((1<<n)-1));
    }
    return 0;
}
