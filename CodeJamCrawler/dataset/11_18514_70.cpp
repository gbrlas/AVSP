#include <cstdio>

int main()
{
    freopen("a.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int  nc, n, pp;
    char p1[105], p2[105], bt[105];
    char rr;

    scanf("%d", &nc);
    for (int h=1; h<=nc; h++)
    {
        scanf("%d", &n);
        int t1=1, t2=1;
        for (int i=1; i<=n; i++)
        {
            scanf(" %c%d", &rr, &pp);
            if (rr == 'O')
            {
                bt[i] = 1;
                p1[t1++] = pp;
            }
            else
            {
                bt[i] = 2;
                p2[t2++] = pp;
            }
        }
        int i, j, k, t;
        int tag;
        int d1, d2;
        k = 1;
        t = 0;
        i = j = 1;
        t1 = t2 = 1;
        d1 = d2 = 1;
        while (k <= n)
        {
            t++;
            tag = 0;

            if (t1 != p1[i])
                t1 += d1;
            else if (bt[k] == 1)
            {
                k++;
                i++;
                tag = 1;
                if (p1[i] > p1[i-1]) d1 = 1;
                else                 d1 = -1;
            }

            if (t2 != p2[j])
                t2 += d2;
            else if (bt[k] == 2 && !tag)
            {
                k++;
                j++;
                if (p2[j] > p2[j-1]) d2 = 1;
                else                 d2 = -1;
            }
        }
        printf("Case #%d: %d\n", h, t);
    }
}
