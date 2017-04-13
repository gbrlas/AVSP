//
//	Google CodeJam 2011 - Qualification Round, Problem D
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


void main (void)
{
	int iCase, nCases;
    int i, n, num, count;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d\n", &n);
        count = 0;
        for (i = 1; i <= n; i++)
        {
            scanf ("%d ", &num);
            if (num != i)
                count++;
        }
        printf ("Case #%d: %f\n", iCase, (double) count);
	}
}
