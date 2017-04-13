#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX 1000

int main(int argc,char*argv[]){
	int cases;
	int i;
	__int64 result;
	char used[MAX];
	int n,k,r;
	int cont;
	int aux;
	int g[MAX];
	FILE*fin,*fout;
	int numV;
	fin=fopen("input.in","r");
	fout=fopen("output.out","w");
	fscanf(fin,"%d",&cases);
	for(i=0;i<cases;++i){
		result=0;
		fprintf(fout,"Case #%d: ",i+1);
		fscanf(fin,"%d%d%d",&r,&k,&n);
		for(cont=0;cont<n;++cont)
			fscanf(fin,"%d",&g[cont]);
		numV=0;
		for(cont=0;cont<r;++cont){
			memset(used,0,sizeof(char)*MAX);
			aux=k;
			while((aux-g[numV%n]>=0)&&(!used[numV%n])){
				aux-=g[numV%n];
				result+=g[numV%n];
				used[numV%n]=1;
				numV++;
			}

		}



		fprintf(fout,"%I64d\n",result);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}