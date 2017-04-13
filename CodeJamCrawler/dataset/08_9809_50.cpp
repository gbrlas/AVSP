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

typedef long long ll;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int __it;
    scanf ("%d", &__it);
    for (int __xx = 1; __xx <= __it; ++ __xx)
    {
        ll n, A, B, C, D, x0, y0, M;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &A, &B, &C, &D, &x0, &y0, &M);
        vector <ll> v(9); 
        for (int i = 0; i < n; ++ i)
        {
            v[(x0 % 3) * 3 + y0 % 3] ++;
            x0 = (A * x0 + B) % M;
            y0 = (C * y0 + D) % M;
        }
        ll ans = 0;
        for (int i = 0; i < 9; ++ i)
            for (int j = i + 1; j < 9; ++ j)
                for (int k = j + 1; k < 9; ++ k)
                    if (((i / 3 + j / 3 + k / 3) % 3 == 0) &&
                        ((i % 3 + j % 3 + k % 3) % 3 == 0))
                            ans += v[i] * v[j] * v[k];
        for (int i = 0; i < 9; ++ i)
            ans += v[i] * (v[i] - 1) * (v[i] - 2) / 6;
        for (int i = 0; i < 9; ++ i)
            for (int j = i + 1; j < 9; ++ j)
            {
                if (((i / 3 + i / 3 + j / 3) % 3 == 0) &&
                    ((i % 3 + i % 3 + j % 3) % 3 == 0))
                    ans += v[i] * (v[i] - 1) * v[j] / 2;
                if (((i / 3 + j / 3 + j / 3) % 3 == 0) &&
                    ((i % 3 + j % 3 + j % 3) % 3 == 0))
                    ans += v[i] * v[j] * (v[j] - 1) / 2;
            }
        printf("Case #%d: %lld\n", __xx, ans);
    }
    return 0;
}
