#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<sstream>
int main(int argc, char* argv[]){
	FILE* fileIn,*fileOut;
	int numCases=0;
	int tot=0;
	int numA,numB,value;
	int values[10];
	char numS[12];
	char num[24];
	char founds;
	char numAS[12];
	char numBS[12];
	bool wrong;
	
	fileIn=fopen("input.in","rb");
	fileOut=fopen("output.dat","w");
	fscanf(fileIn,"%d",&numCases);
	
	for(int i=0;i<numCases;++i){
		fscanf(fileIn,"%d%d",&numA,&numB);
		

		tot=0;
		for(int j=numA;j<=numB;++j){
			itoa(j,numS,10);
			strcpy(num,numS);
			founds=0;
			for(int k=0;(k<strlen(numS)-1);++k){
				num[strlen(numS)+k]=numS[k];
				num[strlen(numS)+k+1]='\0';
				value=atoi(&num[k+1]);
				if(value>=numA && value <=numB && value>j)
				{
					wrong=false;
					for(int z=0;!wrong && z<founds;++z){
						if(values[z]==j)
							wrong=true;

					}
					if(!wrong){
						tot++;
						values[founds++]=value;
					}

					
				}
			}
		}
		


		fprintf(fileOut,"Case #%d: %d\n",i+1,tot);
	
	}

	fclose(fileIn);
	fclose(fileOut);
	return 0;
}