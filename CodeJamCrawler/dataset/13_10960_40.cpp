#include <string.h>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

int T;

int* input;
int* results;

void readInput(){
	char fn[256];

	//A-small-attempt0
	sprintf(fn, "C-small-attempt0.in");
	//A-large.in
	//sprintf(fn, "A-large.in");
	//sprintf(fn, "A-small-attempt0.in");

	FILE* pFile = fopen(fn, "rt");

	fscanf(pFile, "%d", &T);

	input = new int[T * 2];
	results = new int[T];

	memset(results, -1, sizeof(int) * T);

	int t, i, j;

	char temp;

	fscanf(pFile, "%c", &temp);

	int v;

	for(t = 0; t < T; ++t){

		fscanf(pFile, "%d", &(v));

		input[t * 2] = v;

		fscanf(pFile, "%c", &temp);

		fscanf(pFile, "%d", &(v));

		input[t * 2 + 1] = v;

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


void printInput(){
	int t, i;
	
	printf("%d\n", T);
	for(t = 0; t < T; ++t){

		for(i = 0; i < 2; ++i){
			printf("%d ", input[t * 2 + i]);
		}	

		printf("\n");
	}
}

void printResults(){
	char fn[256];

	sprintf(fn, "result.txt");

	FILE* pFile = fopen(fn, "wt");

	int i;

	for(i = 0; i < T; ++i){
		fprintf(pFile, "Case #%d: %d\n", i + 1, results[i]);
	}

	fclose(pFile);
}

bool ispalindromes(int v){
	char str[256];
	sprintf(str, "%d\n", v);

	int length;

	int i;

	for(i = 0; i < 256; ++i){
		if(str[i] == '\n'){
			length = i;

			break;
		}
	}

	int half = length / 2;

	for(i = 0; i < half; ++i){
		if(str[i] != str[length - 1 - i]){
			return false;
		}
	}

	return true;
}

bool checkTarget(int i, int lowBound, int uppBound){

	bool inbound;

	int target = i * i;

	printf("check i tar %d %d -> lowBound uppBound %d %d\n", i, target,  lowBound, uppBound);

	if(target >= lowBound && target <= uppBound){
		inbound = ispalindromes(i) && ispalindromes(target);

		printf("i, j, %d %d %d\n", i, target, inbound);
		if(inbound){
			return true;
		}
	}

	return false;
}

void checkResults(){
	int t, i;

	int low, upp;

	int lowBound, uppBound;

	bool isTarget;

	for(t = 0; t < T; ++t){
		printf("t %d\n", t);

		results[t] = 0;

		lowBound = input[t * 2];
		uppBound = input[t * 2 + 1];

		printf("low and upper bound %d, %d \n", lowBound, uppBound);

		low = sqrt((float)lowBound);

		upp = sqrt((float)uppBound);

		printf("get low and upp %d, %d\n", low, upp);

		for(i = low; i <= upp; ++i){
		//	printf("check i %d\n", i);
			isTarget = checkTarget(i, lowBound, uppBound);

			if(isTarget){
				results[t]++;
			}
		}
	}
}

int main(){
	input = NULL;
	results = NULL;

	readInput();

	printInput();

	checkResults();

	printResults();

	clearInput();
	
	return 0;	
}