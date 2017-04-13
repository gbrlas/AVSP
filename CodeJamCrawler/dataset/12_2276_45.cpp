/*
 * milkshakes.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: Changhe
 */

#include "stdio.h"
#include "string.h"

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

char buf_in[110];
char buf_out[110];
char trans[27] = "yhesocvxduiglbkrztnwjpfmaq";
int case_number;
#define printg case_number++, fprintf(fp2, "Case #%d: ",case_number)


void docase(FILE* fp, FILE* fp2) {
	printg;
	fgets(buf_in, 110, fp);
	for (int i=0; i<strlen(buf_in)-1; i++)
	{
		if(buf_in[i] != ' ')	fprintf(fp2, "%c", trans[buf_in[i] - 'a']);
		else fprintf(fp2, "%c", ' ');
	}
	fprintf(fp2, "\n");
}

void train(){
	fgets(buf_in, 110, stdin);
	fgets(buf_out, 110, stdin);
	for (int i=0; i<strlen(buf_in); i++)
	{
		if(buf_in[i] != ' ') trans[buf_in[i] - 'a'] = buf_out[i];
	}
}

int main(int argc, char* argv[]){
	int number_of_test_cases, i;
	FILE* fp = fopen(argv[1], "r");
	FILE* fp2 = fopen(argv[2], "w");
	fscanf(fp, "%d\n", &number_of_test_cases);
	REP(i,number_of_test_cases)
		docase(fp, fp2);
	fclose(fp);
	fclose(fp2);
	return 0;
}