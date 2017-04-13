#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

typedef struct timetableTag
{
	//int dep, arr;
	int time;
	char station;
	char action;
} timetable;

int compare (const void * a, const void * b)
{
	if ((((timetable*)a)->time) != (((timetable*)b)->time)) return ( (((timetable*)a)->time) - (((timetable*)b)->time) );
	else return ( (((timetable*)a)->action) - (((timetable*)b)->action) );
	//return ( (((timetable*)a)->time) - (((timetable*)b)->time) );
}

int main()
{
	int N, NA, NB, i, iA, iB, j;
	FILE *fileIn;

	fileIn = fopen("a.in", "r");

	//timetable timeTA[20], timeTB[20];
	timetable timeT[1000];
	int availableTrainsA, availableTrainsB;
	int neededTrainsA, neededTrainsB;
	int depH, depM, arrH, arrM;

	int turnaroundTime;

	fscanf(fileIn, "%d", &N);

	int n;
	for (n = 0; n < N; n++)
	{
		fscanf(fileIn, "%d", &turnaroundTime);
		fscanf(fileIn, "%d %d", &NA, &NB);

		j = 0;

		for (i = 0; i < NA; i++)
		{
			fscanf(fileIn, "%d:%d %d:%d", &depH, &depM, &arrH, &arrM);
			//timeT[j].dep = depH * 60 + depM;
			//timeT[j].arr = depH * 60 + depM + turnaroundTime;
			timeT[j].action = 'D';
			timeT[j].time = depH * 60 + depM;
			timeT[j].station = 'A';
			j++;

			timeT[j].action = 'A';
			timeT[j].time = arrH * 60 + arrM + turnaroundTime;
			timeT[j].station = 'A';
			j++;

		}

		for (i = 0; i < NB; i++)
		{			
			fscanf(fileIn, "%d:%d %d:%d", &depH, &depM, &arrH, &arrM);
			//timeT[j].dep = depH * 60 + depM;
			//timeT[j].arr = depH * 60 + depM + turnaroundTime;
			timeT[j].action = 'D';
			timeT[j].time = depH * 60 + depM;
			timeT[j].station = 'B';
			j++;

			timeT[j].action = 'A';
			timeT[j].time = arrH * 60 + arrM + turnaroundTime;
			timeT[j].station = 'B';
			j++;
		}

		availableTrainsA = 0;
		availableTrainsB = 0;

		neededTrainsA = 0;
		neededTrainsB = 0;

		iA = 0;
		iB = 0;

		qsort(timeT, j, sizeof(timetable), compare);
		//qsort(timeTB, NB, sizeof(timetable), compare);

		for (i = 0; i < j;  i++)
		{
			if (timeT[i].station == 'A')
			{
				if (timeT[i].action == 'A')
				{
					availableTrainsB++;
				}
				else //dep
				{
					if (availableTrainsA > 0) availableTrainsA--;
					else neededTrainsA++;
				}
			}
			else
			{
				if (timeT[i].action == 'A')
				{
					availableTrainsA++;
				}
				else //dep
				{
					if (availableTrainsB > 0) availableTrainsB--;
					else neededTrainsB++;
				}
			}
		}

		printf("Case #%d: %d %d\n", n + 1, neededTrainsA, neededTrainsB);
	}

	return 0;
}

