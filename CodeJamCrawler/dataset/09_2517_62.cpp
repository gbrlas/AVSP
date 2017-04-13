
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



int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        int T[55];
        int n;
        scanf("%d",&n);
        // ---- Cleaning !!! ----
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        char buf[100];
        REP(i,n){
            scanf("%s",buf);
            int mx=0;
            REP(k,n) if(buf[k]=='1') mx=k;
            T[i]=mx;
        }
        int res=0;
        REP(i,n){
            int bs=i;
            FOR(j,i,n-1) if(T[j] <= i){ bs=j; break;}
            res+=bs-i;
            FORD(j,bs-1,i) T[j+1]=T[j];

        }
        printf("Case #%d: %d\n",zz+1,res);
    }
    return 0;
}
