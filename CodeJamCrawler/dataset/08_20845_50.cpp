#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int num_cases, num_eng, num_quer, swap_ctr, temp_cntr;
	int *tracker;
	//int tracker[100];
	FILE *fsrc, *fdest;
	char s1[102];
	char **srch_eng;
	int i, j, k;

	if(argc != 2) {
		printf("Error in input parameters");
		exit(-1);
	}
	fsrc = fopen(argv[1], "r");
	if(!fsrc) {
		printf("Error opening input file\n");
		exit(-1);
	}
	fdest = fopen("output", "w");
	if(!fdest) {
		printf("Error opening output file\n");
		exit(-1);
	}
	num_cases = atoi(fgets(s1, 102, fsrc));
	printf("Num cases = %d\n", num_cases);

	for(i = 0; i < num_cases; i++) {
		num_eng = atoi(fgets(s1, 102, fsrc));
		printf("Case %d:\n", i+1);
		printf("Num eng: %d\n", num_eng);

		srch_eng = (char**)malloc(num_eng*sizeof(char*));
		//store the search engine names
		for(j = 0; j < num_eng; j++) {
			srch_eng[j] = (char*)malloc(100*sizeof(char));
			fgets(srch_eng[j], 102, fsrc);
		}

		for(j=0;j<num_eng;j++) {
			printf("%s\n", srch_eng[j]);
		}
		//allocate zeroed tracker array
		tracker = (int*)calloc(num_eng, sizeof(int));
		swap_ctr = 0;

		num_quer = atoi(fgets(s1, 102, fsrc));
		temp_cntr = 0;
		for(j = 0; j < num_quer; j++) {
			fgets(s1, 102, fsrc);
			for(k = 0; k < num_eng; k++) {
				/* compare this to the search engines we have
				 * if this is something new, increment count
				 */
				if(strcmp(s1, srch_eng[k]) == 0) {
					if(tracker[k] == 0) {
						printf("Found: %s\n", s1);
						temp_cntr++;
						printf("Temp ctr: %d\n", temp_cntr);
						tracker[k]++;
					}
					break;
				}
			}
			/* when count reaches number of search engines, first
			 * swap will be made
			 */
			if(temp_cntr == num_eng) {
				printf("Last of search engines found: %s\n", s1);
				swap_ctr++;
				temp_cntr = k;
				for(k = 0; k < num_eng; k++) {
					tracker[k] = 0;
				}
				tracker[temp_cntr]++;
				temp_cntr = 1;
			}
		}
		//annouce result
		printf("Number of swaps: %d\n", swap_ctr);
		fprintf(fdest, "Case #%d: %d\n", i+1, swap_ctr);
		// free data structures
		free(tracker);
		for(j = 0; j < num_eng; j++) {
			free(srch_eng[j]);
		}
		free(srch_eng);
	}
	fclose(fdest);
	fclose(fsrc);
	return 0;
}
