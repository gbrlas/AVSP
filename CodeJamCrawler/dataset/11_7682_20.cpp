#include <stdio.h>
#include <math.h>

int main()
{
    int t, pd, pg, c = 0, flag;
    long long n;
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%d%d", &n, &pd, &pg);
        if (pd < 100 && pg == 100 || pd != 0 && pg == 0)
            printf("Case #%d: Broken\n", ++c);
        
        else
        {
            flag = 0;
            n = (n < 100 ? n : 100);
            while (n > 0)
            {
                double tmp = (double)n * pd / 100;
                if (fabs(tmp - (int)tmp) < 1e-12)
                {
                    printf("Case #%d: Possible\n", ++c);
                    flag = 1;
                    break;
                }
                --n;
            }
            if (!flag)
                printf("Case #%d: Broken\n", ++c);
        }
    }
    
    return 0;
}
