//
//	Google CodeJam 2011 - Qualification Round, Problem C
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

#define FALSE   0
#define TRUE    1

int c [1000];

void main (void)
{
	int iCase, nCases;
    int i, n, total, sum, min;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d\n", &n);
        total = sum = 0;
        min = 1000001;
        for (i = 0; i < n; i++)
        {
            scanf ("%d ", &c[i]);
            total ^= c[i];
            sum += c[i];
            if (c[i] < min)
                min = c[i];
        }
        if (total != 0)
            printf ("Case #%d: NO\n", iCase);
        else
            printf ("Case #%d: %d\n", iCase, sum - min);
	}
}
