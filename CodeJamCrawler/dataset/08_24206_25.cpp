#include <iostream>
#include <stdio.h>
#include <string>


char S[100][101];
char Q[1000][101];


void init(){
	for (int i=0;i<100;i++)
		S[i][100]=0;
}

bool all(int p){
	for(int i=0;i<p;i++)
		if(S[i][100] == 0)
			return false;
	return true;
}


int main(){
	FILE *fptr=fopen("A-small-attempt1.in","r");
	FILE *f=fopen("output.txt","w");
	int o,p,q,sw;
	fscanf(fptr,"%d",&o);
	for(int t=1;t<=o;t++){
		fscanf(fptr,"%d",&p);
		fgets(S[0],2,fptr);
			for (int r=0;r<p;r++){
			fgets(S[r],100,fptr);
		}
		fscanf(fptr,"%d",&q);
		init();
		sw=0;
		fgets(Q[0],2,fptr);
		for (int z=0;z<q;z++){
			fgets(Q[z],100,fptr);
			for(int i=0;i<p;i++){
				if(!strcmp(S[i],Q[z])){
					S[i][100]=1;
					break;
				}
			}
			if(all(p)){
				sw++;
				init();
			}
			S[i][100]=1;
		}
		fprintf(f,"Case #%d: %d\n",t,sw);
	}
	return 0;
}