#include <stdio.h>

void solveCase()
{
	char combine[26][26];
	int oppose[26][26];
	int contains[26];
	
	char instring[4];
	char nchar;
	
	int C, D, N;
	
	char resString[100];
	int rlen=0;
	
	int i,j;
	
	for (i=0; i<26; i++)
	{
		for (j=0; j<26; j++)
		{
			combine[i][j] = 0;
			oppose[i][j] = 0;
		}
		contains[i] = 0;
	}
	
	scanf("%d", &C);
	
	for (i=0; i<C; i++)
	{
		scanf("%s", instring);
		combine[instring[0]-'A'][instring[1]-'A'] = instring[2];
		combine[instring[1]-'A'][instring[0]-'A'] = instring[2];
	}
	
	scanf("%d", &D);
	
	for (i=0; i<D; i++)
	{
		scanf("%s", instring);
		oppose[instring[0]-'A'][instring[1]-'A'] = 1;
		oppose[instring[1]-'A'][instring[0]-'A'] = 1;
	}
	
	scanf("%d", &N);
	
	for (i=0; i<N; i++)
	{
		scanf(" %c", &nchar);
		if (rlen != 0)
		{
			if (combine[resString[rlen-1]-'A'][nchar-'A'] != 0)
			{
				nchar = combine[resString[rlen-1]-'A'][nchar-'A'];
				rlen--;
				contains[resString[rlen]-'A']--;
			}
			
			for (j=0; j<26 && nchar != 0; j++)
			{
				if (contains[j] && oppose[nchar-'A'][j])
					nchar = 0;
			}
			if (nchar == 0)
			{
				rlen = 0;
				for (j=0; j<26; j++)
				{
					contains[j] = 0;
				}
			}
		}
		if (nchar != 0)
		{
			resString[rlen] = nchar;
			contains[nchar-'A']++;
			rlen++;
		}
	}
	
	printf("[");
	if (rlen != 0)
	{
		printf("%c", resString[0]);
	}
	for (i=1; i<rlen; i++)
	{
		printf(", %c", resString[i]);
	}
	printf("]\n");
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}
