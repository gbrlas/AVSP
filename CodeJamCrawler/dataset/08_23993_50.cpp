#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define NA 20
#define NB 20
#define T 5

typedef struct journey {
	int arrival, departure;
}journeyStruct;

int find_closest (journeyStruct station, journeyStruct dest[], int no, int *check,int turnaround) {
	int iter, prevval = INT_MAX, returnval = -1, diff;
	for (iter = 0; iter < no; iter ++) {
		diff = station.arrival - dest[iter].departure;
		// printf ("here %d %d %d %d\n",station.arrival, dest[iter].departure, diff, check[iter]);
		if (diff >= turnaround && check [iter] == 0) {			
			if (diff < prevval) {
				prevval = diff;
				returnval = iter;				
			}
		}
	}
	return returnval;
}

int clear_arr (int *arr) {
	int iter;
	for (iter = 0; iter < NA; iter ++)
		arr[iter] = 0;
	return 0;
}

int get_trains (journeyStruct stationf[], journeyStruct stations[], int nf, int ns, int turnaround) {
	int iterf, iters, val = 0;
	int  count = 0, check [NA];
	bzero ((void *) check, sizeof(int) * NA);
	for (iterf = 0; iterf < nf; iterf ++) {
		val = find_closest (stationf[iterf], stations, ns, check, turnaround);
		if (val == -1) 
			count ++;
		else check[val] = 1;
		// printf ("val : %d\n", val);
	}
	return count; 
}

int train_schedule (char *filename) {
	journeyStruct journeyA[NA], journeyB[NB];
	FILE *fpIn, *fpOut = fopen ("Output", "w");
	int Number_Of_Inputs, iter, turnaround, na, nb, loop, h1, h2, m1, m2;
	fpIn = fopen (filename, "r");
	if (!fpIn || !fpOut) 
		printf ("Unable to Open file.\n"), exit(1);
	fscanf (fpIn, "%d", &Number_Of_Inputs);
	for (iter = 0; iter < Number_Of_Inputs; iter ++) {
		fscanf (fpIn, "%d %d %d", &turnaround, &na, &nb);
		for (loop = 0; loop < na; loop ++) {
			fscanf (fpIn, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
			journeyA[loop].arrival = h1 * 60 + m1;	journeyA[loop].departure = h2 * 60 + m2;			
		}
		for (loop = 0; loop < nb; loop ++) {
			fscanf (fpIn, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
			journeyB[loop].arrival = h1 * 60 + m1;	journeyB[loop].departure = h2 * 60 + m2;
		}
		fprintf (fpOut, "Case #%d: %d %d\n", iter + 1, get_trains (journeyA, journeyB, na, nb, turnaround),
								get_trains (journeyB, journeyA, nb, na, turnaround));
	}
	return 0;
}

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf ("Invalid Arguments .... \n Usage Train <Input File>");
		exit (1);
	}
	train_schedule (argv[1]);
}
