#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int moves=0;
int A,B,K;
FILE *fpin, *fpout;
char fname[255];
int numcases;

void calc(){
	int win;
	int i,j;
	win=0;
	for(i=0;i<A;i++){
		for(j=0;j<B;j++){
			if((i&j)<K){
				win++;
			}
		}
	}
	fprintf(fpout, "%d\n",win);
	printf("win: %d\n",win);


}

int main (int argc, char **argv ){

	int i=0, j=0, cases;

	if(argc != 2){
		printf ("Usage: %s input_file_name\n", argv[0]);
		return 1;
	}
	printf("in : %s\n", argv[1]);
	fpin=fopen(argv[1],"r");
	sprintf(fname,"%s.out",argv[1]);
	fpout=fopen(fname,"w");
	fscanf(fpin,"%d\n", &numcases);
	printf("numcases: %d\n", numcases);
	//return 0;
	int strings;
	for(cases=0; cases < numcases; cases++){
		printf("CCCCCCCCCCCase: %d,%d\n", cases+1, numcases);
		fprintf(fpout,"Case #%d: ", cases+1);
		fscanf(fpin,"%d %d %d\n", &A, &B, &K);
		calc();
	}




	fclose(fpin);
	fclose(fpout);
	return 0;



}
