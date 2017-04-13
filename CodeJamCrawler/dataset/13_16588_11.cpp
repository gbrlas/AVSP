#include<stdio.h>
#include<math.h>
void main(){
	int i,tcase;
	int r,t,n;
	FILE *fin,*fout;
	fin=fopen("A-small-attempt0.in","rw");
	fout=fopen("out.txt","ww");
	fscanf(fin,"%d",&tcase);
	for(i=1;i<=tcase;i++){
		fscanf(fin,"%d%d",&r,&t);
		n=1;
		while(2*n*n+2*r*n-n<=t) n++;
		fprintf(fout,"Case #%d: %d\n",i,n-1);
	}
	fclose(fin);
	fclose(fout);
}