# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char q[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char line[1000], *p;
int n;

int main()
{
	int kase=0;
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.txt", "w", stdout);

	scanf("%d%*c", &n);

	while (n)
	{
		fgets(line, 1000, stdin);
		printf("Case #%d: ",++kase);

		p=line;

		while (*p!='\n')
		{
			if (*p==' ') printf(" "); else printf("%c", q[*p-'a']);
			p++;
		}

		printf("\n");
		
		n--;
	}
}