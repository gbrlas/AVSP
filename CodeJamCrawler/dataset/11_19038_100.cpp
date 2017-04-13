//
//	Google CodeJam 2011 - Qualification Round, Problem B
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

char combine[27][27];
unsigned int opposed[27];

char list[100];
int size;
int qty[27];
unsigned int present;

void main (void)
{
	int iCase, nCases;
    int i, C, D, N;
    char c1, c2, c3;
    #ifdef DUMP
    int j;
    #endif

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
        scanf ("%d ", &C);
        memset (combine, 0, sizeof(combine));
        for (i = 0; i < C; i++)
        {
            scanf ("%c%c%c ", &c1, &c2, &c3);
            c1 -= '@';
            c2 -= '@';
            c3 -= '@';
            combine [c1][c2] = c3;
            combine [c2][c1] = c3;
        }
        scanf ("%d ", &D);
        memset (opposed, 0, sizeof(opposed));
        for (i = 0; i < D; i++)
        {
            scanf ("%c%c ", &c1, &c2);
            c1 -= '@';
            c2 -= '@';
            opposed [c1] |= (1 << c2);
            opposed [c2] |= (1 << c1);
        }
        scanf ("%d ", &N);
        size = 0;
        present = 0;
        memset (qty, 0, sizeof(qty));
        for (i = 0; i < N; i++)
        {
            scanf ("%c", &c1);
            c1 -= '@';
            if (size == 0)
            {
                // list is empty
                list[size++] = c1;
                qty[c1] = 1;
                present |= (1 << c1);
            }
            else
            {
                c2 = list[size-1];
                c3 = combine[c1][c2];
                if (c3 == 0)
                {
                    if (present & opposed[c1])
                    {
                        // opposed is present, list is cleared
                        size = 0;
                        present = 0;
                        memset (qty, 0, sizeof(qty));
                    }
                    else
                    {
                        // append element
                        list[size++] = c1;
                        present |= (1 << c1);
                        qty[c1]++;
                    }
                }
                else
                {
                    list[size-1] = c3;  // combined
                    if (--qty[c2] == 0)
                        present &= ~(1 << c2);
                }
            }
            #ifdef DUMP
            printf ("[");
            for (j = 0; j < size; j++)
                printf ("%c", list[j]+'@');
            printf ("]\n");
            #endif
        }
        scanf ("\n");
        printf ("Case #%d: [", iCase);
        for (i = 0; i < size; i++)
        {
            if (i != 0)
                printf (", ");
            printf ("%c", list[i]+'@');
        }
        printf ("]\n");
	}
}
