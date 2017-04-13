
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

const int pmx=13;
int M[1<<pmx];
int p,n;
const LL inf=100000000000000LL;
LL C[1<<pmx];
LL T[pmx][1<<pmx];

int main() {
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
            scanf("%d",&p);
            n=1<<p;
        REP(i,n) scanf("%d",M+i);
        CLR(T,0);
        REP(i,n) FOR(j,M[i]+1,p) T[j][i+n]=inf;
        FORD(y,p-1,0) FOR(x,0,(1<<y)-1) scanf("%lld",C+ (1<<y)+x);
        FORD(i,n-1,1){
            FOR(j,0,p){
                if(j==p) T[j][i]=inf;
                else T[j][i] = T[j+1][i*2] + T[j+1][i*2+1];
                T[j][i] = min(T[j][i], C[i] + T[j][i*2] + T[j][i*2+1]);
                if(T[j][i] >inf) T[j][i]=inf;
            }
        }
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        printf("Case #%d: %lld\n",zz+1,T[0][1]);
    }
    return 0;
}
