#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <fcntl.h>

void sustituye(char arr[]){
	int i = 0;
	while(arr[i]!= '\n'){
		switch(arr[i]){
			case 'a':
					arr[i] = 'y';
				break;

			case 'b':
					arr[i] = 'h';
				break;



			case 'c':
					arr[i] = 'e';
				break;

			case 'd':
					arr[i] = 's';
				break;

			case 'e':
					arr[i] = 'o';
				break;

/////////////////////////////////////////////////////////////////
			case 'f':
					arr[i] = 'c';
				break;

			case 'g':
					arr[i] = 'v';
				break;

			case 'h':
					arr[i] = 'x';
				break;

			case 'i':
					arr[i] = 'd';
				break;

			case 'j':
					arr[i] = 'u';
				break;

			case 'k':
					arr[i] = 'i';
				break;

			case 'l':
					arr[i] = 'g';
				break;

			case 'm':
					arr[i] = 'l';
				break;

			case 'n':
					arr[i] = 'b';
				break;

			case 'o':
					arr[i] = 'k';
				break;

			case 'p':
					arr[i] = 'r';
				break;

			case 'q':
					arr[i] = 'z';
				break;

			case 'r':
					arr[i] = 't';
				break;

			case 's':
					arr[i] = 'n';
				break;

			case 't':
					arr[i] = 'w';
				break;

			case 'u':
					arr[i] = 'j';
				break;

			case 'v':
					arr[i] = 'p';
				break;

			case 'w':
					arr[i] = 'f';
				break;

			case 'x':
					arr[i] = 'm';
				break;

			case 'y':
					arr[i] = 'a';
				break;

/////////////////////////////////////////////////////////////////////
			case 'z':
					arr[i] = 'q';
				break;
			case ' ':
					arr[i] = ' ';
				break;
		}
		i++;
	}
}

int main(){
	FILE * kFile;
	kFile=fopen("a.in", "r");
	char temp;
	int casos = 0;
	fscanf(kFile, "%i", &casos);

	char linea[102]= {'\0'};
	int i=0;
	int actual = 1;
	printf("%i\n", casos);
	fgets(linea, 102, kFile);
	memset(linea, '\0', 102);
	while(actual<casos+1){
		fgets(linea, 102, kFile);
		sustituye(linea);
		printf("Case #%i: %s", actual, linea);
		memset(linea, '\0', 102);
		actual++;

	}
	fclose(kFile);
	return 0;
}
