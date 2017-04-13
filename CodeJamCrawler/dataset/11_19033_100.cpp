//
//	Google CodeJam 2011 - Qualification Round, Problem A
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


typedef struct
{
    int pos;
    int iMission;
    int dest;
    int finished;
} ROBOT;

ROBOT robot[2];

typedef struct
{
    int iRob;
    int iBut;
} MISSION;

MISSION mission [100];
int nMission;
int curMission;

int sec;


void SetNextMission (int ir)
{
    int i;

    for (i = robot[ir].iMission+1; (i < nMission) && (mission[i].iRob != ir); i++)
        ;
    robot[ir].iMission = i;
    if (i < nMission)
        robot[ir].dest = mission[i].iBut;
    else
        robot[ir].finished = TRUE;

    #ifdef DUMP
    printf ("Next mission for robot %d: %d\n", ir, i);
    #endif
}

int MoveRobot (int ir)
{
    int im;

    if (robot[ir].finished)
        return FALSE;
    im = robot[ir].iMission;
    if (robot[ir].pos < mission[im].iBut)
        robot[ir].pos++;
    else if (robot[ir].pos > mission[im].iBut)
        robot[ir].pos--;
    else if (robot[ir].iMission == curMission)
    {
        #ifdef DUMP
        printf ("Robot %d finished mission %d\n", ir, im);
        #endif
        SetNextMission (ir);
        return TRUE;
    }
    return FALSE;
}


void main (void)
{
	int iCase, nCases;
    int i;
    char cRob;
    int next;

#ifdef TEST
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif

	scanf ("%d\n", &nCases);
	for (iCase = 1; iCase <= nCases; iCase++)
	{
    	scanf ("%d", &nMission);
        for (i = 0; i < nMission; i++)
        {
            scanf (" %c %d", &cRob, &mission[i].iBut);
            mission[i].iBut--;
            mission[i].iRob = (cRob == 'O') ? 0 : 1;
        }
        robot[0].pos = robot[1].pos = 0;
        robot[0].iMission = robot[1].iMission = -1;
        robot[0].finished = robot[1].finished = FALSE;
        SetNextMission (0);
        SetNextMission (1);
        curMission = 0;
        sec = 0;
        while (! (robot[0].finished && robot[1].finished))
        {
            sec++;
            next = MoveRobot(0);
            next = MoveRobot(1) || next;
            #ifdef DUMP
            printf ("sec %d: %d %d\n", sec, robot[0].pos, robot[1].pos);
            #endif
            if (next)
                curMission++;
        }
        printf ("Case #%d: %d\n", iCase, sec);
	}
}
