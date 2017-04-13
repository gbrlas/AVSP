#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int moves=0;
char A[101], B[101];
char Achar[101], Bchar [101];
int Achars[101],Bchars [101];
FILE *fpin, *fpout;
char fname[255];
int numcases;

void calc(){
	int i=0;
	int j=0;
	int m=0;
	memset(Achar,0,101);
	memset(Bchar,0,101);
	memset(Achars,0,101*sizeof(int));
	memset(Bchars,0,101*sizeof(int));
	char act;
	act=A[0];
	Achar[0]=A[0];
	Achars[0]=1;
	i=1;
	j=0;
	while( A[i] ){
		if( A[i]!=act){
			j++;
			act=A[i];
			Achar[j]=act;
			Achars[j]=1;
		}
		else{
			Achars[j]= Achars[j]+1;
		}
		printf("i: %d, j:%d ,Achar[j]: %c Achars[j]: %d\n",i,j,Achar[j],Achars[j]);
		i++;
	}
	i=0;
	printf("Achar: %s ",Achar);
	printf("\n");
	printf("       ");
	while(Achars[i]){
		printf("%d", Achars[i]);
		i++;
	}
	printf("\n");
	printf("B: %s\n",B);
	act=B[0];
	Bchar[0]=B[0];
	Bchars[0]=1;
	i=1;
	j=0;
	while( B[i] ){
		if( B[i]!=act){
			j++;
			act=B[i];
			Bchar[j]=act;
			Bchars[j]=1;
		}
		else{
			Bchars[j]=Bchars[j]+1;
		}
		i++;
	}
	printf("Bchar: %s",Bchar);
	printf("\n");


	if(strlen(Achar) != strlen(Bchar)){
		printf("Fegla Won\n");
		fprintf(fpout,"Fegla Won\n");
	}
	else{
		i=0;
		while(Achars[i]){
			if(Achar[i]!=Bchar[i]){
				printf("Fegla Won\n");
				fprintf(fpout,"Fegla Won\n");
				return;
			}
			m += Achars[i]> Bchars[i] ? Achars[i]-Bchars[i]: Bchars[i]-Achars[i];
			i++;
		}
		printf("moves: %d\n", m);
		fprintf(fpout,"%d\n", m);
	}




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
		fscanf(fpin,"%d\n", &strings);
		printf("Strings: %d\n",strings);
		fscanf(fpin,"%s\n",A);
		fscanf(fpin,"%s\n",B);
		calc();
	}




	fclose(fpin);
	fclose(fpout);
	return 0;



}
