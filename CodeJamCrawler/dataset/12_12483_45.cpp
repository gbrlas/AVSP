#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class hyj{
    public : int x[5];
};

hyj a[110];

bool cmp(const hyj &a, const hyj &b)
{
    if (a.x[1] != b.x[1]) return a.x[1] < b.x[1];
    else return a.x[4] > b.x[4];
}

/*
bool pd(int q)
{
    if ((a[q].x[1] == 0) || ((a[q].x[1] != a[q].x[2]) && (a[q].x[3] != a[q].x[3]))) return false;
    return true;
}
*/

int main()
{
    freopen("B-small-attempt4.in", "r", stdin);
    freopen("B-small-attempt4.out", "w", stdout);
    int t, n, p, s, q;
    cin >> t;
    for (int i = 1; i <= t; i ++)
    {
        cin >> n >> s >> p;
        int j1 = 1, ans, j;
        for (j = 1; j <= n; j ++)
        {
            cin >> q;
            for (int k = 1; k <= 3; k ++) a[j1].x[k] = q / 3;
            a[j1].x[0] = q %= 3;
            for (int k = 1; k <= 3; k ++)
                if (q -- > 0) a[j1].x[k] ++;
            a[j1].x[4] = p - a[j1].x[1];
            if (a[j1].x[4] <= 1) j1 ++;
        }
        n = -- j1;
        sort(a + 1, a + 1 + n, cmp);
        for (j = 1; j <= n; j ++)
            if (a[j].x[1] >= p) break;
        if ((j != n) || (a[j].x[1] >= p)) j --;
        ans = n - j;
        for (int k = j; (k >= 1) && (s > 0); k --)
            if ((a[k].x[2] != 0) && (a[k].x[1] == a[k].x[2]))
            {
                ans ++;
                s --;
            }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
