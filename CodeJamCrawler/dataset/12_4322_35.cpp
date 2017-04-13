#include<stdio.h>
#define N 31

char m[26][2],input[N][101],n;

void main(){
	int i,j;
	char tp;
	FILE *in = fopen("A-small-attempt1.in","r");
	FILE *out = fopen("output.txt","w");
	
	//--------------------------

	for(i=0;i<n;i++){
		m[i][0] = 'a'+i;
	}
	m[0][1] = 'y';
	m[1][1] = 'h';
	m[2][1] = 'e';
	m[3][1] = 's';
	m[4][1] = 'o';
	m[5][1] = 'c';
	m[6][1] = 'v';
	m[7][1] = 'x';
	m[8][1] = 'd';
	m[9][1] = 'u';
	m[10][1] = 'i';
	m[11][1] = 'g';
	m[12][1] = 'l';
	m[13][1] = 'b';
	m[14][1] = 'k';
	m[15][1] = 'r';
	m[16][1] = 'z';//q
	m[17][1] = 't';
	m[18][1] = 'n';
	m[19][1] = 'w';
	m[20][1] = 'j';
	m[21][1] = 'p';
	m[22][1] = 'f';
	m[23][1] = 'm';
	m[24][1] = 'a';
	m[25][1] = 'q';//z

	fscanf(in,"%d",&n);
	fgets(input[0],1024,in);
	for(i=0;i<n;i++){
		fgets(input[i],1024,in);
		//printf("%s\n",input[i]);
	}

	for(i=0;i<n;i++){
		fprintf(out,"Case #%d: ",i+1);
		for(j=0;j<100;j++){
			if(input[i][j] >= 'a' && input[i][j] <= 'z')
				fprintf(out,"%c",m[input[i][j]-'a'][1]);
			else
				fprintf(out," ");
		}
		fprintf(out,"\n");
	}


	fclose(in);
	fclose(out);
}