#include <stdio.h>

int main(int argc, char *argv)
{
    int t, i;
    int n, j, m, d, sum, c;
//    int c[1001];
    scanf ("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        sum = 0;
        m = 0;
        d = 1000010;
        scanf ("%d", &n);
        for (j = 0; j < n; j ++)
        {
            scanf ("%d", &c);
            sum += c;
            d = c < d ? c : d;
            m ^= c;
        }
        if (m)
            printf ("Case #%d: NO\n", i);
        else
            printf ("Case #%d: %d\n", i, sum - d);
    }
    return 0;
}
