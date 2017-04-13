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

int P;
ll M[1<<11], cost[1<<11];

ll D(int id,int upper) {
    int lv=0;
    for (; ;lv++) if (1<<lv<=id && id<1<<(lv+1)) break;
    if (lv==P) return 0;

    ll res=1LL<<40;
    int left=(id<<(P-lv))&((1<<P)-1);
    int right=((id<<(P-lv))|((1<<(P-lv))-1))&((1<<P)-1);
    FOREQ(j,left,right) if (P-M[j]>=P-lv+upper) goto NEXT;
    res=min(res,D(id*2,upper)+D(id*2+1,upper));
NEXT:
    res=min(res,cost[id]+D(id*2,upper+1)+D(id*2+1,upper+1));
    return res;
}

int main()
{
    int T;
    cin>>T;
    while (T--) {
        cin>>P;
        REP(j,1<<P) cin>>M[j];
        DEC(lv,P-1) REP(j,1<<lv) cin>>cost[(1<<lv)+j];

        static int test=1;
        printf("Case #%d: %lld\n",test++,D(1,0));
    }
}
