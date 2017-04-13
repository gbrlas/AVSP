#include <stdio.h>
#include <stdlib.h>

void bad_sort(int *arr, int num);

int main(int argc, char **argv)
{
	char s[15];
	FILE *fin, *fout;
	int num_cases, turn_arnd_time, numA, numB;
	int *depA, *arrA, *depB, *arrB;
	int temp_hr, temp_min;
	int i, j, k;
	int trainA_ctr, trainB_ctr;
	
	if(argc != 2) {
		printf("Error in parameters\n");
		exit(-1);
	}

	fin = fopen(argv[1], "r");
	if(!fin) {
		printf("Error opening source\n");
		exit(-1);
	}

	fout = fopen("output", "w");
	if(!fout) {
		printf("Error opening destination\n");
		exit(-1);
	}

	fscanf(fin, "%d\n", &num_cases);
	printf("NUM CASES: %d\n", num_cases);

	for(i = 0; i < num_cases; i++) {
		fscanf(fin, "%d\n", &turn_arnd_time);
		printf("TT: %d\n", turn_arnd_time);

		fscanf(fin, "%d%d\n", &numA, &numB);
		printf("NUMA: %d\n", numA);
		printf("NUMB: %d\n", numB);

		depA = (int*)malloc(sizeof(int) * numA);
		arrA = (int*)malloc(sizeof(int) * numA);

		depB = (int*)malloc(sizeof(int) * numB);
		arrB = (int*)malloc(sizeof(int) * numB);

		/* Get arrival and departure times and convert them into minutes */

		for(j = 0; j < numA; j++) {
			fscanf(fin, "%d:%d", &temp_hr, &temp_min);
			depA[j] = temp_hr*60 + temp_min;
			fscanf(fin, "%d:%d\n", &temp_hr, &temp_min);
			arrA[j] = temp_hr*60 + temp_min + turn_arnd_time;
		}

		/*for(j = 0; j < numA; j++) {
			printf("ARR %d\tDEP%d\n", arrA[j], depA[j]);
		}*/

		for(j = 0; j < numB; j++) {
			fscanf(fin, "%d:%d", &temp_hr, &temp_min);
			depB[j] = temp_hr*60 + temp_min;
			fscanf(fin, "%d:%d\n", &temp_hr, &temp_min);
			arrB[j] = temp_hr*60 + temp_min + turn_arnd_time;
		}

		// sort arrivals and departures
		bad_sort(depA, numA);
		bad_sort(arrA, numA);
		bad_sort(depB, numB);
		bad_sort(arrB, numB);

		// compare departures of B with arrivals of A and vice versa to get answer
		
		trainB_ctr = 0;
		trainA_ctr = 0;
		// for B
		for(j = 0, k = 0; (j < numA) && (k < numB); k++) {
			if(arrA[j] > depB[k]) {	// we need a new train
				trainB_ctr++;
			}
			else {
				j++;
			}
		}
		while(k < numB) {
			trainB_ctr++;
			k++;
		}
		printf("Trains from B: %d\n", trainB_ctr);
		// for A
		for(j = 0, k = 0; (j < numA) && (k < numB); j++) {
			if(arrB[k] > depA[j]) { // we need a new train
				trainA_ctr++;
			}
			else {
				k++;
			}
		}
		while(j < numA) {
			trainA_ctr++;
			j++;
		}

		// result
		printf("Trains from A: %d\n", trainA_ctr);

		fprintf(fout, "Case #%d: %d %d\n", i+1, trainA_ctr, trainB_ctr);
		free(depA);
		free(arrA);
		free(depB);
		free(arrB);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

void bad_sort(int *arr, int num) 
{
	int i, j, temp;
	if(num == 0)
		return;
	for(i = 0; i < num-1; i++) {
		for(j = i+1; j < num; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// verify
	for(i = 0; i < num; i ++)
		printf("%d\t", arr[i]);
	printf("\n");
}
