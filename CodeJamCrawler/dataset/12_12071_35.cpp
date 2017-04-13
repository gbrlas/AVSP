#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main ()
{
    //freopen("B-small-attempt1.in", "r", stdin);
    //freopen("B-small.txt", "w", stdout);
    int ca;
    scanf("%d", &ca);
    int K = 0;
    while (ca--)
    {
        int n, s, p, x;
        scanf("%d%d%d", &n, &s, &p);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if (x >= 3 * p - 2)
            {
                res++;
            }
            else if (x >= max(3 * p - 4, p) && s > 0)
            {
                res++;
                s--;
            }
        }
        printf("Case #%d: %d\n", ++K, res);
    }
    return 0;
}
