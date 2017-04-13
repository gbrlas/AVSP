#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv){
	FILE* fi_ptr = fopen("D-small-attempt0.in", "r");
	FILE* fo_ptr = fopen("output.txt", "w");
	char* line = new char[9000];
	fgets(line, 8999, fi_ptr);
	// get no of iterations/cases
	int num_iter = atoi(line);
	char value[100];
	for(int l=0; l < num_iter ; l++){
		fgets(line, 8999, fi_ptr);
		int n = atoi(line);
		int* numbers = new int[n];
		fgets(line, 8999, fi_ptr);
		int pos = 0;
		for(int k=0; k<n ; k++){
			sscanf(line+pos, "%s", value);
			numbers[k] = atoi(value);
			pos++;
			for(int m=0; value[m] != '\0' ; m++, pos++);
		}
		// Output numbers
		/*for(int k=0; k<n ; k++)
			printf("%d ", numbers[k]);
		printf("\n");*/
		int identical = 0;
		for(int k=0; k<n ; k++){
			if(numbers[k] == k+1)
				identical++;
		}
		float different = n - identical;
		fprintf(fo_ptr, "Case #%d: %f\n", (l+1), different);
		
		

		delete [] numbers;
	}
	//getchar();
	delete [] line;
	fclose(fi_ptr);
	fclose(fo_ptr);
	return 0;
}