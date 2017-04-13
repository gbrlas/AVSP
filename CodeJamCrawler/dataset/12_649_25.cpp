#include <stdio.h>
#include <string.h>

int dancer_score[100];
//int max_score[100];
//int score_w_triplet[100];

int calcnum(int triplets, int score, int dancers ){
	int i=0;int possib_max,passed,mean,max,ret=0;;
	if(!dancers)
		return 0;
	if(!score)
		return dancers;
	for(i=0;i<dancers;i++){
		mean=dancer_score[i]/3;
		switch(dancer_score[i]%3){
			case 0: max=mean;possib_max=mean+1; break;	
			case 1: max=mean+1;possib_max=mean+1; break;
			case 2: max=mean+1;possib_max=mean+2; break;
	
		}
		//printf("i: %d, score: %d dancer_score: %d max: %d possib_max: %d\n",i,score,dancer_score[i], max, possib_max);	
		if(max>=score)
			ret++;
		else{
			if((triplets) && (possib_max==score) && mean){
				triplets--;
				ret++;			
			}
		}
	}
	return ret;
}


int main (char argc, char** argv ){
	FILE *fp;
	char input [256];
	int i,max_cases,dancers,triplets,score,j;
    //printf("Hello wolrd! \n");
    if( !(fp=fopen("jam2.txt","r"))){
		printf("Error opening file\n");
		return (-1);
    }
	else {
		fscanf(fp,"%d\n",&max_cases);
		//printf("max cases: %d\n",max_cases);
		for(i=0;i<max_cases; i++){
			memset(input,0,256);
			fscanf(fp,"%d %d %d",&dancers,&triplets,&score);
			for(j=0;j<dancers;j++)
				fscanf(fp,"%d",&dancer_score[j]);
			//calcnum(triplets,score,dancers);
			//printf("Case #%d: %d, %d, %d, score: %d \n",i,dancers,triplets,score,calcnum(triplets,score,dancers) );	
			printf("Case #%d: %d\n",i+1,calcnum(triplets,score,dancers) );	
		}	
	}		
}