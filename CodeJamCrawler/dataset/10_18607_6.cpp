//
//	Google CodeJam 2010 - Round 2, Problem C
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

char grid [102][102];
char grid [102][102];
int minX, maxX, minY, maxY;
int nbact;


void Clear()
{
    memset (grid, '0', sizeof(grid));
    minX = minY = 101;
    maxX = maxY = 0;
}

void Rect (int x1, int y1, int x2, int y2)
{
    int x, y;

    if (x1 < minX)
        minX = x1;
    if (x2 > maxX)
        maxX = x2;
    if (y1 < minY)
        minY = y1;
    if (y2 > maxY)
        maxY = y2;

    for (y = y1; y <= y2; y++)
        for (x = x1; x <= x2; x++)
            grid[y][x] = '1';
}

int Count ()
{
    int x, y;
    int n = 0;

    for (y = minY; y <= maxY; y++)
        for (x = minX; x <= maxX; x++)
            if (grid[y][x] == '1')
                n++;

    return n;
}


void Generate ()
{
    int x, y;

    for (y = maxY; y >= minY; y--)
        for (x = maxX; x >= minX; x--)
        {
            if (grid[y][x] == '0')
            {
                if ((grid[y-1][x] == '1') && (grid[y][x-1] == '1'))
                {
                    grid[y][x] = '1';
                    nbact++;
                }
            }
            else
            {
                if ((grid[y-1][x] == '0') && (grid[y][x-1] == '0'))
                {
                    grid[y][x] = '0';
                    nbact--;
                }
            }
        }
}


#ifdef DUMP

void Dump ()
{
    int x, y;

    for (y = minY; y <= maxY; y++)
    {
        for (x = minX; x <= maxX; x++)
            printf ("%c", grid[y][x]);
        printf ("\n");
    }
    printf ("\n");
}

#endif

void main (void)
{
	int iCase, nCases;
    int i, R;
    int x1, y1, x2, y2;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
        Clear();
    	scanf ("%d\n", &R);
        for (i = 0; i < R; i++)
        {
            scanf ("%d %d %d %d\n", &x1, &y1, &x2, &y2);
            Rect (x1, y1, x2, y2);
        }
        nbact = Count();

        #ifdef DUMP
        printf ("minX=%d maxX=%d minY=%d maxY=%d nbact=%d\n",
            minX, maxX, minY, maxY, nbact);
        Dump();
        #endif

        for (i = 0; nbact > 0; i++)
        {
            Generate();
            #ifdef DUMP
            Dump ();
            #endif
        }


        printf ("Case #%d: %d\n", iCase, i);
	}
}
