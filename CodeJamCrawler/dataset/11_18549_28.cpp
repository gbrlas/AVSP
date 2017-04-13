#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int ncase, nc, n, l, h;
    int a[110];

    scanf("%d", &ncase);
    for (nc=1; nc<=ncase; nc++)
    {
        scanf("%d %d %d", &n, &l, &h);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);
        int i;
        for (i=l; i<=h; i++)
        {
            int j;
            for (j=0; j<n; j++)
            {
                if (a[j]%i != 0 && i%a[j] != 0)
                    break;
            }
            if (j >= n)
                break;
        }
        printf("Case #%d: ", nc);
        if (i <= h)
        {
            printf("%d\n", i);
        }
        else
            printf("NO\n");
    }
    return 0;
}
