#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char fname[255];
int a[4];
int b[4];
int t[4];
int res=0;
int nok=0;
int anum,bnum;
int numcases;
FILE * fpin,*fpout;

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
	for(cases=0;cases < numcases; cases++){
		fscanf(fpin,"%d\n", &anum);
		for(i=0 ; i < 4 ; i++){
			if(i+1 == anum)
				fscanf(fpin,"%d %d %d %d\n",&a[0], &a[1],&a[2],&a[3]  );
			else
				fscanf(fpin,"%d %d %d %d\n",&t[0], &t[1],&t[2],&t[3]  );
		}
		printf("anum: %d, row: %d %d %d %d\n",anum, a[0], a[1],a[2],a[3] );
		fscanf(fpin,"%d\n", &bnum);
		for(i=0 ; i < 4 ; i++){
			if(i+1 == bnum)
				fscanf(fpin,"%d %d %d %d\n",&b[0], &b[1],&b[2],&b[3]  );
			else
				fscanf(fpin,"%d %d %d %d\n",&t[0], &t[1],&t[2],&t[3]  );
		}
		printf("bnum: %d, row: %d %d %d %d\n",bnum, b[0], b[1],b[2],b[3] );
		res=0;
		nok=0;
		for(i=0;i<4 ;i++){
			for(j=0; j<4 ; j++){
				if(a[i] == b[j]){
					if(0==res)
						res=a[i];
					else
						nok=1;
				}
			}
		}
		printf ("Case #%d: ",cases+1);
		fprintf (fpout,"Case #%d: ",cases+1);
		if(nok){
			printf("Bad magician!\n");
			fprintf(fpout,"Bad magician!\n");
		}
		else{
			if(res){
				printf("%d\n",res);
				fprintf(fpout,"%d\n",res);
			}
			else{
				printf("Volunteer cheated!\n");
				fprintf(fpout,"Volunteer cheated!\n");
			}
		}
	}




	fclose(fpin);
	fclose(fpout);
	return 0;



}

