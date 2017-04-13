#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LD long double
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int T, n;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    cin >> T;
    for (int TT = 1; TT <= T; TT ++)
    {
        cin >> n;
        int N = 0;
        for (int i = 1; i <= n; i ++)
        {
            int x; cin >> x;
            if (i - x) N ++;
        }
        printf("Case #%d: %.6lf\n", TT, (double) N);
    }
    return 0;
}
