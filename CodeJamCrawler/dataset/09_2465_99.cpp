
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
const int smx=103;
int h,w;
int P[smx*smx];
int PS[smx*smx];

int A[smx][smx];
int parent(int v){
    if(P[v]==v) return v;
    return P[v]=parent(P[v]);
}
inline bool ok(int y,int x){
    return x>=0 && x<w && y>=0 && y<h;
}


// STANDARD
const int DX[]={0,-1,1,0},DY[]={-1,0,0,1};


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        CLR(PS,-1);
        scanf("%d%d",&h,&w);    
        REP(y,h)REP(x,w){ scanf("%d",A[y]+x); P[y*w+x]=y*w+x;}
        int xt,yt,b;
        REP(y,h)REP(x,w){
            b=A[y][x]-1;
            REP(d,4){
                xt=x+DX[d];
                yt=y+DY[d];
                if (ok(yt,xt))
                    b=min(b,A[yt][xt]);
            }
            REP(d,4){
                xt=x+DX[d];
                yt=y+DY[d];
                if (ok(yt,xt) && A[yt][xt]==b){
                    P[parent(y*w+x)]=parent(yt*w+xt);
                    break;
                }
            }
        }
        printf("Case #%d:\n",zz+1);
        int us=0;
        REP(y,h){
            REP(x,w){
                if(x) printf(" ");
                int p=parent(y*w+x);
                if(PS[p]==-1) PS[p]=us++;
                printf("%c",PS[p]+'a');
            }
            puts("");
        }
        assert(us<='z'-'a'+1);
        fprintf(stderr,"US: %d\n",us);
    }
    return 0;
}

