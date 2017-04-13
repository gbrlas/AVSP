#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if(argc<3)
		return 1;
	FILE *input = fopen(argv[1], "r");
	int numberOfCase;
	fscanf(input, "%d\n", &numberOfCase);
	char** G = new char*[numberOfCase];
	char translation[] = "yhesocvxduiglbkrztnwjpfmaq";

	for(int i = 0; i<numberOfCase; i++)
	{
		G[i] = new char[256];
		fgets(G[i], 256, input);
		printf("%s", G[i]);
		for(int j = 0; j<256&&G[i][j]!='\0'; j++)
			if(G[i][j]>96&&G[i][j]<123)
				G[i][j] = translation[G[i][j]-97];
		printf("%s", G[i]);
	}
	
	FILE *output = fopen(argv[2], "w");
	for(int i = 0; i<numberOfCase; i++)
		fprintf(output, "Case #%d: %s", i+1, G[i]);
}
