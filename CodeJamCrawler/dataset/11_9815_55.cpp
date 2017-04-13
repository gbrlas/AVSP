/*
 * File:   d.cc
 * Author: cain
 *
 * Created on 8 Май 2011 г., 1:00
 */

#if 1

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#if defined(_MSC_VER) && _MSC_VER <= 1400
typedef __int64 LL;
#else
typedef long long LL;
#endif
typedef long double LD;
typedef istringstream iss;
typedef ostringstream oss;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, LD> pdd;
const LD eps = 1e-9;
const LL inf = 1000000000;


#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define dbg(x) cerr << #x << " = " << x << endl;

/*
 *
 */
LD sf[1001], f[1001], dp[1001];
int main(int argc, char** argv)
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cout.precision(10);
    cout.setf(ios::fixed);
/*    f[0] = 1;
    sf[0] = 1;
    int k = -1;
    for (int i = 1; i < 1001; ++ i)
    {
        f[i] = f[i - 1] / i;
        sf[i] = sf[i - 1] + k * f[i];
        k = - k;
    }
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < 1001; ++ i)
    {
        LD t1 = 1, t2 = 0;
        for (int j = 0; j < i; ++ j)
        {
            t1 += sf[j] * f[i - j] * dp[j];
            t2 += sf[j] * f[i - j];
        }
        dp[i] = t1 / t2;
        cout << i << " " << dp[i] << endl;
    }
    */
    int z;
    cin >> z;
    for (int t = 1; t <= z; ++ t)
    {
        int n;
        int q = 0;
        int x;
        cin >> n;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> x;
            if (x != i)
                q++;
        }
        cout << "Case #" << t << ": " << (LD) q << endl;
    }
    return (EXIT_SUCCESS);
}

#endif
