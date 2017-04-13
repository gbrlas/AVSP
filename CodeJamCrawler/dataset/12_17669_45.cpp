#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
	FILE* fileIn,*fileOut;
	int numCases=0;
	int s,p,n,value,res;
	char str[400];
	
	

	fileIn=fopen("input.in","rb");
	fileOut=fopen("output.dat","w");
	fscanf(fileIn,"%d",&numCases);
	
	for(int i=0;i<numCases;++i){
		res=0;
	if(i==53)
		i=53;
		fscanf(fileIn,"%d%d%d",&n,&s,&p);
		for(int j=0;j<n;++j){
			fscanf(fileIn,"%d",&value);
		
			if(value>=(3*p-2)){
				res++;
				continue;
			}
			if(s && (value>=3*p-4) && (value>1)){
				res++;

				s--;

			}


		}
		fprintf(fileOut,"Case #%d: %d\n",i+1,res);
	
	}

	fclose(fileIn);
	fclose(fileOut);
	return 0;
}