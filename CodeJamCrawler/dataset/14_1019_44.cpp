#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numcases;
double C,F,X;
FILE * fpin,*fpout;
char fname[255];

void calc (){
	double prod=2;
	double t1=X/prod;
	double t2=0;
	int iter=1;
	int i=1;
	while (t2 < t1){
		prod=2;
		for(i=0; i < iter ;i++){
			t2=t2+C/prod;
			prod+=F;
		}
		t2+=X/prod;
		printf("times: %lf, %lf\n",t2,t1);
		if(t2 < t1){
			t1=t2;
			t2=0;
		}
		iter++;
	}
	printf("final: %lf\n", t1);
	fprintf(fpout,"%lf\n", t1);


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
	for(cases=0; cases < numcases; cases++){
		printf("case: %d,%d\n", cases, numcases);
		fprintf(fpout,"Case #%d: ", cases+1);
		fscanf(fpin,"%lf %lf %lf\n", &C, &F, &X);
		printf("Values: %lf, %lf, %lf\n", C, F, X);
		calc();
	}




	fclose(fpin);
	fclose(fpout);
	return 0;



}
