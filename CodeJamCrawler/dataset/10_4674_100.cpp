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

int D[2][513][513][515];

int main()
{
    int T;
    cin>>T;
    while (T--) {
        int H,W;
        cin>>H>>W;
        vector<vector<int> > v(H,vector<int>(W,0));
        REP(y,H) {
            string s;
            cin>>s;
            REP(k,SZ(s)) {
                int bit=0;
                if ('0'<=s[k]&&s[k]<='9') bit=s[k]-'0';
                else bit=s[k]-'A'+10;
                REP(b,4) {
                    int x=4*k+b;
                    if (bit&(1<<(3-b)))
                        v[y][x]=1;
                    if ((y+b)%2) v[y][x]=1-v[y][x];
                }
            }
        }
        //REP(y,H) { REP(x,W) cout<<v[y][x]; cout<<endl; }
        MEMSET(D,0);
        REP(b,2) REP(y,H) REP(x,W) if (v[y][x]==b) D[b][y][x][1]=1;
        REP(b,2) {
            FOREQ(sz,2,min(H,W)) {
                REP(y,H-sz+1) {
                    REP(x,W-sz+1) {
                        if (D[b][y][x][sz-1]==0) continue;
                        FOR(j,0,sz) if (v[y+j][x+sz-1]!=b||v[y+sz-1][x+j]!=b) goto NEXT;
                        D[b][y][x][sz]=1;
                        //printf("#%d %d %d %d\n",b,y,x,sz);
NEXT:;
                    }
                }
            }
        }
        int res[513];
        MEMSET(res,0);
        vector<vector<int> > cut(H,vector<int>(W,0));
        for (int sz=min(H,W); sz>=1; --sz) {
            REP(y,H-sz+1) {
                REP(x,W-sz+1) {
                    if (D[0][y][x][sz]==0&&D[1][y][x][sz]==0) continue;
                    REP(j,sz) REP(k,sz) if (cut[y+j][x+k]) goto NEXT2;
                    res[sz]++;
                    REP(j,sz) REP(k,sz) cut[y+j][x+k]=1;
NEXT2:;
                }
            }
        }
        int num=0;
        DEC(sz,min(H,W))
            if (res[sz]) ++num;
        static int test=1;
        printf("Case #%d: %d\n",test++,num);
        DEC(sz,min(H,W)) {
            if (res[sz]) printf("%d %d\n",sz,res[sz]);
        }
    }
}

