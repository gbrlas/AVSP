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

int v[2000640];

int main()
{
    int T;
    cin>>T;
    while (T--) {
        static int test=1;
        printf("Case #%d: ",test++);

        MEMSET(v,0);
        int N; cin>>N;
        REP(j,N) {
            int P,V; cin>>P>>V;
            P+=1000300;
            v[P]=V;
        }
        ll res=0;
        for (int cur=0; cur<2000600; ) {
            if (v[cur]>=2) {
                int move=v[cur]/2;
                res+=move;
                v[cur]-=move*2;
                v[cur-1]+=move;
                v[cur+1]+=move;
                cur--;
            } else cur++;
        }
        printf("%lld\n", res);
    }
}
