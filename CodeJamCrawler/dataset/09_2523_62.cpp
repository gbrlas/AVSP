
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



int h,w,f;
const int wmx=53;
char A[wmx][wmx];
bool B[wmx][wmx][1<<12];
int G[wmx][wmx];
int DX[]={1,-1};

int popraw(int y,int mask){
    REP(x,w) if(A[y][x]=='.') mask|=(1<<x);
    REP(x,w) if(A[y+1][x]=='.') mask|=(1<<(x+w));
    return mask;
}
int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        scanf("%d%d%d",&h,&w,&f);
        REP(y,h)
            scanf("%s",A[y]);
        CLR(G,0);
        FORD(y,h-1,0)REP(x,w){
            if(A[y][x]=='#') G[y][x]=0;
            else G[y][x]=1+G[y+1][x];
        }
        CLR(B,0);

        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);  
        int res=0;
        bool rf=0;
        queue<int> X[2],Y[2],M[2];
        int ac=0,nx=1;
#define ADD(y,x,ms,q) {int mtmp=popraw(y,ms);  if(!B[y][x][mtmp]) { B[y][x][mtmp]=1; X[q].push(x); Y[q].push(y);\
    M[q].push(mtmp); } }
#define ok(x) ( (x) >= 0 && (x) < w )
        ADD(0,0,0,ac);
        int x,y,ms;
        for(;;){
            if( X[ac].empty()){
                swap(ac,nx);
                res++;
                if(X[ac].empty()) break;
                continue;
            }
            x=X[ac].front(); X[ac].pop();  
            y=Y[ac].front(); Y[ac].pop();
            ms=M[ac].front(); M[ac].pop();
            assert( ms & (1<<x));
            if(y==h-1) {
                rf=1;
                break;
            }

        
            if( ms&(1<<(x+w)) ){
                if(G[y+2][x]+1 <= f){
                    int nms=0;
                    if(G[y+2][x]==0) nms=ms>>w;
                    ADD(y+G[y+2][x]+1,x,nms,ac);
                }
            }else{
                REP(d,2){
                    int xt=x+DX[d];
                    if( ok(xt) && (ms&(1<<xt))){  
                        ADD(y,xt,ms,ac);
                        if (!(ms&(1<<(xt+w))))
                        ADD(y,x,ms|(1<<(xt+w)),nx); // kopiemy
                    }
                }
            }
        }
        printf("Case #%d: ",zz+1);
        if(rf){
            printf("Yes %d\n",res);
        }else printf("No\n");
    }
    return 0;
}
