#include <stdio.h>
#include <stdlib.h>

int main() {
	int first_row[4];
	int second_row[4];
	int i, j, no_tests, curr, index, aux, number, no_found;
	
	FILE * inFile = fopen ("A-small-attempt0.in","r");
	FILE * outFile = fopen ("A.out","w");
	
	if (inFile == NULL) {
		printf("Error");
		return 1;
	}
  
	fscanf(inFile, "%i", &no_tests);
	for (curr = 0; curr < no_tests; curr++) {
		fscanf(inFile, "%i", &index);
		for( i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				fscanf(inFile, "%i", &aux);
				if( i == index -1) {
					first_row[j] = aux;
				}
			}
		}
		
		fscanf(inFile, "%i", &index);
		for( i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				fscanf(inFile, "%i", &aux);
				if( i == index -1) {
					second_row[j] = aux;
				}
			}
		}		
		
		no_found = 0;
		number = 0;
		
		for( i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (first_row[i] == second_row[j]) {
					no_found++;
					number = first_row[i];
				}
			}
		}
		
		if (no_found == 0) {
			fprintf(outFile, "Case #%d: Volunteer cheated!\n", curr + 1);
		} else if (no_found == 1) {
			fprintf(outFile, "Case #%d: %d\n", curr + 1, number);
		} else {
			fprintf(outFile, "Case #%d: Bad magician!\n", curr + 1);
		}
	}
	
	
	fclose(inFile);
	fclose(outFile);
	
	return 0;
	
}

