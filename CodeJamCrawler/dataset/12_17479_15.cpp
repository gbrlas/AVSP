#include <stdio.h>
#include <string.h>

int main()
{
	char b[26];
	b[0] = 'y';
	b[1] = 'h';
	b[2] = 'e';
	b[3] = 's';
	b[4] = 'o';
	b[5] = 'c';
	b[6] = 'v';
	b[7] = 'x';
	b[8] = 'd';
	b[9] = 'u';
	b[10] = 'i';
	b[11] = 'g';
	b[12] = 'l';
	b[13] = 'b';
	b[14] = 'k';
	b[15] = 'r';
	b[16] = 'z';
	b[17] = 't';
	b[18] = 'n';
	b[19] = 'w';
	b[20] = 'j';
	b[21] = 'p';
	b[22] = 'f';
	b[23] = 'm';
	b[24] = 'a';
	b[25] = 'q';

	int d, i;
	char a[5000];
	int count = 0;

	scanf("%d", &d);
	getchar();

	while(d--)
	{
		count++;
		gets(a);

		printf("Case #%d: ", count);

		for(i=0; i<strlen(a); i++)
		{
			if (a[i]!=' ')
				printf("%c", b[a[i]-97]);
			else
				printf(" ");
		}

		printf("\n");
	}
	
	return 0;
}

