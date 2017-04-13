#include <stdio.h>
#include <string.h>

char *from="ynficwlbkuomxsevzpdrjgthaq";
char *to  ="abcdefghijklmnopqrstuvwxyz";


void decode (char *input){
	int i,idx;
	while(*input){
		if( (*input >= 'a') && (*input <= 'z')){
			for (i=0;i<26;i++){
				if(from[i]==*input)
					idx=i;			
			}
			*input=to[idx];
		}
		input++; 	
	}
}

int main (char argc, char** argv ){
	FILE *fp;
	char input [256];
	int i,max_cases;
    //printf("Hello wolrd! \n");
    if( !(fp=fopen("exc1.txt","r"))){
		printf("Error opening file\n");
		return (-1);
    }
	else {
		fscanf(fp,"%d\n",&max_cases);
		//printf("max cases: %d\n",max_cases);
		for(i=0;i<max_cases; i++){
			memset(input,0,256);
			fgets(input,256,fp);
			decode(input);
			printf("Case #%d: %s",i+1,input);		
		}	
	}
	
		
}