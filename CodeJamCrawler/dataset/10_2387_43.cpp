
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


const int nmx=103,rmx=1003;


bool B[2][nmx][nmx];


int main() {
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        int n;
        scanf("%d",&n);
        CLR(B,0);
        REP(i,n){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            FOR(y,y1,y2)FOR(x,x1,x2) B[0][y][x]=1;
        }
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        int a=1,l=0;
        int r=0;
        for(;;){
            CLR(B[a],0);
            int ile=0;
            FOR(y,1,100) FOR(x,1,100){
                if(B[l][y][x]){
                    if(B[l][y-1][x] || B[l][y][x-1])
                    {
                          B[a][y][x]=1, ile++;
                    }


                }else{
                    if(B[l][y-1][x] && B[l][y][x-1])
                    {  B[a][y][x]=1, ile++;}
                }

            }
            if(ile==0) break;
            r++;
            swap(a,l);
        }
        printf("Case #%d: %d\n",zz+1,r+1);
    }
    return 0;
}
