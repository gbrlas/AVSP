/*
 * File:   d-s.cc
 * Author: cain
 *
 * Created on 22 Май 2011 г., 13:38
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
    freopen("c.in", "r", stdin);    freopen("c.out", "w", stdout);
    int t;
    cin >> t;
    for (int z = 0; z < t; ++ z)
    {
        int n, l, h;
        cin >> n >> l >> h;
        vector<int> ns(n);
        for (int i = 0; i < n; ++ i)
        {
            cin >> ns[i];
        }
        int res = 0;
        for (int i = l; i <= h; ++ i)
        {
            int c;
            for (c = 0; c < n; ++ c)
                if ((ns[c] % i) && (i % ns[c]))
                    break;
            if (c == n)
            {
                res = i;
                break;
            }
        }
        if (res)
            cout << "Case #" << z + 1 << ": " << res << endl;
        else
            cout << "Case #" << z + 1 << ": NO\n";
    }
    return (EXIT_SUCCESS);
}

#endif
