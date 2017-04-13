
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
const int nmx=1003;
int T[nmx];
int L[nmx];
LL WAS[nmx];

int main(){
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        CLR(L, -1);
        LL res=0;
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        int n,r;
        LL k; 
        scanf("%d%lld%d",&r,&k,&n);
        REP(i,n){ scanf("%d",T+i); assert(T[i] <= k); }
        int round=0;
        int x=0;
        while(round < r){
            if(L[x] != -1 ){
                  LL tury = (r-round) / (round-L[x]);
                  res+= (LL)tury * (res-WAS[x]);
                  round+= tury * (round-L[x]);
            }
            if(round >=r) break;
            WAS[x]=res;
            L[x]=round;
            LL sum = T[x];
            int y=(x+1)%n;
            while(y!= x && sum+T[y] <=k) {sum+=T[y]; y=(y+1)%n;}
            //printf("%d x:%d y:%d k:%lld n:%d %lld\n",round,x,y,k,n, sum);
            res+=sum;
            x=y;
            round++;
        }


        printf("Case #%d: %lld\n",zz+1, res);
    }
    return 0;
}
