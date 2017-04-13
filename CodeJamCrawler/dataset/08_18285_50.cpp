//
//	Google CodeJam - Qualification Round, Problem B
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

#define MAX_TRIPS   100

#define TRAIN_READY     1
#define TRAIN_DEPARTURE 2

// Each array record departures and ready trains,
// ordered by time and type
int StationA [2*MAX_TRIPS];
int StationB [2*MAX_TRIPS];
int nSA, nSB;

// Convert HH:MM in tenths of minutes
int EncodeTime (char *s)
{
    return (s[0]-'0')*10*600 + (s[1]-'0')*600 +
           (s[3]-'0')*100 + (s[4]-'0')*10;
}

// Register an event at the station
// (good old insertion sort, again)
void Register (int *tabEvt, int nEvt, int event)
{
    int i;

    for (i = nEvt; i > 0; i--)
        if (tabEvt[i-1] <= event)
            break;
    if (i < nEvt)
        memmove (tabEvt+i+1, tabEvt+i, (nEvt-i)*sizeof(int));
    tabEvt[i] = event;
}

// Finds how many trains we need
int Trains (int *Station, int nEvt)
{
    int i, need, cur;

    for (i = need = cur = 0; i < nEvt; i++)
    {
        if ((Station[i] % 10) == TRAIN_READY)
            cur++;
        else if (cur == 0)
            need++;
        else
            cur--;
    }
    return need;
}

void main (void)
{
	int iCase, nCases;
    int t, nA, nB;
    int i;
    char depart[6], arrive[6];

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
        scanf ("%d", &t);
        t *= 10;
        scanf ("%d %d", &nA, &nB);
        nSA = nSB = 0;
        for (i = 0; i < nA; i++)
        {
            scanf ("%s %s", depart, arrive);
            Register (StationA, nSA, EncodeTime(depart)+TRAIN_DEPARTURE);
            nSA++;
            Register (StationB, nSB, EncodeTime(arrive)+t+TRAIN_READY);
            nSB++;
        }
        for (i = 0; i < nB; i++)
        {
            scanf ("%s %s", depart, arrive);
            Register (StationB, nSB, EncodeTime(depart)+TRAIN_DEPARTURE);
            nSB++;
            Register (StationA, nSA, EncodeTime(arrive)+t+TRAIN_READY);
            nSA++;
        }

#ifdef TEST
        printf ("Station A\n");
        for (i = 0; i < nSA; i++)
            printf ("%02d:%02d %c\n", StationA[i]/600, (StationA[i]%600)/10,
            (StationA[i]%10) == TRAIN_DEPARTURE ? '>' : '<');
        printf ("Station B\n");
        for (i = 0; i < nSB; i++)
            printf ("%02d:%02d %c\n", StationB[i]/600, (StationB[i]%600)/10,
            (StationB[i]%10) == TRAIN_DEPARTURE ? '>' : '<');
#endif

		printf ("Case #%d: %d %d\n", iCase, Trains (StationA, nSA), 
                Trains (StationB, nSB));
	}

}
