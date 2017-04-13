//
//	Google CodeJam 2010 - Qualification Round, Problem A
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
    int N, K;
    int lOn, i, msk;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d %d\n", &N, &K);
        lOn = FALSE;
        msk = 1;
        for (i = 0; i < N; i++)
        {
            if ((K & msk) == 0)
            {
                lOn = FALSE;
                break;
            }
            lOn = TRUE;
            msk <<= 1;
        }


        printf ("Case #%d: %s\n", iCase, lOn ? "ON" : "OFF");
	}
}
