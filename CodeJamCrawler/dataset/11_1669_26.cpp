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

int s[1010][1010], x[1010][1010], y[1010][1010], a[1010][1010];
int n, m, d, o;

int checkodd(int L)
{
    int Half = L / 2;
    for (int i = Half + 1; i + Half <= n; i ++)
        for (int j = Half + 1; j + Half <= m; j ++)
        {
            int sum = s[i + Half][j + Half], v;
            sum -= s[i + Half][j - Half - 1];
            sum -= s[i - Half - 1][j + Half];
            sum += s[i - Half - 1][j - Half - 1];
            //x
            v = x[i + Half][j + Half];
            v -= x[i + Half][j - Half - 1];
            v -= x[i - Half - 1][j + Half];
            v += x[i - Half - 1][j - Half - 1];
            v -= sum * i;
            v -= (i - Half - i) * a[i - Half][j - Half];
            v -= (i - Half - i) * a[i - Half][j + Half];
            v -= (i + Half - i) * a[i + Half][j - Half];
            v -= (i + Half - i) * a[i + Half][j + Half];
            if (v) continue;
            //y
            v = y[i + Half][j + Half];
            v -= y[i + Half][j - Half - 1];
            v -= y[i - Half - 1][j + Half];
            v += y[i - Half - 1][j - Half - 1];
            v -= sum * j;
            v -= (j - Half - j) * a[i - Half][j - Half];
            v -= (j - Half - j) * a[i + Half][j - Half];
            v -= (j + Half - j) * a[i - Half][j + Half];
            v -= (j + Half - j) * a[i + Half][j + Half];
            if (v) continue;
            return 1;
        }
    return 0;
}

int checkeven(int L)
{
    int Half = L / 2;
    for (int i = Half; i + Half <= n; i ++)
        for (int j = Half; j + Half <= m; j ++)
        {
            double v;
            int sum = s[i + Half][j + Half];
            sum -= s[i + Half][j - Half];
            sum -= s[i - Half][j + Half];
            sum += s[i - Half][j - Half];
            //x
            v = x[i + Half][j + Half];
            v -= x[i + Half][j - Half];
            v -= x[i - Half][j + Half];
            v += x[i - Half][j - Half];
            v -= sum * (i + 0.5);
            v -= (i - Half + 1 - (i + 0.5)) * a[i - Half + 1][j - Half + 1];
            v -= (i - Half + 1 - (i + 0.5)) * a[i - Half + 1][j + Half];
            v -= (i + Half - (i + 0.5)) * a[i + Half][j - Half + 1];
            v -= (i + Half - (i + 0.5)) * a[i + Half][j + Half];
            if (v) continue;
            //y
            v = y[i + Half][j + Half];
            v -= y[i + Half][j - Half];
            v -= y[i - Half][j + Half];
            v += y[i - Half][j - Half];
            v -= sum * (j + 0.5);
            v -= (j - Half + 1 - (j + 0.5)) * a[i - Half + 1][j - Half + 1];
            v -= (j - Half + 1 - (j + 0.5)) * a[i + Half][j - Half + 1];
            v -= (j + Half - (j + 0.5)) * a[i - Half + 1][j + Half];
            v -= (j + Half - (j + 0.5)) * a[i + Half][j + Half];
            if (v) continue;
            return 1;
        }
    return 0;
}
           
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int TT; scanf("%d", &TT);
    memset(s, 0, sizeof(s));
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (int T = 1; T <= TT; T ++)
    {
        printf("Case #%d: ", T);
        scanf("%d%d%d", &n, &m, &d);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
            {
                char c;
                cin >> c;
                a[i][j] = c - 48;
                s[i][j] = x[i][j] = y[i][j] = 0;
            }
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + i * a[i][j];
                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] + j * a[i][j];
            }
        o = -1;
        for (int ans = min(n, m); ans >= 3; ans --)
        {
            int flag;
            if (ans % 2)
                flag = checkodd(ans);
            else flag = checkeven(ans);
            if (flag)
            {
                o = ans;
                break;
            }
        }
        if (o == -1)
            printf("IMPOSSIBLE\n");
        else printf("%d\n", o); 
    }
    return 0;
}
