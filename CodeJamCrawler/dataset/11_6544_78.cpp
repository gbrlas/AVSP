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
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (ll i=0; i<(ll)(n); ++i)
#define FOR(i,k,n) for (ll i=(k); i<(ll)(n); ++i)
#define FOREQ(i,k,n) for (ll i=(k); i<=(ll)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (ll)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

char s[520][520];
ll cell[3][520][520];
ll sum[3][520][520];

void solve() {
        // force ll
    ll Y, X, D; scanf("%lld%lld%lld", &Y, &X, &D);
    REP(i, Y) scanf("%s", s[i]);

    REP(y, Y) REP(x, X) {
        ll w = D+(s[y][x]-'0');
        cell[0][y][x] = w;
        cell[1][y][x] = y*w;
        cell[2][y][x] = x*w;
    }

    MEMSET(sum, 0LL);
    REP(r, 3) FOREQ(y, 1, Y) FOREQ(x, 1, X) {
        sum[r][y][x] = sum[r][y-1][x] + sum[r][y][x-1] - sum[r][y-1][x-1] + cell[r][y-1][x-1];

            //cout<<"#"<<y<<" "<<x<<" "<<r<<"     "<<sum[r][y][x]<<endl;
    }

    ll res = -666;
    REP(y, Y) REP(x, X) {
        FOREQ(k, 3, 520) {
            if (k+y > Y || k+x > X) break;
            ll param[3];
            REP(r, 3) {
                param[r] = sum[r][k+y][k+x]-sum[r][k+y][x]-sum[r][y][k+x]+sum[r][y][x];
                param[r] -= cell[r][k-1+y][k-1+x]+cell[r][k-1+y][x]+cell[r][y][k-1+x]+cell[r][y][x];
            }
            //cout<<"#"<<y<<" "<<x<<" "<<k<<"     "<<param[0]<<" "<<param[1]<<" "<<param[2]<<endl;
            // bool f1 = (param[1] / param[0] == y+(k-1)/2)
            bool f1 = (2*param[1]  == param[0]*(2*y+k-1));
            bool f2 = (2*param[2]  == param[0]*(2*x+k-1));
            if (f1 && f2) res = max(res, k);
        }
    }

    if (res == -666LL) puts("IMPOSSIBLE");
    else printf("%lld\n", res);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve();
    }
}
