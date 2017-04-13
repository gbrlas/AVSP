#include <stdio.h>
#include <malloc.h>

FILE *dataset;
FILE *dataset_out;

int test_cases;
int curr_test = 0;

int n_candies;

int xor_patrick;
int xor_sean;
int sum_patrick;
int sum_sean;

int index;
int vcandy;

int candies[1000];

void swap(int* a, int* b) {
        int temp=*a;
        *a=*b;
        *b=temp;
}

void quicksort(int* izq, int* der) {
        if(der<izq) return;
        int pivot=*izq;
        int* ult=der;
        int* pri=izq;
 
        while(izq<der)
        {
                while(*izq<=pivot && izq<der+1) izq++;
                while(*der>pivot && der>izq-1) der--;
                if(izq<der) swap(izq,der);
        }
        swap(pri,der);
        quicksort(pri,der-1);
        quicksort(der+1,ult);
}

int main() {

	dataset = fopen("dataset.in", "r");
	dataset_out = fopen("output", "w");

	fscanf(dataset, "%d", &test_cases);

	while(curr_test < test_cases) {

		fscanf(dataset, "%d", &n_candies);
		for(int i = n_candies - 1; i >= 0 ; --i) {
			fscanf(dataset, "%d ", &vcandy);
			candies[i] = vcandy;
		}
		quicksort(&candies[0], &candies[n_candies - 1]);
	
		index = 1;
		xor_sean = 0;
		xor_patrick = -1;
		
		while(xor_sean != xor_patrick) {

			sum_patrick = xor_patrick = candies[0];
			for(int i = 1; i < index; ++i) {
				xor_patrick ^= candies[i];
				sum_patrick += candies[i];
			}

			sum_sean = xor_sean = candies[index];
			for(int i = index + 1; i < n_candies; ++i) {
				xor_sean ^= candies[i];
				sum_sean += candies[i];
			}

			if(sum_sean <= sum_patrick) {
				break;
			}
			++index;
		}

		if(xor_patrick != xor_sean) {
			fprintf(dataset_out, "Case #%d: NO\n", curr_test + 1);
		} else {
			fprintf(dataset_out, "Case #%d: %d\n", curr_test + 1, sum_sean);
		}
		++curr_test;
	}

	fclose(dataset_out);
	fclose(dataset);
	return 0;
}
