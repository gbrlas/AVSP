#include <stdio.h>
#include <string.h>

int fit(char *s, int a, int e, int n)
{
    while (e <= n)
        s[a ++] = s[e ++];
    return n - (e - a);
}

int main(int argc, char **argv)
{
    int t, i;
    int c, d, n, j, k, a, e;
    char b;
    char base[4];
    char bases[256][256];
    char oppose[3];
    char opposes[256][256];
    char s[101];
    scanf ("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        for (j = 0; j < 256; j ++)
            for (k = 0; k < 256; k ++)
            {
                bases[j][k] = 0;
                opposes[j][k] = 0;
            }
        scanf ("%d", &c);
        for (j = 0; j < c; j ++)
        {
            scanf ("%s", base);
            bases[base[0]][base[1]] = base[2];
            bases[base[1]][base[0]] = base[2];
        }
        scanf ("%d", &d);
        for (j = 0; j < d; j ++)
        {
            scanf ("%s", oppose);
            opposes[oppose[0]][oppose[1]] = 1;
            opposes[oppose[1]][oppose[0]] = 1;
        }
        scanf ("%d", &n);
        scanf ("%s", s);
        a = 0;
        for (j = 1; j < n; j ++)
        {
            e = 0;
            if (bases[s[j]][s[a]])
            {
//                printf ("C: a=%d, j=%d, s[a]=%c, s[j]=%c, ", a, j, s[a], s[j]);
                s[a] = bases[s[j]][s[a]];
//                printf ("%s\n", s);
                e = 1;
            }
            else
            {
                for (k = a; k >= 0; k --)
                {
                    if (! s[k]) continue;
                    if (opposes[s[j]][s[k]])
                    {
                        a = -1;
//                        printf ("O: a=%d, j=%d, s[j]=%c, s[k]=%c, ", a, j, s[j], s[k]);
//                        printf ("%s\n", s);
                        e = 1;
                        break;
                    }
                }
            }
            if (!e)
                s[++a] = s[j];
        }
        s[++a] = s[j];
        printf ("Case #%d: [", i);
        if (strlen(s)) printf ("%c", s[0]);
        for (j=1; j<strlen(s); j ++)
            printf (", %c", s[j]);
        printf ("]\n");

    }
    return 0;
}
