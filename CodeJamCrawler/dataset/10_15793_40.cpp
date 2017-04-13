#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define dbg(x) cout << #x << " -> " << x << "\t" << flush;
#define dbge(x) cout << #x << " -> " << x << "\t" << endl;
#define LET(x,a) __typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1

const int mod = 100003;
int dp[502][502];

int ncr[502][502];

int NCR(int n, int r)
{
    if(n == r)
        return 1;
    if(r == 0)
        return 1;
    if(r > n)
        return 0;
    if(ncr[n][r] != -1)
        return ncr[n][r];
    return ncr[n][r] = NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int solve(int num, int rank)
{
    if(rank == 1)
        return 1;
    if(rank > num)
        return 0;
    int& ref = dp[num][rank];
    if(ref != -1)
        return ref;
    ref = 0;
    int d = num - rank + 1 - 2;
    for(int r = 1; r < rank; ++r)
    {
        int has = rank - r + 1 - 2;
        if(has <= d)
            ref = (ref + solve(rank, r)*NCR(d, has)) % mod;
    }
    return ref;
}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(ncr, -1, sizeof ncr);
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        int ans = 0;
        int n = GI;
        for(int r = 1; r <= n; ++r)
        {
            ans = (ans + solve(n, r))%mod;
        }
        printf("Case #%d: %d\n", nc, ans);
    }

}
