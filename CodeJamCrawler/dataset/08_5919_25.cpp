#include "stdio.h"
#include "string.h"


/* ////////////////////////////////////////

N
NA NB
...

1 ¡Ü N ¡Ü 100
Small dataset
0 ¡Ü NA, NB ¡Ü 20
0 ¡Ü T ¡Ü 5

*  ///////////////////////////////       */

typedef struct  {
	int  minu;
	int  flag;
}Time;

static int  cost = 0;
static int  icase = 0;

void  do_case(FILE * fp) {
	//int   qui[100] = {0};
	int  timeAfr[100];
	int  timeAto[100];

	int  timeBfr[100];
	int  timeBto[100];

	char line[101];
	int turnTime = 0;
	int na = 0;
	int nb = 0;

	int i = 0, k = 0, j = 0;;
	int cost = 0;
	int hour1, minu1, hour2, minu2;
	Time tmA[200], tmB[200];
	int  gooutA = 0, arvA = 0;
	int  gooutB = 0, arvB = 0;

	fgets(line, 101, fp);
	sscanf(line, "%d", &turnTime);
	//printf("turnTime: %d\n", turnTime);

	fgets(line, 101, fp);
	sscanf(line, "%d %d", &na, &nb);
	//printf("na:%d  nb:%d\n", na, nb);
	
	for( i = 0; i < na; i++) {
		fgets(line, 101, fp);
		sscanf(line, "%d:%d %d:%d", &hour1, &minu1, &hour2, &minu2);
		timeAfr[i] = hour1 * 60 + minu1;
		timeAto[i] = hour2 * 60 + minu2;

		tmA[i].flag = 1;
		tmA[i].minu = timeAfr[i];
		
		tmB[i].flag = 2;
		tmB[i].minu = timeAto[i] + turnTime;
	}

	for( i = 0; i < nb; i++) {
		fgets(line, 101, fp);
		sscanf(line, "%d:%d %d:%d", &hour1, &minu1, &hour2, &minu2);
		timeBfr[i] = hour1 * 60 + minu1;
		timeBto[i] = hour2 * 60 + minu2;

		tmB[i+na].flag = 1;
		tmB[i+na].minu = timeBfr[i];
		
		tmA[i+na].flag = 2;
		tmA[i+na].minu = timeBto[i] + turnTime;
	}
	//printf("\n");

	/**  sort to tmA  **/
	for( i = 0; i < na + nb; i++) {
		for( j = 1; j < na + nb - i; j++) {
			if(tmA[j].minu < tmA[j-1].minu || tmA[j].minu == tmA[j-1].minu && tmA[j].flag == 2) {
				Time tmp = tmA[j];
				tmA[j] = tmA[j-1];
				tmA[j-1] = tmp;
			}
		}
	}
	for( i = 0; i < na + nb; i++) {
		if(tmA[i].flag == 1) {
			gooutA ++;
			if(arvA > 0) {
				arvA --;
				gooutA --;
			}
		}
		else if(tmA[i].flag == 2) {
			arvA ++;
		}
	}

	/**  sort to tmB  **/
	for( i = 0; i < na + nb; i++) {
		for( j = 1; j < na + nb - i; j++) {
			if(tmB[j].minu < tmB[j-1].minu || tmB[j].minu == tmB[j-1].minu && tmB[j].flag == 2) {
				Time tmp = tmB[j];
				tmB[j] = tmB[j-1];
				tmB[j-1] = tmp;
			}
		}
	}
	for( i = 0; i < na + nb; i++) {
		if(tmB[i].flag == 1) {
			gooutB ++;
			if(arvB > 0) {
				arvB --;
				gooutB --;
			}
		}
		else if(tmB[i].flag == 2) {
			arvB ++;
		}
	}
	//Case #X: Y
	printf("Case #%d: %d  %d\n", ++icase, gooutA, gooutB);
}



int main(int argc, char * argv[]) {
	FILE * oldinfp = freopen("B-large.in", "r+t", stdin);
	//FILE * oldoutfp = stdout;
	FILE * oldoutfp = freopen("B-large.out", "w+t", stdout);
	//FILE * fp = fopen("B-small-attempt0.out", "r+t");
	char line[101] = {0};
	int n = 0;
	int i = 0;
	
	if(!oldinfp || !oldoutfp){
		fprintf(stderr, "open faile");
		return -1;
	}
		
	fgets(line, 101, stdin);
	sscanf(line, "%d", &n);
	for( ; i < n; i++) {
		do_case(stdin);
		//printf("--------------------------\n");
	}
	return 0;
}



/**
Problem

A train line has two stations on it, A and B. Trains can take trips from A to B or 
from B to A multiple times during a day. When a train arrives at B from A (or arrives 
at A from B), it needs a certain amount of time before it is ready to take the return 
journey - this is the turnaround time. For example, if a train arrives at 12:00 and 
the turnaround time is 0 minutes, it can leave immediately, at 12:00. 

A train timetable specifies departure and arrival time of all trips between A and B. 
The train company needs to know how many trains have to start the day at A and B in 
order to make the timetable work: whenever a train is supposed to leave A or B, there 
must actually be one there ready to go. There are passing sections on the track, so 
trains don't necessarily arrive in the same order that they leave. Trains may not 
travel on trips that do not appear on the schedule. 

Input


The first line of input gives the number of cases, N. N test cases follow. 

Each case contains a number of lines. 
The first line is the turnaround time, T, in minutes. The next line has two numbers on it, 
NA and NB. NA is the number of trips from A to B, and 
NB is the number of trips from B to A. Then there are NA lines giving the details 
of the trips from A to B. 

Each line contains two fields, giving the HH:MM departure and arrival time for that 
trip. The departure time for each trip will be earlier than the arrival time. All 
arrivals and departures occur on the same day. The trips may appear in any order - they 
are not necessarily sorted by time. The hour and minute values are both two digits, 
zero-padded, and are on a 24-hour clock (00:00 through 23:59). 

After these NA lines, there are NB lines giving the departure and arrival times for the 
trips from B to A. 


Output

For each test case, output one line containing "Case #x: " followed by the number of trains 
that must start at A and the number of trains that must start at B. 

Limits

1 ¡Ü N ¡Ü 100

Small dataset

0 ¡Ü NA, NB ¡Ü 20

0 ¡Ü T ¡Ü 5

Large dataset

0 ¡Ü NA, NB ¡Ü 100

0 ¡Ü T ¡Ü 60

Sample


Input 
 
2
5
3 2
09:00 12:00
10:00 13:00
11:00 12:30
12:02 15:00
09:00 10:30

2
2 0
09:00 09:01
12:00 12:02

Output 
Case #1: 2 2
Case #2: 2 0


*/