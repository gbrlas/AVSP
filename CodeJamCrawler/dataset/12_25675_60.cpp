#include <stdio.h>

#define MAX 256

char m[MAX];
char b[MAX];


int main()
{
	int n;
	int i, cas;
	
	m[(int)'a'] = 'y';
	m[(int)'b'] = 'h';
	m[(int)'c'] = 'e';
	m[(int)'d'] = 's';
	m[(int)'e'] = 'o';
	m[(int)'f'] = 'c';
	m[(int)'g'] = 'v';
	m[(int)'h'] = 'x';
	m[(int)'i'] = 'd';
	m[(int)'j'] = 'u';
	m[(int)'k'] = 'i';
	m[(int)'l'] = 'g';
	m[(int)'m'] = 'l';
	m[(int)'n'] = 'b';
	m[(int)'o'] = 'k';
	m[(int)'p'] = 'r';
	m[(int)'q'] = 'z';
	m[(int)'r'] = 't';
	m[(int)'s'] = 'n';
	m[(int)'t'] = 'w';
	m[(int)'u'] = 'j';
	m[(int)'v'] = 'p';
	m[(int)'w'] = 'f';
	m[(int)'x'] = 'm';
	m[(int)'y'] = 'a';
	m[(int)'z'] = 'q';

	m[(int)' '] = ' ';

	gets(b);
	sscanf(b, "%d", &n);
	
	for (cas = 1; cas <= n; cas++)
	{
		printf("Case #%d: ", cas);
		gets(b);
		for (i=0; b[i]; i++)
		{
			putchar(m[(int)b[i]]);
		}
		putchar('\n');
	}
	
	return 0;
	
}
