#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int numcases;
int bars;

double n[10];
double k[10];
double n2[10];
double k2[10];


FILE * fpin,*fpout;
char fname[255];


int compare( const void* a, const void* b)
{
	double int_a = * ( (double*) a );
	double int_b = * ( (double*) b );

	if ( int_a == int_b ) return 0;
	else if ( int_a < int_b ) return -1;
	else return 1;
}

void calc (){
	int i,j;
	int ken=0, nao=0;
	int kwin=0;
	
	memcpy(k2,k,sizeof(k));
	memcpy(n2,n,sizeof(n));
	
	qsort( k2, bars, sizeof(double), compare );
	qsort( n2, bars, sizeof(double), compare );

	printf("Sorted values\n");
	for(i=0;i < bars ;i++){
		printf("%lf ",n2[i]);
	}
	printf("\n");

	for(i=0;i < bars ;i++){
		printf("%lf ",k2[i]);
	}

	printf("\n");
	
	int up = bars-1;
	int down=0;
	int kup = bars-1;
	int kdown=0;
	
	for(j=0;j < bars; j++ ){
		if(n2[up] > k2[kup]){
			nao++;
			up--;
			kdown++;
			continue;
		}
		else{
			ken++;
			up--;
			kup--;
		}
	}

	printf("nwin_normal: %d, nao: %d kup: %d, kdown: %d\n",bars-ken, nao, kup,kdown);

	int ken2=0;
	int nao2=0;

	memcpy(k2,k,sizeof(k));
	memcpy(n2,n,sizeof(n));
	
	qsort( k2, bars, sizeof(double), compare );
	qsort( n2, bars, sizeof(double), compare );

	up = bars-1;
	down=0;
	kup = bars-1;
	kdown=0;
	int l;

	for(j=0; j < bars; j++ ){

		i=bars-1;
		if( n2[down] > k2[kdown] ){
			down++;
			kdown++;
			nao2++;
			continue;
		}
		else{
			printf("kwin, N:%lf , k: %lf\n",n2[up],k2[kup]  );
			down++;
			kup--;
			ken2++;
			continue;
		}
	}
	
	
	printf("deceit_win: %d, nao2: %d kup: %d, kdown: %d, gwals: %d %d\n",bars-ken2, nao2, kup,kdown, bars-ken2, bars-ken);
	//printf("deceit win: %d, gwals: %d %d\n", bars-ken2, bars-ken2, bars-ken );
	fprintf(fpout,"%d %d\n", bars-ken2, bars-ken );

	printf("\n");

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
		fprintf(fpout,"Case #%d: ", cases+1 );
		fscanf(fpin,"%d\n", &bars);
		for(j=0; j < 10; j++){
			n[j]=k[j]=0;
		
		}
		printf("ok\n");
		for(j=0; j < bars; j++)
			fscanf(fpin,"%lf ",&n[j]);
		fscanf(fpin,"\n");

		printf("Values: ");
		for(j=0; j < bars; j++)
			printf("%lf ",n[j]);
		printf("\n");

		for(j=0; j < bars; j++)
			fscanf(fpin,"%lf ",&k[j]);
		fscanf(fpin,"\n");

		printf("Values: ");
		for(j=0; j < bars; j++)
			printf("%lf ",k[j]);
		printf("\n");

		calc();

	}




	fclose(fpin);
	fclose(fpout);
	return 0;



}
