//
//	Google CodeJam 2009 - Round 1C, Problem A
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//

// If the following defines are uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST
//#define DUMP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main (void)
{
	int iCase, nCases;
    char symb [61];
    __int64 result;
    int used  [36];
    int value [36];
    int i, j, n, first, base;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);

	for (iCase = 1; iCase <= nCases; iCase++)
	{
        scanf ("%s\n", symb);
        n = strlen (symb);
        #ifdef TEST
        printf ("%s\n", symb);
        #endif

        // convert
        for (i = 0; i < n; i++)
            if ((symb[i] >= '0') && (symb[i] <= '9'))
                symb[i] -= '0';
            else
                symb[i] = 10 + symb[i] - 'a';

        // find out the base
        for (i = 0; i < 36; i++)
            used[i] = 0;
        for (i = 0; i < n; i++)
            used[symb[i]] = 1;
        base = 0;
        for (i = 0; i < 36; i++)
            if (used[i])
                base++;
        if (base == 1)
            base = 2;
        #ifdef TEST
        printf ("base %d\n", base);
        #endif

        // assign the values
        for (i = 0; i < 36; i++)
            value[i] = -1;
        value [symb[0]] = 1;
        first = 1;
        j = 2;
        for (i = 1; i < n; i++)
        {
            if (value[symb[i]] == -1)
            {
                if (first)
                {
                    value[symb[i]] = 0;
                    first = 0;
                }
                else
                {
                    value[symb[i]] = j++;
                }
            }
        }
        #ifdef TEST
        for (i = 0; i < 36; i++)
            if (value[i] != -1)
                printf ("%c %d\n", (i < 10) ? (i + '0') : (i - 10 + 'a'), value[i]);
        #endif


        // calculate result
        result = 0;
        for (i = 0; i < n; i++)
            result = result*base + value[symb[i]];


        printf ("Case #%d: %I64d\n", iCase, result);
	}

}
