#include <stdio.h>
#include <stdlib.h>

unsigned char field[10][10];
int rows,cols;
FILE * fin, *fout;
int cases;
char buf[255];

void create_field(){
	int i,j;
	char c;
	for (i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			c=fgetc(fin);
			c-='0';
			field[i][j]=c;
			printf("%d",field[i][j]);
			fgetc(fin);
		}
		printf("\n");
	}
	
}

int calcrow(int rownum){
	int i;
	for (i=0;i<cols;i++)
		if(field[rownum][i]==2)
			return 1;
	return 0;
}

int calccol(int colnum){
	int i;
	for(i=0;i<rows;i++){
		if (field[i][colnum]==2)
			return 1;
	}
	return 0;
}


void calcsit(){
	char colour=0;
	int poss=1;
	//char morespace;
	int i,j;
	for (i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(field[i][j]==1 && calcrow(i) && calccol(j)){
				poss=0;
				goto end;
			}			
		}
	}
	end:
	if(poss){
		printf("possible\n");
		fprintf(fout,"YES\n");
	}
	else{
		printf("NO\n");
		fprintf(fout,"NO\n");
	}
	

		
}

int main(){
	int i;
	fin=fopen("in2.txt","r");
	fout=fopen("out.txt","w");
	if(fin == NULL){
		printf("AAAA \n");
		return(1);
	}
	/*while(fgets(buf,255,fin)){
		printf("%s\n",buf);
	}*/
	fscanf(fin,"%d\n", &cases);
	//fscanf(fin,"%s",buf);
	//printf("ok? :%s\n",buf);
	printf("cases: %d\n",cases);
	for(i=1;i<=cases;i++){
		printf("Case #%d\n",i);
		fprintf(fout,"Case #%d: ",i);
		fscanf(fin,"%d %d\n",&rows,&cols);
		printf("rows: %d,cols: %d\n",rows,cols);
		create_field();
		calcsit();
	}
	return(0);		
} 
