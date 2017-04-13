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

ll B[102], dp[100010];

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }

int main()
{
    int T;
    cin>>T;
    while (T--) {
        static int test=1;
        printf("Case #%d: ",test++);
        ll L; int N; cin>>L>>N;
        REP(j,N) cin>>B[j];
        sort(B,B+N);
        reverse(B,B+N);
        ll g=B[0];
        FOR(j,1,N) g=gcd(g,B[j]);
        if (L%g) {
            puts("IMPOSSIBLE");
            goto NEXT;
        }
        {
            dp[0]=0;
            FOR(j,1,100001) {
                ll r=1LL<<62;
                FOR(k,1,N) {
                    if (j-B[k]>=0) r=min(r,1+dp[j-B[k]]);
                }
                dp[j]=r;
            }
            ll res=1LL<<62;
            for (ll zero=L/B[0]; L-zero*B[0]<=100000; zero--) {
                res=min(res,zero+dp[L-zero*B[0]]);
            }
            printf("%lld\n", res);
        }
NEXT:;
    }
}
