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

bool v[2][112][112];

int main()
{
    int T;
    cin>>T;
    while (T--) {
        int R,N=102; cin>>R;
        MEMSET(v,false);
        REP(j,R) {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2; 
            FOREQ(x,x1,x2) FOREQ(y,y1,y2) v[0][y][x]=true;
        }
        int cur=0,tm=0;
        for (;;) {
            bool f=false;
            REP(y,N) REP(x,N) f=f||v[cur][y][x];
            if (!f) break;
            ++tm;
            cur=1-cur;
            FOREQ(y,1,N) FOREQ(x,1,N) {
                if (v[1-cur][y][x]) {
                    v[cur][y][x]=v[1-cur][y-1][x]||v[1-cur][y][x-1];
                } else {
                    v[cur][y][x]=v[1-cur][y-1][x]&&v[1-cur][y][x-1];
                }
            }
        }
        static int test=1;
        printf("Case #%d: %d\n",test++,tm);
    }
}
