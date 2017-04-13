#include<stdio.h>
#include<stdlib.h>

main(){
  FILE *fp;
  int T,C,D,N,M,i,j,k,l,m,t;
  fp=fopen("input","r");
  fscanf(fp,"%d",&T);
  
  for(i=0;i<T;i++){
  
  	int C,D,N,M,j,k,l,m,t;
		char A[3]="0",B[2]="0",X[10]="0",Y[10]="0";  
		int flag1=0,flag2=0;  
    fscanf(fp,"%d",&C);
    for(j=0;j<C;j++)
      fscanf(fp,"%s",A);
		fscanf(fp,"%d",&D);
		for(k=0;k<D;k++)
      fscanf(fp,"%s",B);
    fscanf(fp,"%d",&N);
	  fscanf(fp,"%s",Y);
    M=N;
    
       //   printf("delete %s\n",B);
       //   printf("replace %s\n",A);
       //   printf("test %s\n",Y);
    
    for(l=0,m=0;m<M,l<N;l++,m++){
			X[l]=Y[m];
			     // printf("\nX[%d][%d]=%c \n",i,l,X[l]);
			   //   printf("l=%d m=%d \n",l,m);
			      //printf("N=%d \n",N);
			
			if(X[l]==B[0]){
			flag1=1;}
			if(X[l]==B[1]){
			flag2=1;}
			      //printf("f1=%d f2=%d\n",flag1,flag2);
			if(l>0){
			      //replace
				if(((X[l-1]==A[0])&&(X[l]==A[1]))||((X[l-1]==A[1])&&(X[l]==A[0]))){
					//      printf("new character\n");
					X[l-1]=A[2];
					l=l-1;
					N=N-1;
					flag1=0;
					flag2=0;
					for(t=0;t<=l;t++){
						if(X[t]==B[0]){
						flag1=1;}
						if(X[t]==B[1]){
						flag2=1;}
						}
					}
			      //delete
				if(((X[l]==B[0])&&(flag2==1))||((X[l]==B[1])&&(flag1==1))){
				//	      printf("delete all\n");
					N=N-l-1;
					l=-1;
					flag1=0;
					flag2=0;
				}
			}
		}	
				//printf("l=%d m=%d \n",l,m);
			  //printf("N=%d \n",N);
				printf("Case #%d: [",i+1);
				for(l=0;l<N-1;l++)
				printf("%c, ",X[l]);
				if(N!=0)
				printf("%c]\n",X[N-1]);
				else
				printf("]\n");
				
		}
	}
	
  
  
             
  


