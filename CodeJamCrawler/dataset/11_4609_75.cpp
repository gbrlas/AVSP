#include <cstdio>
#include <cstdlib>
#include <climits>
int main(int argc, char** argv){
	FILE* fi_ptr = fopen("C-small-attempt0.in", "r");
	FILE* fo_ptr = fopen("output.txt", "w");
	char* line = new char[9000];
	fgets(line, 8999, fi_ptr);
	// get no of iterations/cases
	int num_iter = atoi(line);
	char value[500];
	for(int l=0; l < num_iter ; l++){
		int pos = 0;
		fgets(line, 8999, fi_ptr);
		sscanf(line, "%s", value);
		int n_candy = atoi(value);
		int* candies = new int[n_candy];
		fgets(line, 8999, fi_ptr);
		for(int i = 0; i < n_candy ; i++){
			sscanf(line+pos, "%s", value);
			pos++;
			for(int m=0; value[m] != '\0' ; m++, pos++);
			candies[i] = atoi(value);
		}
		// Output candies values
		/*for(int i = 0; i < n_candy ; i++){
			printf("%d ", candies[i]);
		}
		printf("\n");*/
		int ans = candies[0];
		for(int i = 1; i < n_candy ; i++){
			ans = ans ^ candies[i];
		}
		if(ans != 0)
			fprintf(fo_ptr, "Case #%d: NO\n", (l+1));
		else{
			int min = 1000001;
			int min_index = -1;
			for(int i = 0; i < n_candy ; i++){
				if(min > candies[i]){
					min = candies[i];
					min_index = i;
				}
			}
			int sean_candy = 0;
			for(int i = 0; i < n_candy ; i++){
				if(i == min_index)
					continue;
				else
					sean_candy = sean_candy + candies[i];
			}
			fprintf(fo_ptr, "Case #%d: %d\n", (l+1), sean_candy);
		}

		delete [] candies;
	}
	//getchar();
	delete [] line;
	fclose(fi_ptr);
	fclose(fo_ptr);

}