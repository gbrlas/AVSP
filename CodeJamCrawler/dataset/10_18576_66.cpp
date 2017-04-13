//
//	Google CodeJam 2010 - Qualification Round, Problem C
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


#define MAX_N   1000

typedef struct
{
    int g;
    int sum;
    int next;
} GROUP;

GROUP grp [MAX_N];

void main (void)
{
	int iCase, nCases;
    int R, k, N;
    int i, j;
    int total;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d %d %d\n", &R, &k, &N);
        total = 0;
        for (i = 0; i < N; i++)
        {
            scanf ("%d ", &grp[i].g);
            total += grp[i].g;;
        }

        // special cases
        if (total < k)
        {
            // everybody goes
            total = total * R;
        }
        else if (grp[0].g > k)
        {
            // first group does not fit
            total = 0;
        }
        else
        {
            for (i = 0; i < N; i++)
            {
                j = i;
                total = 0;
                while ((total + grp[j].g) <= k)
                {
                    total += grp[j].g;
                    if (++j >= N)
                        j = 0;
                }
                grp[i].sum = total;
                grp[i].next = j;
            }
            #ifdef DUMP
            for (i = 0; i < N; i++)
                printf ("%d %d %d %d\n", i, grp[i].g, grp[i].sum, grp[i].next);
            #endif

            total = 0;
            j = 0;
            for (i = 0; i < R; i++)
            {
                total += grp[j].sum;
                j = grp[j].next;
            }
        }
        printf ("Case #%d: %d\n", iCase, total);
	}
}
