#include <stdio.h>

#define FORN(i, t) for(i = 1; i<=t; ++i)
#define READFROMFILE 1
#define WRITEFILE 1

void solve(int casenum);

char match [26] = 
{
	'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 
	'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

char str[101];

int main()
{
	int i, n;

#if READFROMFILE
	freopen("input.txt", "r", stdin);
#endif

#if WRITEFILE
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n", &n);

	FORN(i, n)
	{
		solve(i);
	}

	return 0;
}


void solve(int casenum)
{
	char c;

	printf("Case #%d: ", casenum);

	while((c = getc(stdin)) != '\r')
	{
		if(c == '\n')
			break;

		if(c == ' ')
			printf(" ");
		else
			printf("%c", match[c - 'a']);
	}

	printf("\n");
}