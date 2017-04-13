#include <stdio.h>
#include <stdlib.h>

int main() {
	int first_row[4];
	int second_row[4];
	int i, j, no_tests, curr, index;
	double price, added_rate, amount;
	double total_time, curr_rate, possible_rate, curr_time, possible_time, curr_buy_time;
	int found;
	
	FILE * inFile = fopen ("B-small-attempt0.in","r");
	FILE * outFile = fopen ("B.out","w");
	
	if (inFile == NULL) {
		printf("Error");
		return 1;
	}
  
	fscanf(inFile, "%i", &no_tests);
	for (curr = 0; curr < no_tests; curr++) {
		fscanf(inFile, "%lf %lf %lf", &price, &added_rate, &amount);
		found = 0;
		curr_rate = 2;
		total_time = 0;
		while (!found) {
			curr_time = amount / curr_rate;
			curr_buy_time = price / curr_rate;
			possible_rate = curr_rate + added_rate;
			possible_time = amount / possible_rate;
			
			if(curr_time <= curr_buy_time + possible_time) {
				total_time += curr_time;
				found = 1;
			} else {
				total_time += curr_buy_time;
				curr_rate = possible_rate;
			}
		}
		fprintf(outFile, "Case #%d: %.7lf\n", curr + 1, total_time);
	}
	
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
	
}

