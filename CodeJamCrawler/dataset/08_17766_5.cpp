#include<stdio.h>
#include<stdlib.h>

//global data
float **A, **B;	//timetables at A,B.
float *DepQAtA, *DepQAtB;	//departure queues at A,B.

//fn prototypes
void initGlobalData(FILE*,int,int);
void enQ(float*,int,int,float);

int main(){
	FILE *fpin, *fpout;
	int N, NA, NB;
	int i;
	float T;
	int startedA, startedB, fdA,fdB;
	int lenA, lenB, frontA, frontB, endA, endB;	//length,front and end of departure queues.

	fpin=fopen("input.txt","r");
	fpout=fopen("output.txt","w");
	fscanf(fpin,"%d", &N);

	for(i=1;i<=N;i++){
		startedA=0,startedB=0,fdA=0,fdB=0,lenA=0,lenB=0,frontA=0,frontB=0,endA=0;endB=0;
		fscanf(fpin,"%f",&T); T=T/(float)60.0;

		fscanf(fpin,"%d%d",&NA,&NB);
		initGlobalData(fpin,NA,NB);	
		DepQAtA=(float*)calloc(sizeof(float),NB);
		DepQAtB=(float*)calloc(sizeof(float),NA);
		//actual processing
		while(1){
			if(fdA>=NA && fdB>=NB) break;
			else if(fdA<NA && fdB<NB){
				if(A[fdA][0]<=B[fdB][0]){
					if(lenA==0) {startedA++;}//printf(" 2.1.1 ");}
					else if(DepQAtA[frontA]>A[fdA][0]){startedA++;}//printf(" 2.1.2 ");}
					else {frontA++;}//printf("2.1.3 ");}
					enQ(DepQAtB,frontB,endB,A[fdA][1]+T);
					//printf("%f:%f  ",A[fdA][1],DepQAtB[frontB]);
					endB++; fdA++;
		//printf("c%d startedA=%d fdA=%d startedB=%d fdB=%d\n",i,startedA, fdA,startedB,fdB);
				}
				else{
					if(lenB==0) {startedB++;}
			//printf(" 2.2.1 ");}
					else if(DepQAtB[frontB]>B[fdB][0]){startedB++;}
//			printf("2.2.2 ");}
					else {frontB++;}
//			printf("2.2.3 ");}
					enQ(DepQAtA,frontA,endA,B[fdB][1]+T);
					//printf("%f:%f ",B[fdB][1]+T,DepQAtA[frontA]);
					endA++; fdB++;
//			printf("c%d startedA=%d fdA=%d startedB=%d fdB=%d \n",i,startedA, fdA,startedB,fdB);
				}
			}
			else if(fdA<NA && fdB>=NB){
				if(lenA==0) {startedA++;}
//		printf("2.3.1 ");}
				else if(DepQAtA[frontA]>A[fdA][0]){ startedA++;}
//	       printf(" 2.3.2 ");}
				else{ frontA++;}
//		printf(" 2.3.3 ");}
				enQ(DepQAtB,frontB,endB,A[fdA][1]+T);
				endB++; fdA++;
				//printf("%f ",A[fdA][1]+T);
//			printf("c%d startedA=%d fdA=%d startedB=%d fdB=%d\n",i,startedA, fdA,startedB,fdB);
			}
			else if(fdA>=NA && fdB<NB){
				if(lenB==0) {startedB++;}
//		printf(" 2.4.1 ");}
				else if(DepQAtB[frontB]>B[fdB][0]){ startedB++;}
//			printf("2.4.2 ");}
				else {frontB++;}
//		printf(" 2.4.3 ");}
				enQ(DepQAtA,frontA,endA,B[fdB][1]+T);
				endA++; fdB++;
				//printf("%f ",B[fdB][1]+T);
//			printf("c%d startedA=%d fdA=%d startedB=%d fdB=%d \n",i,startedA, fdA,startedB,fdB);
			}
			lenA=endA-frontA, lenB=endB-frontB;
		}//end of while loop
		//printf("loop over\n");
		fprintf(fpout,"Case #%d: %d %d\n",i,startedA,startedB);
		free(DepQAtA); free(DepQAtB);
		free(A); free(B);
	}//end of for loop
	fclose(fpout);
	fclose(fpin);
	return 0;
}
//fn definitions
void initGlobalData(FILE *fp,int na, int nb){
	int hour,min;
	float timea,timed;
	int i,j;
	char c;

	A=(float**)calloc(sizeof(float*),na);
	for(i=0;i<na;i++){
		A[i]=(float*)calloc(sizeof(float),2);
		fscanf(fp,"%d%c%d",&hour,&c,&min);
	//	printf("%d %d",hour, min);
		timed=(float)hour+(float)min/(float)60.0;;
		fscanf(fp,"%d%c%d",&hour,&c,&min);
//		printf("%d %d\n",hour, min);
		timea=(float)hour+(float)min/(float)60.0;
		//printf("%f %f\n",timed, timea);
		j=i-1;	//sort A
		while(j>=0 && timed<A[j][0]){
			A[j+1][0]=A[j][0],A[j+1][1]=A[j][1];
			j--;
		}
		A[j+1][0]=timed, A[j+1][1]=timea;
	}
	B=(float**)calloc(sizeof(float*),nb);
	for(i=0;i<nb;i++){
		B[i]=(float*)calloc(sizeof(float),2);
		 fscanf(fp,"%d%c%d",&hour,&c,&min);
		 timed=(float)hour+(float)min/(float)60.0;
//		 printf("%f %f\n",timed, timea);
		 fscanf(fp,"%d%c%d",&hour,&c,&min);
		 timea=(float)hour+(float)min/(float)60.0;
		 //printf("%f %f\n",timed, timea);
		// printf("%f %f\n",timed, timea);
		 j=i-1;   //sort B
		 while(j>=0 && timed<B[j][0]){
			B[j+1][0]=B[j][0],B[j+1][1]=B[j][1];
			 j--;
		 }
		 B[j+1][0]=timed, B[j+1][1]=timea;
	}
	//printf("sorted\n");
	//for(i=0;i<na;i++)printf("%f %f\n",A[i][0],A[i][1]);
	//for(i=0;i<nb;i++)printf("%f %f\n",B[i][0],B[i][1]);

}

void enQ(float* a, int front, int end, float n){
	int i=end-front-1;
	while(i>=0 && n<a[i+front]){
		a[i+front+1]=a[i+front];
		i--;
	}
	a[i+front+1]=n;
}
