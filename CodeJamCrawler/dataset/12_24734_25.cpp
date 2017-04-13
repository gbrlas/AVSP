#include <stdio.h>

const char h[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
	char s[200];

	int i, j, l, t;
	char c;

	FILE * fin = fopen("A-small-attempt1.in", "r");
	FILE * fout = fopen("A-small-attempt1.out", "w");

	fscanf(fin, "%d\n", &t);

	for (i = 1; i <= t; i++)
	{
		l = 0;
		while ( fscanf(fin, "%c", &c)  &&  c != 10 )
			s[l++] = c;
		fprintf(fout, "Case #%d: ", i);
		for (j = 0; j < l; j++)
			if ( s[j] != ' ' )
				fprintf(fout, "%c", h[s[j]-'a']);
			else
				fprintf(fout, " ");
		fprintf(fout, "\n");
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

