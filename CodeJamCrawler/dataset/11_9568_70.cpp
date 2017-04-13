#include <stdio.h>
#include <malloc.h>

struct combination {
	int a, b, eq;	
};

struct opossed {
	int a, b;
};

FILE *dataset;
FILE *dataset_out;

int test_cases;
int curr_test = 0;

char buff[100];

int n_combs; 	
int n_opposed;	
int n_invokes;	

int index = 1;
char invoked, eq;

int n_elements;
char element_list[200]; 	

combination combs[36];		
opossed opps[28];			
char invokes[100];


int rcombination(int a, int b) {
	
	for(int i = n_combs - 1; i >= 0; --i) {
		if((a == combs[i].a && b == combs[i].b)
				|| (b == combs[i].a && a == combs[i].b)) {
			return combs[i].eq;
		}
	}
	return 0;
}

int ropposed(int a, int b) {

	for(int i = n_opposed - 1; i >= 0; --i) {
		if((a == opps[i].a && b == opps[i].b)
				|| (b == opps[i].a && a == opps[i].b)) {
			return 1;
		}
	}
	return 0;
}

int main() {

	dataset = fopen("dataset.in", "r");
	dataset_out = fopen("output", "w");

	fscanf(dataset, "%d", &test_cases);

	while(curr_test < test_cases) {

		fscanf(dataset, "%d", &n_combs);
		for(int i = n_combs - 1; i >= 0 ; --i) {
			fscanf(dataset, "%s ", buff);
			combs[i].a = buff[0];
			combs[i].b = buff[1];
			combs[i].eq = buff[2];
		}

		fscanf(dataset, "%d", &n_opposed);
		for(int i = n_opposed - 1; i >= 0; --i) {
			fscanf(dataset, "%s ", buff);
			opps[i].a = buff[0];
			opps[i].b = buff[1];
		}

		fscanf(dataset, "%d", &n_invokes);
		fscanf(dataset, "%s", buff);
		for(int i = 0; i < n_invokes; ++i) {
			invokes[i] = buff[i];
		}

		invoked = eq = 0;
		element_list[0] = invokes[0];
		n_elements = 1;
		index = 1;

		for(int i = 1; i < n_invokes; ++i) {
			invoked = invokes[i];

			eq = rcombination(invoked, element_list[index - 1]);
			if(eq) {
				element_list[index - 1] = eq;
				continue;
			}
			
			for(int k = index - 1; k >= 0; --k) {
				if(ropposed(invoked, element_list[k])) {
					n_elements = 0;
					index = 0;
					break;
				}
			}

			if(n_elements == 0) {
				if(++i >= n_invokes) break;
				invoked = invokes[i];
			}
			element_list[index] = invoked;
			++index;
			++n_elements;
		}
		
		fprintf(dataset_out, "Case #%d: [", curr_test + 1);
		if(n_elements > 0) {
			for(int i = 0; i < n_elements - 1; ++i) {
				fprintf(dataset_out, "%c, ", element_list[i]);
			}
			fprintf(dataset_out, "%c]\n", element_list[n_elements - 1]);
		} else {
			fprintf(dataset_out, "]\n");
		}
		++curr_test;
	}

	fclose(dataset_out);
	fclose(dataset);
	return 0;
}
