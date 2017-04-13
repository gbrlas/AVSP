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
#define LET(x,a) typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1
typedef unsigned long long LL;
const int mod = 1e4;

int main()
{
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        char str[1001];
        while(cin.getline(str, 1001) && !isalpha(str[0]))
            ;
        int dp[21] = {0};
        string pat = "welcome to code jam";
        printf("Case #%d: ", nc);
        dp[0] = 1;
        int len = strlen(str);
        FORZ(i, len)
            for(int j = pat.SZ-1; j >= 0; --j)
            {
                if(pat[j] == str[i])
                    dp[j+1] += dp[j], dp[j+1] %= mod;
            }
        printf("%04d\n", dp[19]);
    }
}
