#include <stdio.h>
#include <stdlib.h>

unsigned long long int sum,num;


int rows,cols;
FILE * fin, *fout;
int cases;
char buf[255];
char f_out[255];


void calcres(unsigned long long int sum, unsigned long long int num){
	unsigned long long int part=0;
	unsigned long long int i=0;
	unsigned long long element=0;
	element=2*(num+1)-1;
	//printf("part: %llu, i: %llu \n",part,i);
	while(part<=sum){
		part+=element;
		element=element+4;
		i++;
		//printf("part: %llu, i: %llu \n",part,i);
	}
	printf("end i: %llu\n",i-1);
	fprintf(fout,"%llu\n",i-1);
	

}


int main(int argc, char **argv ){
	int i;
	
	printf("argc: %d\n",argc);
	if(argc > 1 ){
		printf("fname: %s\n",argv[1]);
		fin=fopen(argv[1],"r");
		sprintf(f_out,"%s.out",argv[1]);
		fout=fopen(f_out,"w");

	}
	else{
		fin=fopen("in2.txt","r");
		fout=fopen("out.txt","w");
	}
	if(fin == NULL){
		printf("AAAA \n");
		//return(1);
	}
	/*while(fgets(buf,255,fin)){
		printf("%s\n",buf);
	}*/
	//fscanf(fin,"%s",buf);
	//printf("ok? :%s\n",buf);
	fscanf(fin,"%d\n", &cases);
	printf("cases: %d\n",cases);
	//fprintf(fout,"Ok\n");
	
	for(i=1;i<=cases;i++){
		printf("Case #%d\n",i);
		fprintf(fout,"Case #%d: ",i);
		fscanf(fin,"%llu %llu\n",&num,&sum);
		//printf("num: %llu\n",sum);
		calcres(sum,num);
	}
	return(0);		
} 
