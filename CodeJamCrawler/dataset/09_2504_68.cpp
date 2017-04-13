
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

int w,q;
const int wmx=33;
char T[wmx][wmx];
// STANDARD
const int DX[]={0,1,0,-1},DY[]={1,0,-1,0};

vector<map<PI,PI> > Q;
map<PI,int> WR;
vector< pair<PI,PI> > lev;

VI D[1024];
VI DV[1024];


int main()
{
    int z; scanf("%d",&z);
    REP(zz,z)
    {
        // ---- Cleaning !!! ----


        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        scanf("%d%d",&w,&q);
        REP(y,w) scanf("%s",T[y]);
        printf("Case #%d:\n",zz+1);
        REP(y,w)
            REP(x,w){
                int  p=y*32+x;
                D[p].clear();
                DV[p].clear();
                int xt,yt;
                REP(d,4){
                    xt=x+DX[d];
                    yt=y+DY[d];
                    if(xt<0 || xt>=w || yt<0 || yt>=w) continue;
                    D[p].PB(yt*32+xt);
                    if(T[y][x]!='-' && T[y][x]!='+') DV[p].PB(0);
                    else DV[p].PB((T[yt][xt]-'0')*((T[y][x]=='+')?1:-1));
                }
            }

        REP(qq,q){
            fprintf(stderr,"ANS %d / %d\n",qq,q);
            int look;
            scanf("%d",&look);
            Q.clear();
            Q.PB(map<PI,PI>());
#define ADD(p,w,fp,fw) { if (Q.back().find(MP((p),(w))) == Q.back().end()) Q.back()[MP((p),(w))]=MP((fp),(fw));}
            REP(y,w)REP(x,w)if(T[y][x]!='+' && T[y][x]!= '-')
                ADD(y*32+x,T[y][x]-'0',-1,0);
            int step=0;
            int found=0;
            while(found==0){
                
            if(step%100 == 0) fprintf(stderr,"Step %d\n",step);
                step++;
                Q.PB(map<PI,PI>());
                
                lev.clear();
                int was=0;
                int m=SIZE(Q)-2;
                int p,w;
                FORE(i,Q[m]){
                    p=i->FI.FI;
                    w=i->FI.SE;
                    lev.PB( MP( MP(WR[i->SE],T[p>>5][p&31]), i->FI ));
                }
                WR.clear();
                sort(ALL(lev));
                PI last;
                int k=0;
                FORE(i,lev){
                    if (i->FI != last) was++;
                    last=i->FI;
                    WR[i->SE]=was;
                    p=i->SE.FI;
                    w=i->SE.SE;
//                    printf("p:%d %d %d w:%d\n",p,p/32,p%32,w);
                    if(w==look){
                        found=1;
                        string res="";
                        PI pr;
                        while(m>=0){
                            res+=T[p/32][p&31];
                            pr=Q[m][MP(p,w)];
                            p=pr.FI;
                            w=pr.SE;
                            m--;
                        }
                        reverse(ALL(res));
                        printf("%s\n",res.c_str());
                        break;
                    }
                    k=SIZE(D[p]);
                    REP(d,k){
                        assert(D[p][d]!=p);

                        ADD(D[p][d],DV[p][d]+w,p,w);
                    }
                }
            }
        }
    }
    return 0;
}
