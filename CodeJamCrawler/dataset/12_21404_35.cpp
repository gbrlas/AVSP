//============================================================================
// Name        : Google code jam 2012, Qualification Round 2012, Problem A
// Author      : Jaroslav Bucko
//============================================================================

#include <stdio.h>

int main() {
	char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char c=0;
	int t=0;
	scanf("%d\n",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		do{
			c=getchar();
			if (c==' ' || c=='\n')
			{
				putchar(c);
			}
			else
			{
				putchar(map[c-'a']);
			}

		} while (c!='\n');
	}
	return 0;
}
