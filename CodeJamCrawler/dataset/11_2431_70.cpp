#include <stdio.h>
#include <stdlib.h>

void bsort(int *array, size_t size) {
	int i, sorted = 0;
	
	while(sorted == 0) {
		sorted = 1;
		for(i = 0; i < size-1; i++) {
			if(array[i] > array[i+1]) {
				int t;
				
				t = array[i];
				array[i] = array[i+1];
				array[i+1] = t;
				sorted = 0;
			}
		}
	}
	return;
}

int main(int argc, char *argv[]) {
	FILE *in, *out;
	int lines;
	int n;
	
	if(argc != 3) {
		return(1);
	}
	
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w+");
	
	if(!in || !out) {
		return(1);
	}
	
	fscanf(in, "%d", &lines);
	printf("%d lines\n", lines);
	for(n = 0; n < lines; n++) {
		int candy, m;
		int patrick_sum;
		int *bag;
		int o, best;
		
		fscanf(in, "%d", &candy);
		bag = malloc(sizeof(int) * candy);
		for(m = 0; m < candy; m++) {
			fscanf(in, "%d", &bag[m]);
		}			
		best = 0;
		bsort(bag, candy);
		for(o = 0; o < candy; o++) {
			int i, p, s, sp;
			
			p = 0;
			s = 0;
			sp = 0;
			for(i = 0; i <= o; i++) {
				p ^= bag[i];
			}
			for(i = o+1; i < candy; i++) {
				s += bag[i];
				sp ^= bag[i];
			}
			if(p == sp) {
				if(s > best) {
					best = s;
				}
			}
		}
		if(best > 0) {
			fprintf(out, "Case #%d: %d\n", n+1, best);
		} else {
			fprintf(out, "Case #%d: NO\n", n+1);
		}
		free(bag);	
	}
	fclose(in);
	fclose(out);
	return(0);
}
