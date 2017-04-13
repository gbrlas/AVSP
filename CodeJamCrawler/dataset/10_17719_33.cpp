#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv)
{

	int i;
	int totalLines;
	int n;
	long k;
	long exp;
	FILE *f;
	char str[15];
	char *ch;

	f = fopen(argv[1], "r");

	if(f == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}

	memset(str, 0, sizeof(str));
	fgets(str, 7, f);
	totalLines = atoi(str);

	for(i = 0; i < totalLines; i++)
	{
		memset(str, 0, sizeof(str));
		fgets(str, 15, f);

		ch = strstr(str, " ");

		n = atoi(str);
		k = atoi(ch);

		exp = pow(2, n);

		if((((k%exp)+1)%exp) == 0) 
			printf("Case #%d: ON\n", i+1);
		else
			printf("Case #%d: OFF\n", i+1);
	}

	fclose(f);

	return 0;
}

