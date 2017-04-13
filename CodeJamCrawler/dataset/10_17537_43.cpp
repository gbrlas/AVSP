#include <stdio.h>
#include <stdlib.h>


int main(int argc,char*argv[]){
	char letter;
	int result;
	int l,d,n;
	int i,k,valExp;
	FILE*fin,*fout;
	fin=fopen("input.in","r");
	fout=fopen("output.out","w");
	fscanf(fin,"%d",&n);
	for(i=0;i<n;++i){
		valExp=1;
		fscanf(fin,"%d%d",&l,&d);
		fprintf(fout,"Case #%d: ",i+1);
		for(k=0;k<l;++k)
			valExp*=2;
		if(d%valExp==valExp-1)
			fprintf(fout,"ON\n");
		else
			fprintf(fout,"OFF\n");

	}
	fclose(fin);
	fclose(fout);
	return 0;
}