//
//	Google CodeJam 2009 - Qualification Round, Problem A
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

// Dictionary
#define MAX_WORDS 5000
#define MAX_L     15
int nW = 0;
char Words [MAX_WORDS][MAX_L+1];
int order [MAX_WORDS];


// Compare words for qsort
int compWord (const void *elem1, const void *elem2)
{
    int i1 = *((int *) elem1);
    int i2 = *((int *) elem2);
    int dif = strcmp (Words[i1], Words[i2]);
    return dif;
}

// Find a partial Word
// (good old binary search)
int FindWordN (char *w, int n)
{
    int first, last, mid, dif;

    first = 0;
    last = nW-1;
    while (last >= first)
    {
        mid = (last+first)/2;
        dif = memcmp (Words[order[mid]], w, n);
        if (dif == 0)
            return mid;
        else if (dif < 0)
            first = mid + 1;
        else
            last = mid - 1;
    }
    return -1;  // not found
}


#ifdef DUMP
void DumpWords (void)
{
    int i;

    for (i = 0; i < nW; i++)
        printf ("[%s]\n", Words[order[i]]);
}
#endif


void main (void)
{
	int iCase, nCases;
    int L, D;
    char word [16];
    int nHits;
    char query [26*15+1];
    char qt [15] [27];
    int pos [15];
    int i, j, k;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d %d %d\n", &L, &D, &nCases);

    // Read the dictonary
    for (nW = 0; nW < D; nW++)
    {
    	gets (word);
        //InsertWord (word);
        strcpy (Words[nW], word);
        order[nW] = nW;
    }
    qsort (order, nW, sizeof(int), compWord);

#ifdef DUMP
    DumpWords ();
#endif

	for (iCase = 1; iCase <= nCases; iCase++)
	{
        // Process the query
  		gets (query);
#ifdef TEST
        printf ("[%s]\n", query);
#endif
        nHits = 0;
        for (i = j = 0; query[i] != 0; i++, j++)
        {
            if (query[i] == '(')
            {
                i++;
                for (k = 0; query[i] != ')'; i++, k++)
                    qt [j][k] = query[i];
                qt [j][k] = 0;
            }
            else
            {
                qt [j][0] = query [i];
                qt [j][1] = 0;
            }
        }

        i = 0;
        pos[0] = 0;
        word[L] = 0;
        while (1)
        {
            word[i] = qt[i][pos[i]];
            if (FindWordN (word, i+1) != -1)
            {
                if (i == (L-1))
                {
#ifdef DUMP
                    printf ("[%s]\n", word);
#endif
                    nHits++;
                }
                else
                {
                    i++;
                    pos[i] = -1;
                }
            }
            pos[i]++;
            while (qt[i][pos[i]] == 0)
            {
                i--;
                if (i < 0)
                    break;
                pos[i]++;
            }
            if (i < 0)
                break;
        }

		printf ("Case #%d: %d\n", iCase, nHits);
	}

}
