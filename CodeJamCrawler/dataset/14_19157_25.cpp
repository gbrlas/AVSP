#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long double ld;

ld solve()
{
    ld c, f, x;
    cin >> c >> f >> x;

    ld t = 0.;
    ld ret = x / 2.;
    for (int i = 1; i < x; ++i)
    {
        t += c / (2. + f * (i - 1));
        ret = min(ret, t + x / (2. + f * i));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout.precision(8);
        cout << "Case #" << i << ": " << fixed << solve() << endl;
    }

    return 0;
}
