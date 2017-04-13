#include <stdio.h>

int main()
{
    int t, n, l, h, i, j, a[100], c = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &l, &h);
        for (i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (i = l; i <= h; ++i)
        {
            for (j = 0; j < n; ++j)
                if (a[j] % i != 0 && i % a[j] != 0)
                    break;
            
            if (j == n) break;
        }
        
        if (i <= h)
            printf("Case #%d: %d\n", ++c, i);
        else
            printf("Case #%d: NO\n", ++c);
    }
    
    return 0;
}
