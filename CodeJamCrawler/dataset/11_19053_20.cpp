//
//	Google CodeJam 2011 - Round 1B, Problem A
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

#define MAX_TEAM    100

typedef struct
{
    int ng;
    int nv;
    double wp, owp, oowp;
    char game [MAX_TEAM+2];
} TEAM;

TEAM team [MAX_TEAM];


void main (void)
{
	int iCase, nCases;
    int i, j, n;
    double sum;
    TEAM *pt;

#ifdef TEST
	freopen("test.txt","r",stdin);
	freopen("saida.txt","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d\n", &n);
        for (i = 0; i < n; i++)
        {
            pt = &team[i];
            gets (pt->game);
            pt->ng = pt->nv = 0;
            for (j = 0; j < n; j++)
            {
                if (pt->game[j] == '0')
                {
                    pt->ng++;
                }
                else if (pt->game[j] == '1')
                {
                    pt->ng++;
                    pt->nv++;
                }
            }
            pt->wp = (double) pt->nv / pt->ng;
            #ifdef DUMP
            printf ("Team %d WP = %f\n", i, pt->wp);
            #endif
        }
        for (i = 0; i < n; i++)
        {
            sum = 0;
            pt = &team[i];
            for (j = 0; j < n; j++)
            {
                if (pt->game[j] == '0')
                    sum += (double) (team[j].nv - 1) / (team[j].ng - 1);
                else if (pt->game[j] == '1')
                    sum += (double) team[j].nv / (team[j].ng - 1);
            }
            pt->owp = sum / pt->ng;
            #ifdef DUMP
            printf ("Team %d OWP = %f\n", i, pt->owp);
            #endif
        }
        for (i = 0; i < n; i++)
        {
            sum = 0;
            pt = &team[i];
            for (j = 0; j < n; j++)
            {
                if (pt->game[j] != '.')
                    sum += team[j].owp;
            }
            pt->oowp = sum / pt->ng;
            #ifdef DUMP
            printf ("Team %d OOWP = %f\n", i, pt->oowp);
            #endif
        }

        printf ("Case #%d:\n", iCase);
        for (i = 0; i < n; i++)
            printf ("%f\n", 0.25 * team[i].wp + 0.50 * team[i].owp + 0.25 * team[i].oowp);
	}
}
