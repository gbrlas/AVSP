#include <stdio.h>

static int c[1000];

int main(int argc, char **argv)
{
    FILE * file = fopen(argv[1], "r");
    int t, n, i, s, ca = 0, sum, min;

    fscanf(file, "%d", &t);
    while (t--)
    {
        fscanf(file, "%d", &n);
        for (i = s = sum = 0, min = 2000000; i < n; ++i)
        {
            fscanf(file, "%d", &c[i]);
            s ^= c[i];
            sum += c[i];
            if (min > c[i]) min = c[i];
        }
        if (s != 0)
            printf("Case #%d: NO\n", ++ca);
        else
            printf("Case #%d: %d\n", ++ca, sum - min);
    }

    return 0;
}
