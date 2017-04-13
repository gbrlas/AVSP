#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int t, i, j, k;
    int n, p;
    int l, h;
    int note [10001];
    scanf ("%d", &t);
    for (i = 1; i <=t; i ++)
    {
        p = 0;
        scanf ("%d %d %d", &n, &l, &h);
        for (j = 0; j < n; j ++)
            scanf ("%d", &note [j]);
        for (j = l; j <= h; j ++)
        {
            for (k = 0; k < n; k ++)
            {
                if (j % note [k] && note [k] % j)
                    break;
            }
            if (k == n) 
            {
                p = 1; 
                break;
            }
        }
        if (j >= l && j <= h && p)
            printf ("Case #%d: %d\n", i, j);
        else
            printf ("Case #%d: NO\n", i);
    }
    return 0;
}
