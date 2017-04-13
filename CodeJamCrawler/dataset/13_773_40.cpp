#include <stdio.h>
#include <stdlib.h>

unsigned char field[4][4];
FILE * fin, *fout;
int cases;
char buf[255];

void create_field(){
	int i,j;
	char c;
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			c=fgetc(fin);
			printf("%c",c);
			if(c=='O')
				field[i][j]=1;
			else if (c=='X')
				field[i][j]=2;
			else if (c=='T')
				field[i][j]=3;
			else
				field[i][j]=0;
			printf("%d",field[i][j]);
		}
		printf("\n");
		fgetc(fin);
	}
	printf("\n");
	fgetc(fin);
	
}

int calcrow(int rownum){
	int i,j,colour;
	if(field[rownum][0])
		colour=field[rownum][0];
	else
		return 0;
	for(i=1;i<4;i++){
		if (field[rownum][i]!=colour)
			if(colour==3)
				colour=field[rownum][i];
			else if(field[rownum][i]!=3)
				return 0;
	}
	return colour;
}

int calccol(int colnum){
	int i,j,colour;
	if(field[0][colnum])
		colour=field[0][colnum];
	else
		return 0;
	for(i=1;i<4;i++){
		if (field[i][colnum]!=colour)
			if(colour==3)
				colour=field[i][colnum];
			else if(field[i][colnum]!=3)
				return 0;
	}
	return colour;
}

int calcdiag1(){
	int i,colour;
	if(field[0][0])
		colour=field[0][0];
	else
		return 0;
	for(i=1;i<4;i++){
		if (field[i][i]!=colour)
			if(colour==3)
				colour=field[i][i];
			else if(field[i][i]!=3)
				return 0;
	}
	return colour;

}

int calcdiag2(){
	int i,colour;
	if(field[0][3])
		colour=field[0][3];
	else
		return 0;
	for(i=1;i<4;i++){
		if (field[i][3-i]!=colour)
			if(colour==3)
				colour=field[i][3-i];
			else if(field[i][3-i]!=3)
				return 0;
	}
	return colour;

}

int calcdraw(){
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(!field[i][j])
				return 0;
	return 1;
}

void calcsit(){
	char colour=0;
	int win=0,draw=0;
	//char morespace;
	int i,j;
	for (i=0;i<4;i++){
		if (win=calcrow(i))
			goto end;
		if (win=calccol(i))
			goto end;
	}
	if(win=calcdiag1())
		goto end;
	if(win=calcdiag2())
		goto end;
	draw=calcdraw();
	end:
	if(win==1){
		printf("O won\n");
		fprintf(fout,"O won\n");
	}
	else if(win==2){
		printf("X won\n");
		fprintf(fout,"X won\n");
	}
	else if(draw==1){
		printf("Draw\n");
		fprintf(fout,"Draw\n");
	}
	else{ 
		printf("Not finished\n");
		fprintf(fout,"Game has not completed\n");
	}

		
}

int main(){
	int i;
	fin=fopen("in_large.txt","r");
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
		create_field();
		calcsit();
	}
	return(0);		
} 
