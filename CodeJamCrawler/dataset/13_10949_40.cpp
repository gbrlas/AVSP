#include <string.h>
#include <stdio.h>

//using namespace std;

#define DIM 4
#define DIMXY 16

int T;

//char* input;

int* input;
int* results;

void readInput(){
	char fn[256];

	//A-small-attempt0
	//sprintf(fn, "test.txt");
	sprintf(fn, "A-small-attempt0.in");

	FILE* pFile = fopen(fn, "rt");

	fscanf(pFile, "%d", &T);

//	input = new char[T * DIMXY];
	input = new int[T * DIMXY];
	results = new int[T];

	memset(results, -1, sizeof(int) * T);

	int t, i, j;

	char temp;

	fscanf(pFile, "%c", &temp);

	for(t = 0; t < T; ++t){
		for(j = 0; j < DIM; ++j){
			for(i = 0; i < DIM; ++i){
				fscanf(pFile, "%c", &(temp));

				if(temp == 'X'){
					input[t * DIMXY + j * DIM + i] = 1;
				}else if(temp == 'O'){
					input[t * DIMXY + j * DIM + i] = -1;
				}else if(temp == 'T'){
					input[t * DIMXY + j * DIM + i] = 0;
				}else{
					input[t * DIMXY + j * DIM + i] = -100;
				}
			}

			fscanf(pFile, "%c", &temp);
		}

		fscanf(pFile, "%c", &temp);
	}

	fclose(pFile);
}

void clearInput(){
	if(input != NULL){
		delete[] input;
	}

	if(results != NULL){
		delete[] results;
	}
}

void checkResults(){
	int t, i, j;

	int vh[4], vv[4], vd[2];

	bool hasDot;

	for(t = 0; t < T; ++t){
	//	printf("t %d, T %d\n", t, T);
		hasDot = false;

		memset(vh, 0, sizeof(int) * 4);
		memset(vv, 0, sizeof(int) * 4);
		memset(vd, 0, sizeof(int) * 2);

		for(j = 0; j < DIM; ++j){
			for(i = 0; i < DIM; ++i){
				if(input[t * DIMXY + j * DIM + i] == -100){
					hasDot = true;
				}

				vh[j] += input[t * DIMXY + j * DIM + i];

				vv[i] += input[t * DIMXY + j * DIM + i];

				if(i == j){
					vd[0] += input[t * DIMXY + j * DIM + i];
				}

				if((i + j + 1) == DIM){
					vd[1] += input[t * DIMXY + j * DIM + i];
				}
			}
		}

		////////////// check
		for(i = 0; i < DIM && results[t] == -1; ++i){
			if(vv[i] == 3 || vv[i] == 4){
				results[t] = 0;
			}else if(vv[i] == -3 || vv[i] == -4){
				results[t] = 1;
			}else if(vh[i] == 3 || vh[i] == 4){
				results[t] = 0;
			}else if(vh[i] == -3 || vh[i] == -4){
				results[t] = 1;
			}
		}

		if(results[t] == -1){
			if(vd[0] == 3 || vd[0] == 4){
				results[t] = 0;
			}else if(vd[0] == -3 || vd[0] == -4){
				results[t] = 1;
			}else if(vd[1] == 3 || vd[1] == 4){
				results[t] = 0;
			}if(vd[1] == -3 || vd[1] == -4){
				results[t] = 1;
			}
		}

		/////////// draw
		if(results[t] == -1){
			if(hasDot == true){
				results[t] = 3;
			}else{
				results[t] = 2;
			}
		}
	}
}

/*
void printInput(){
	int t, i, j;
	
	printf("%d\n", T);
	for(t = 0; t < T; ++t){
		for(j = 0; j < DIM; ++j){
			for(i = 0; i < DIM; ++i){
				printf("%c", input[t * DIMXY + j * DIM + i]);
			}

			printf("\n");
		}

		printf("\n");
	}
}
*/

void printResults(){
	int i;

	for(i = 0; i < T; ++i){
		if(results[i] == 0){
			printf("Case #%d: X won\n", i + 1);
		}else if(results[i] == 1){
			printf("Case #%d: O won\n", i + 1);
		}else if(results[i] == 2){
			printf("Case #%d: Draw\n", i + 1);
		}else if(results[i] == 3){
			printf("Case #%d: Game has not completed\n", i + 1);
		}else if(results[i] == -1){
			printf("Case #%d: I have not tested\n", i + 1);
		}
	}
}

int main(){
	input = NULL;
	results = NULL;

	readInput();

//	printInput();

	checkResults();

	printResults();

	clearInput();

	return 0;	
}