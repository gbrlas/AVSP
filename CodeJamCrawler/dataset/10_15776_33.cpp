#include <iostream>
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

int main()
{
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        int N = GI;
        typedef long long LL;
        LL dp[N+10];
        dp[0] = 0;
        for(int i = 1; i <= N; ++i)
        {
            dp[i] = dp[i - 1] + 1 + dp[i - 1];
        }
        LL X = dp[N] + 1;
        int K = GI;

        printf("Case #%d: ",nc);

        if(K % X == (X - 1))
            puts("ON");
        else
            puts("OFF");

    }
}
