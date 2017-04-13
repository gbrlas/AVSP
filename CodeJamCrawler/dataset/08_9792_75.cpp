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

inline double ta(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int __it;
    scanf ("%d", &__it);
    for (int __xx = 1; __xx <= __it; ++ __xx)
    {
        double f, R, t, r, g;
        scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
        if (g <= 2 * f)
        {
            printf("Case #%d: %.6lf\n", __xx, 1.0);
            continue;
        }
        double st = 2 * r + g, ir = R - t, rx1, rx2, ry1, ry2, rr = ir - f, rs = g - 2 * f;
        double ac = 0;
        double af = M_PI * R * R;
        double tx1, tx2, ty1, ty2, ra;
        for (int x = 0; ir > x * st; ++ x)
        {
            for (int y = 0; ir > y * st; ++ y)
            {
                rx1 = x * st + r + f;
                ry1 = y * st + r + f;
                rx2 = rx1 + rs;
                ry2 = ry1 + rs;
                if (rx1 * rx1 + ry1 * ry1 >= rr * rr)
                {
                    continue;
                }
                else if (rx2 * rx2 + ry2 * ry2 <= rr * rr)
                {
                    ac += rs * rs;
                    continue;
                }
                ra = 0.0;
                ty1 = sqrt(rr * rr - rx1 * rx1);
                if (ry1 <= ty1 && ty1 <= ry2)
                    tx1 = rx1;
                else
                {
                    tx1 = sqrt(rr * rr - ry2 * ry2);
                    ty1 = ry2;
                }
                tx2 = sqrt(rr * rr - ry1 * ry1);
                if (rx1 <= tx2 && tx2 <= rx2)
                    ty2 = ry1;
                else
                {
                    ty2 = sqrt(rr * rr - rx2 * rx2);
                    tx2 = rx2;
                }
                ra += abs(ta(tx1, ty1, rx1, ry2));
                ra += abs(ta(tx2, ty2, rx2, ry1));
                ra -= abs(ta(rx1, ry1, rx1, ry2));
                ra -= abs(ta(rx1, ry1, rx2, ry1));
                ra /= 2;
                ra += abs(atan2(ty1, tx1) - atan2(ty2, tx2)) * rr * rr / 2.0;
                ac += ra;
            }
        }
        printf("Case #%d: %.6lf\n", __xx, 1.0 - ac * 4.0 / af);
    }
    return 0;
}
