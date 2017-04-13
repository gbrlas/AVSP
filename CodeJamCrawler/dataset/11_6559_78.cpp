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

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

const ll PN=3000000;
vector<int> prime;

void solve() {
    ll N; scanf("%lld", &N);
    ll res = 0;

    FOREQ(p, 2, PN) if (prime[p]) {
        ll cur=p*p;
        for (; cur<=N; cur*=p) res++;
    }
    if (N>=2) res++;

    printf("%lld\n", res);
}

int main()
{
    // Sieve of Eratosthenes
    prime = vector<int>(PN, 1);
    for (ll i=2; i*i<=PN; ++i) {
        if (!prime[i]) continue;
        for (ll j=i*2; j<=PN; j+=i) prime[j]=0;
    }

    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve();
    }
}
