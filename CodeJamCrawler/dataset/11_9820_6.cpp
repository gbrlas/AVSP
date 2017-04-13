/*
 * File:   a.cc
 * Author: cain
 *
 * Created on 21 Май 2011 г., 5:00
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
char *q[] = {"Case #%d: Possible\n", "Case #%d: Broken\n"};
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}
int main(int argc, char** argv)
{
    freopen("a.in", "r", stdin);    freopen("a.out", "w", stdout);
    int t;
    cin >> t;
    for (int z = 0; z < t; ++ z)
    {
        int n, pd, pg;
        bool res = false;
        cin >> n >> pd >> pg;
        int mind = 100 / gcd(pd, 100);
        int minv = mind * pd / 100;
        int minl = mind - minv;
        if (n >= mind && 1000000 * pg >= minv && 1000000 * (100 - pg) >= minl)
            res = true;
        printf(q[!res], z + 1);
    }
    return (EXIT_SUCCESS);
}

#endif
