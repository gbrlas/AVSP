#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <complex>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define L 128
#define S 128
#define Q 1024
#define INF (1 << 20)

char buff[L + 1];
int qu[Q];
int dp[S];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int __it;
    fgets(buff, L, stdin); sscanf(buff, "%d", &__it);
    for (int __xx = 1; __xx <= __it; ++ __xx)
    {
        int s, q;
        map <string, int> msi;
        fgets(buff, L, stdin); sscanf(buff, "%d", &s);
        for (int i = 0; i < s; ++ i)
        {
            fgets(buff, L, stdin);
            msi[buff] = i;
        }
        fgets(buff, L, stdin); sscanf(buff, "%d", &q);
        for (int i = 0; i < q; ++ i)
        {
            fgets(buff, L, stdin);
            qu[i] = msi[buff];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < q; ++ i)
        {
            for (int j = 0; j < s; ++ j)
                dp[j] = min(dp[j], dp[qu[i]] + 1);
            dp[qu[i]] = INF;
        }
        int ans = INF;
        for (int i = 0; i < s; ++ i)
            ans = min(ans, dp[i]);
	printf("Case #%d: %d\n", __xx, ans);
    }
    return 0;
}

