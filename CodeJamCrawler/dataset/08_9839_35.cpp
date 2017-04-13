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

int n, m, a;

inline int orarea(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int __cases;
    cin >> __cases;
    for (int __cs = 1; __cs <= __cases; ++ __cs)
    {
        int f = 0;
        cin >> n >> m >> a;
        printf("Case #%d: ", __cs);
        for (int x2 = 0; x2 <= n && !f; ++ x2)
            for (int y2 = 0; y2 <= m && !f; ++ y2)
                for (int x3 = 0; x3 <= n && !f; ++ x3)
                    for (int y3 = 0; y3 <= m && !f; ++ y3)
                    {
                        if (abs(orarea(0, 0, x2, y2, x3, y3)) == a)
                        {
                            f = 1;
                            printf("%d %d %d %d %d %d\n", 0, 0, x2, y2, x3, y3);
                        }
                    }
        if (f == 0) printf("IMPOSSIBLE\n");
    }
    return 0;
}
