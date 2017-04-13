
// {{{
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
int h,w;
const int wmx=13;
char A[wmx][wmx];



const int DX[]={0,1,0,-1},DY[]={1,0,-1,0};

set<VI> S;
queue<VI> Q;
queue<int> QI;

inline void norm(VI &v){
    sort(ALL(v));
}
int kloc;
bool B[wmx][wmx];
bool was[wmx][wmx];

inline bool ok(int y,int x){
    return y>=0 && x>=0 && y<h && x < w;
}

void decode(VI &v){
    CLR(B,0);
    REP(i,kloc) B[ v[i]/w ][v[i]%w]=1;
}
VI encode(){
    VI r;
    REP(y,h)REP(x,w) if(B[y][x]) r.PB( y*w + x);
    return r;
}


bool spoj(int p){
    CLR(was,0);
    queue<int> qx,qy;
    was[p/w][p%w]=1;
    qx.push(p%w);
    qy.push(p/w);
    int x,y,xt,yt;
    int r=0;
    while(!qx.empty()){
        r++;
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        REP(d,4){
            xt=DX[d]+x;
            yt=DY[d]+y;
            if(ok(yt,xt) && !was[yt][xt] && B[yt][xt]){
                was[yt][xt]=1;
                qx.push(xt);
                qy.push(yt);
            }
        }
    }   
    return kloc==r;
}

VI end;


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        kloc=0;
        end.clear();
        S.clear();
        while(!Q.empty()) Q.pop(),QI.pop();
        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        scanf("%d%d",&h,&w);
        REP(y,h) scanf("%s",A[y]);
        CLR(B,0); 
        VI start;
        REP(y,h)REP(x,w){
            if(A[y][x]=='o' || A[y][x]=='w') B[y][x]=1,kloc++;
        }
        start=encode();
        CLR(B,0);
         REP(y,h)REP(x,w){
            if(A[y][x]=='x' || A[y][x]=='w') B[y][x]=1;
        }
        end=encode();
#define ADD(v,d)  { if(S.find(v)==S.end()) {S.insert(v); Q.push(v); QI.push(d); } }
        ADD(start,0); 
        int res=-1;
        VI v;
        VI to;
        int dis;
        bool sp;
        while(!Q.empty()){
            v=Q.front();
            dis=QI.front();
            Q.pop();
            QI.pop();
            if(v==end){
                res=dis;
                break;
            }
            decode(v);
            sp=spoj(v[0]);
          //  printf("dis:%d sp:%d\n",dis,sp);
         //   REP(y,h){REP(x,w) printf("%d",B[y][x]); puts("");}
            bool dr[4];
            REP(y,h)REP(x,w) if(B[y][x]){
                int xt,yt;
                REP(d,4){
                    xt=x+DX[d];
                    yt=y+DY[d];
                    dr[d]= ok(yt,xt) && (!B[yt][xt] ) && (A[yt][xt]!='#');
                }
                REP(d,4){
                    xt=x+DX[d];
                    yt=y+DY[d];
                    if(dr[d] && dr[(d+2)%4]){
                        swap(B[y][x],B[yt][xt]);
                        if (sp ||spoj(yt*w+xt)){
                            to=encode();
                            ADD(to, dis+1);              
                        }
                        swap(B[y][x],B[yt][xt]);
                    }   
                }


            }




        }

        printf("Case #%d: %d\n",zz+1,res);
    }
    return 0;
}
