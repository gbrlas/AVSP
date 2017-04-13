
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
const int bmx=30;
char B[bmx];


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----


        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        printf("Case #%d: ",zz+1);
        scanf("%s",B);
        int n=strlen(B);
        bool ok=0;
        FORD(i,n-1,0){
            int best=-1;
            FOR(j,i+1,n-1){
                if( B[i] < B[j] ){
                    if (best==-1 || B[j] < B[best])
                        best=j;
                }
            }
            if(best==-1) continue;
            ok=1;
            swap(B[i],B[best]);
            sort(B+i+1,B+n);
            printf("%s\n",B);
            break;
        }
        if(!ok){
            int mn=0;
            REP(i,n) if(B[i] < B[mn] && B[i] != '0') mn=i;
            swap(B[mn],B[0]);
            printf("%c0",B[0]);
            sort(B+1,B+n);
            printf("%s\n",B+1);
        }
    }
    return 0;
}
