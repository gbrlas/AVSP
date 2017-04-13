#include <stdio.h>
#include <string.h>

int main()
{

    int t, c, d, n, i, j, k, m, top, ca = 0;
    char cb[36][4], op[28][3], s[101], buf[101];
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &c);
        for (i = 0; i < c; ++i)
            scanf("%s", cb[i]);
        scanf("%d", &d);
        for (i = 0; i < d; ++i)
            scanf("%s", op[i]);
        scanf("%d%s", &n, s);
        
        top = j = 0;
        buf[top++] = s[j++];

        for (i = 1; i < n; ++i)
        {
            buf[top++] = s[j++];
            for (k = 0; k < c; ++k)
                if (cb[k][0] == buf[top-1] && cb[k][1] == buf[top-2] ||
                        cb[k][0] == buf[top-2] && cb[k][1] == buf[top-1])
                {
                    top -= 2;
                    buf[top++] = cb[k][2];
                }

            for (k = 0; k < d; ++k)
                for (m = 0; m < top - 1; ++m)
                    if (op[k][0] == buf[m] && op[k][1] == buf[top-1] ||
                            op[k][0] == buf[top-1] && op[k][1] == buf[m])
                        top = 0;
        }
        
        printf("Case #%d: [", ++ca);
        for (i = 0; i < top - 1; ++i)
            printf("%c, ", buf[i]);
        if (top > 0)
            printf("%c]\n", buf[i]);
        else
            printf("]\n");
    }

    return 0;
}
