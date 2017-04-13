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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int gcd(int a, int b)
{
    return (! b) ? a : gcd(b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int TT = 1; TT <= T; TT ++)
    {
        cout << "Case #" << TT << ": ";
        int pd, pg;
        LL N;
        cin >> N >> pd >> pg;
        if (pd < 100 && pg == 100 || pd > 0 && pg == 0)
        {
            cout << "Broken" << endl;
            continue;
        }
        int g = gcd(100, pd);
        if ((LL) (100 / g) <= N)
            cout << "Possible" << endl;
        else cout << "Broken" << endl;
    }
    return 0;
}
