#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m[1000], max = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
            scanf("%d", &m[j]);
        for (int j = 0; j < n-1; j++)
            for (int k = j + 1; k < n; k++)
                if (m[j] > m[k]) {
                    int temp = m[j];
                    m[j] = m[k];
                    m[k] = temp;
                }
        for (int j = 0; j < pow(2, n) - 1; j++) {
            int t = j, p = 0, b[100] = {}, c[100] = {};
            while (t) {
                b[p] = t % 2;
                c[p] = 1 - b[p];
                
                //printf("%d %d\n", b[p], c[p]);
                
                p++;
                t /= 2;
            }
            int bs = 0, cs = 0, bm = 0;
            for (int k = 0; k < n; k++) {
                if(b[k]) {
                    bs ^= m[k];
                    bm += m[k];
                } else
                    cs ^= m[k];
            }
            
            //printf("bm=%d\n", bm);
            
            if (bs == cs)
                if (bm > max)
                    max = bm;
        }
        if (max)
            printf("Case #%d: %d\n", i+1, max);
        else
            printf("Case #%d: NO\n", i+1);
    }
    return 0;
}
