#include <stdio.h>

int main (int argc, char **argv)
{
    int t, i;
    int r, c;
    int j, k;
    char grid [51][51];
    int possible;
    scanf ("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        possible = 1;
        scanf ("%d %d", &r, &c);
        for (j = 0; j < r; j ++)
            scanf ("%s", grid [j]);
        for (j = 0; j < r; j ++)
        {
            for (k = 0; k < c; k ++)
            {
                if (grid [j][k] == '#')
                {
//                    printf ("r=%d, c=%d\n", j, k);
                    if (grid [j][k + 1] != '#')
                    {
                        possible = 0;
                        break;
                    }
                    if (grid [j + 1][k] != '#')
                    {
                        possible = 0;
                        break;
                    }
                    if (grid [j + 1][k + 1] != '#')
                    {
                        possible = 0;
                        break;
                    }
                    grid [j][k] = '/';
                    grid [j][k+1] = '\\';
                    grid [j+1][k] = '\\';
                    grid [j+1][k+1] = '/';
                    k ++;
                }
            }
            if (! possible)
                break;
        }
        printf ("Case #%d:\n", i);
        if (! possible)
            printf ("Impossible\n");
        else
        {
            for (j = 0; j < r; j ++)
                printf ("%s\n", grid [j]);
        }
    }

    return 0;
}
