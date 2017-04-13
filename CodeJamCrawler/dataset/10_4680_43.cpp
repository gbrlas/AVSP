#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int v[60][60];

int main()
{
    int T;
    cin>>T;
    while (T--) {
        int N; cin>>N;
        REP(y,N) REP(x,y+1) cin>>v[y-x][x];
        FOR(x1,1,N) REP(x,N-x1) cin>>v[N-1-x][x1+x];

        //REP(y,N) { REP(x,N) cout<<v[y][x]; cout<<endl; } 

        int res=1<<29;
        FOREQ(sz,0,105) {
            int K=N+sz;
            REP(ay,sz+1) REP(ax,sz+1) {
                REP(iy,N) REP(ix,N) {
                    int y=ay+iy,x=ax+ix;
                    int uy[4],ux[4];

                    uy[1]=x,ux[1]=y;
                    int sd=(K-1)-(y+x);
                    uy[2]=y+sd, ux[2]=x+sd;
                    uy[3]=ux[2],ux[3]=uy[2];
                    FOREQ(j,1,3) {
                        if (ay<=uy[j]&&uy[j]<ay+N && ax<=ux[j]&&ux[j]<ax+N) {
                            if (v[y-ay][x-ax]!=v[uy[j]-ay][ux[j]-ax]) {
                                //cout<<sz<<","<<ay<<","<<ax<<","<<iy<<","<<ix<<endl;
                                //cout<<"#"<<y<<","<<x<<","<<uy[j]<<","<<ux[j]<<endl;
                                goto AGAIN;
                            }
                        }
                    }
                }
                res=K;
                goto ANS;
AGAIN:;
            }
        }
ANS:
        static int test=1;
        printf("Case #%d: %d\n",test++,res*res-N*N);
    }
}
