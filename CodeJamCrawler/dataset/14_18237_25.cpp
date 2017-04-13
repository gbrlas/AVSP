#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <iomanip>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
#endif

    int test, t;

    double c, f, x, r;
    double elap, best;

    cin >> test;
    for (t = 1; t <= test; t++)
    {
        cin >> c >> f >> x;

        r = 2;
        elap = 0;
        best = x * 0.5;

        while (elap < best)
        {
            elap += c / r;
            r += f;
            best = min(best, elap + x / r);
        }

        cout << "Case #" << t << ": " << fixed;
        cout << setprecision(7) << best << endl;
    }

    return 0;
}
