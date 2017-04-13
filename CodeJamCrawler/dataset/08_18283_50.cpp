//
//	Google CodeJam - Qualification Round, Problem A
//	DQuadros
//
//	Tested with Microsoft Visual C++ v6
//	(but should run with other compilers with 32bit ints!)
//

// If the following define is uncommented:
// - Uses test files instead of standard input/output
// - Enables debug printfs
//#define TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Search Engines
#define MAX_ENGINES 100
int nS;
char Engines [MAX_ENGINES][101];
int order[MAX_ENGINES];

// Insert a search engine
// (good old insertion sort)
void InsertEngine (char *name)
{
    int i;

    strcpy (Engines[nS], name);
    for (i = nS; i > 0; i--)
        if (strcmp (Engines[order[i-1]], name) <= 0)
            break;
    if (i < nS)
        memmove (order+i+1, order+i, (nS-i)*sizeof(int));
    order[i] = nS;
}

// Find a search engine
// (good old binary search)
int FindEngine (char * name)
{
    int first, last, mid, dif;

    first = 0;
    last = nS-1;
    while (last >= first)
    {
        mid = (last+first)/2;
        dif = strcmp (Engines[order[mid]], name);
        if (dif == 0)
            return mid;
        else if (dif < 0)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;  // not found
}


#ifdef TEST
void DumpEngines (void)
{
    int i;

    for (i = 0; i < nS; i++)
        printf ("[%s]\n", Engines[order[i]]);
}
#endif


void main (void)
{
	int iCase, nCases;
    int S, Q, nQ;
	char name[101];
    char used [MAX_ENGINES];
    int se, unused;
    int nSwitches;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
        // Read the search engines names
        scanf ("%d\n", &S);
        for (nS = 0; nS < S; nS++)
        {
    		gets (name);
            InsertEngine (name);
        }

#ifdef TEST
        DumpEngines ();
#endif

        // Process the queries
        nSwitches = 0;
        unused = nS;
        memset (used, ' ', MAX_ENGINES);
        scanf ("%d\n", &Q);
        for (nQ = 0; nQ < Q; nQ++)
        {
    		gets (name);
            se = FindEngine (name);
#ifdef TEST
            printf ("[%s] = %d\n", name, se);
#endif
            if (se != -1)
            {
                if (used[se] == ' ')
                {
                    if (unused == 1)
                    {
                        // must switch
    #ifdef TEST
                        printf ("--- SWITCH ---\n", name, se);
    #endif
                        nSwitches++;
                        unused = nS;
                        memset (used, ' ', MAX_ENGINES);
                    }
                    used[se] = '*';
                    unused--;
                }
            }
        }


		printf ("Case #%d: %d\n", iCase, nSwitches);
	}

}
