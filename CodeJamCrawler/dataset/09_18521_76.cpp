//
//	Google CodeJam 2009 - Qualification Round, Problem C
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


char msg[] = "welcome to code jam";
char valid[] = "welcom tdja";



void main (void)
{
	int iCase, nCases;
    int nHits;
    char line1 [501];
    char line2 [501];
    char pos [19];
    int i, j;
#ifdef DUMP
    int k;
#endif

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);

	for (iCase = 1; iCase <= nCases; iCase++)
	{
        // get line
        gets (line1);

        // strip unwanted chars
        for (i = j = 0; line1[i] != 0; i++)
        {
            if (strchr (valid, line1[i]) != NULL)
                line2[j++] = line1[i];
            line2[j] = 0;
        }

        // find msg
        i = j = nHits = 0;
        while (1)
        {
            if (line2[i] == msg[j])
            {
                pos[j] = i;
                j++;
                if (msg[j] == 0)
                {
#ifdef DUMP
                    for (k = 0; k < 18; k++)
                        printf ("%d ", pos[k]);
                    printf ("\n");
#endif
                    nHits++;
                    if (nHits == 10000)
                        nHits = 0;
                    j--;
                }
            }
            i++;
            while (line2[i] == 0)
            {
                j--;
                if (j < 0)
                    break;
                i = pos[j] + 1;
            }
            if (j < 0)
                break;
        }

		printf ("Case #%d: %04d\n", iCase, nHits);
	}

}
