#include <stdio.h>

int main (int argc, char **argv)
{
    int t, i;
    int n, j, k, l;
    char team [101][101];
    int total [101];
    double wp [101];
    double wap [101];
    double owp [101];
    double oowp [101];
    scanf ("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        scanf ("%d", &n);
        for (j = 0; j < n; j ++)
        {
            total [j] = 0;
            wap [j] = 0;
            scanf ("%s", team [j]);
            for (k = 0; k < n; k ++)
            {
                switch (team [j][k])
                {
                    case '.':
                        break;
                    case '1':
                        wap [j] = wap [j] + 1;
                    case '0':
                        total [j] = total [j] + 1;
                        break;
                }
            }
            wp [j] = wap [j] / total [j];
        }
        for (j = 0; j < n; j ++)
        {
            owp [j] = 0;
            for (k = 0; k < n; k ++)
            {
                if (k == j) continue;
                switch (team [k][j])
                {
                    case '.':
                        break;
                    case '1':
                        owp [j] += (wap [k] - 1) / (total [k] - 1);
                        break;
                    case '0':
                        owp [j] += (wap [k]) / (total [k] - 1);
                        break;
                }
                //printf ("%d=%c, owp[%d]=%f, w=%f, t=%d\n", k, team [k][j], j, owp [j], wap[k], total[k]);
            }
            owp [j] /= total [j];
//            printf ("owp[%d]=%f\n", j, owp [j]);
        }
        for (j = 0; j < n; j ++)
        {
            oowp [j] = 0;
            for (k = 0; k < n; k ++)
            {
                switch (team [j][k])
                {
                    case '.':
                        break;
                    case '1':
                    case '0':
                        oowp [j] += owp [k];
                        break;
                }
            }
//            printf ("D: oowp[%d]=%f/%d=%f\n", j, oowp [j], total [j], (oowp [j] / (total [j] * 1.0)));
            oowp [j] /= total [j];
        }
        printf ("Case #%d:\n", i);
        for (j = 0; j < n; j ++)
            printf ("%.8g\n", (0.25 * wp [j] + 0.5 * owp [j] + 0.25 * oowp [j]));
    }
    return 0;
}
