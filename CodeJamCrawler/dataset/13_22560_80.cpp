// fas.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int palindrm(int d);

int main()
{
    int t=0, a=0, b=0, x=0, y=0;

    scanf("%d", &t);

    for (x=1; x<=t; ++x)
    {
        y=0;
        scanf("%d%d", &a, &b);

        int l=(int)sqrt((float)a);
        if (l*l < a)
        {
            ++l;
        }

        for (; l*l<=b; ++l)
        {
            if (palindrm(l) && palindrm(l*l))
            {
                ++y;
            }
        }

        printf("Case #%d: %d\n", x, y);
    }

	return 0;
}

int palindrm(int d)
{
    char str[30], str1[30];

    itoa(d, str, 10);
    strcpy(str1, str);

    if (0 == strcmp(str, strrev(str1)))
    {
        return 1;
    }

    return 0;
}
