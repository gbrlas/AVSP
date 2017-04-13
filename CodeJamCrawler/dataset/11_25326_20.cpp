#include <stdio.h>

int gcd (int a, int b)
{
    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(int argc, char **argv)
{
    int t, i;
    long long int n, pd, pg;
    int min;
    scanf ("%d", &t);
    for (i = 1; i <= t; i ++)
    {
        scanf ("%lld %lld %lld", &n, &pd, &pg);
        if (pg == 100 && pd != 100)
            printf ("Case #%d: Broken\n", i);
        else if (pg == 0 && pd != 0)
            printf ("Case #%d: Broken\n", i);
        else
        {
            min = 100 / gcd (pd, 100);
            if (n < min)
                printf ("Case #%d: Broken\n", i);
            else
                printf ("Case #%d: Possible\n", i);
        }
    }
    return 0;
}
