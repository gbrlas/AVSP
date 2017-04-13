#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iomanip>
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

const int N = 16;
const int I = 64;
int n;
int inp[N][4];
int mn[3], mx[3];

double ansall(double x, double y, double z)
{
    double ans = 0;
    for (int i = 0; i < n; ++ i)
        ans = max(ans, (abs(inp[i][0] - x) + abs(inp[i][1] - y) + abs(inp[i][2] - z)) / inp[i][3]);
    return ans;
}

double ansz(double x, double y)
{
    double l = mn[2], r = mx[2], m1, m2, ans1, ans2;
    for (int i = 0; i < I; ++ i)
    {
        m1 = (2 * l + r) / 3.0;
        m2 = (l + 2 * r) / 3.0;
        ans1 = ansall(x, y, m1);
        ans2 = ansall(x, y, m2);
        if (ans1 < ans2) r = m2;
        else l = m1;
    }
    return ans1;
}

double ansy(double x)
{
    double l = mn[1], r = mx[1], m1, m2, ans1, ans2;
    for (int i = 0; i < I; ++ i)
    {
        m1 = (2 * l + r) / 3.0;
        m2 = (l + 2 * r) / 3.0;
        ans1 = ansz(x, m1);
        ans2 = ansz(x, m2);
        if (ans1 < ans2) r = m2;
        else l = m1;
    }
    return ans1;
}

double ansx()
{
    double l = mn[0], r = mx[0], m1, m2, ans1, ans2;
    for (int i = 0; i < I; ++ i)
    {
        m1 = (2 * l + r) / 3.0;
        m2 = (l + 2 * r) / 3.0;
        ans1 = ansy(m1);
        ans2 = ansy(m2);
        if (ans1 < ans2) r = m2;
        else l = m1;
    }
    return ans1;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int __cases;
    cin >> __cases;
    for (int __cs = 1; __cs <= __cases; ++ __cs)
    {
        scanf("%d", &n);
        for (int i = 0; i < 3; ++ i)
        {
            mn[i] = INT_MAX;
            mx[i] = INT_MIN;
        }
        for (int i = 0; i < n; ++ i)
        {
            for (int j = 0; j < 4; ++ j)
                scanf("%d", &inp[i][j]);
            for (int j = 0; j < 3; ++ j)
            {
                mn[j] = min(mn[j], inp[i][j]);
                mx[j] = max(mx[j], inp[i][j]);
            }
        }
        printf("Case #%d: %lf\n", __cs, ansx());
    }
    return 0;
}
