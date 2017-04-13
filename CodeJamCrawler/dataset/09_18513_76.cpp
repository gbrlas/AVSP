//
//	Google CodeJam 2009 - Qualification Round, Problem B
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

typedef struct
{
    int     alt;
    char    flows;
    char    sink;
    char    basin;
} Cell;

Cell map [100*100];
char letter [26];

#define altitude(l,c) map[(l)*100+c].alt

#define FLOW_NORTH  1
#define FLOW_WEST   2
#define FLOW_EAST   4
#define FLOW_SOUTH  8


// recursive tree travel
void mark (int p, char b)
{
    map[p].basin = b;
    if (map[p].flows & FLOW_NORTH)
        mark (p-100, b);
    if (map[p].flows & FLOW_SOUTH)
        mark (p+100, b);
    if (map[p].flows & FLOW_WEST)
        mark (p-1, b);
    if (map[p].flows & FLOW_EAST)
        mark (p+1, b);
}

#ifdef DUMP
void Dump (int H, int W)
{
    int lin, col, i;

    for (lin = 0; lin < H; lin++)
    {
        for (col = 0; col < W; col++)
        {
            i = lin*100+col;
            printf ("%2d %2d %5d %c %c %c %c %c\n",
                lin, col, altitude(lin,col),
                map[i].sink ? '*' : ' ',
            map[i].flows & FLOW_NORTH ? 'N' : ' ',
            map[i].flows & FLOW_WEST ? 'W' : ' ',
            map[i].flows & FLOW_EAST ? 'E' : ' ',
            map[i].flows & FLOW_SOUTH ? 'S' : ' ');
        }
    }

}
#endif

void main (void)
{
	int iCase, nCases;
    int H, W;
    int lin, col, i;
    char b;
    int neighb [4]; // North, West, East, South.
    int min;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);

	for (iCase = 1; iCase <= nCases; iCase++)
	{
        // read dimensions
    	scanf ("%d %d\n", &H, &W);

        // init map
        for (lin = 0; lin < H; lin++)
        {
            for (col = 0; col < W; col++)
            {
                i = lin*100+col;
                scanf ("%d ", &map[i].alt);
                map[i].sink = 0;
                map[i].flows = 0;
            }
        }

        // determine flow
        for (lin = 0; lin < H; lin++)
        {
            for (col = 0; col < W; col++)
            {
                // find to where it will flow
                if (lin == 0)
                    neighb [0] = 99999;
                else
                    neighb [0] = altitude (lin-1,col);
                if (col == 0)
                    neighb [1] = 99999;
                else
                    neighb [1] = altitude (lin,col-1);
                if (col == (W-1))
                    neighb [2] = 99999;
                else
                    neighb [2] = altitude (lin,col+1);
                if (lin == (H-1))
                    neighb [3] = 99999;
                else
                    neighb [3] = altitude (lin+1,col);
                min = 0;
                if (neighb [1] < neighb[min])
                    min = 1;
                if (neighb [2] < neighb[min])
                    min = 2;
                if (neighb [3] < neighb[min])
                    min = 3;
                if (altitude(lin,col) <= neighb[min])
                {
                    // it's a sink
                    map[lin*100+col].sink = 1;
                }
                else
                {
                    // mark where it comes from
                    switch (min)
                    {
                        case 0: // to North, from South
                            map[(lin-1)*100+col].flows |= FLOW_SOUTH;
                            break;
                        case 1: // to West, from East
                            map[lin*100+(col-1)].flows |= FLOW_EAST;
                            break;
                        case 2: // to East, from West
                            map[lin*100+(col+1)].flows |= FLOW_WEST;
                            break;
                        case 3: // to South, from North
                            map[(lin+1)*100+col].flows |= FLOW_NORTH;
                            break;
                    }
                }

            }
        }
#ifdef DUMP
        Dump (H, W);
#endif

        // follow trees from sink to upper lands
        b = 0;
        for (lin = 0; lin < H; lin++)
        {
            for (col = 0; col < W; col++)
            {
                i = lin*100+col;
                if (map[i].sink)
                {
                    mark (i, b);
                    b++;
                }
            }
        }

        // assign letters
        for (i = 0; i < 26; i++)
            letter[i] = 0;
        b = 'a';
        for (lin = 0; lin < H; lin++)
        {
            for (col = 0; col < W; col++)
            {
                i = lin*100+col;
                if (letter [map[i].basin] == 0)
                    letter [map[i].basin] = b++;
            }
        }

        // print result
		printf ("Case #%d:\n", iCase);
        for (lin = 0; lin < H; lin++)
        {
            for (col = 0; col < W; col++)
            {
                i = lin*100+col;
                if (col > 0)
                    printf (" %c", letter [map[i].basin]);
                else
                    printf ("%c", letter [map[i].basin]);
            }
            printf ("\n");
        }
	}

}
