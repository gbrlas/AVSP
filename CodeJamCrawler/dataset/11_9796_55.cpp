/*
 * File:   с.cc
 * Author: cain
 *
 * Created on 8 Май 2011 г., 1:56
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
int main(int argc, char** argv)
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int z;
    cin >> z;
    for (int t = 1; t <= z; ++ t)
    {
        int n;
        int q = 10000000;
        int r = 0;
        int s = 0;
        int x;
        cin >> n;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> x;
            q = min(q, x);
            r ^= x;
            s += x;
        }
        if (r == 0)
            cout << "Case #" << t << ": " << s - q << endl;
        else
            cout << "Case #" << t << ": " << "NO" << endl;
    }
    return (EXIT_SUCCESS);
}

#endif
