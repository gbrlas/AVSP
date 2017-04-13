#include <stdio.h>
#include <string.h>

#define MAX 32

char s[MAX];

char tab[MAX][MAX];

int main()
{
	int i, j, k, q, tam, cas, casos, a, b, resp, cnt, x;
	char tmp;
	
	scanf("%d", &casos);
	
	for (cas=1; cas<=casos; cas++)
	{
		printf("Case #%d: ", cas);
		
		scanf("%d %d", &a, &b);
		resp = 0;
		
		for (i=a; i<=b; i++)
		{
			sprintf(s, "%d", i);
			strcpy(tab[0], s);
			tam = strlen(s);
			cnt = 0;
			for (j=1; j<tam; j++)
			{
				tmp = s[0];
				for (k=1; k<tam; k++)
					s[k-1] = s[k];
				s[tam-1] = tmp;
				sscanf(s, "%d", &x);
				if (a <= x && x <= b && x!= i)
				{
					for (q=0; q<=cnt; q++)
						if (!strcmp(s, tab[q]))
							break;
					if (q>cnt)
					{
						cnt++;
						strcpy(tab[q], s);
					}	
					
				}
			}
			resp += cnt;
		}
		printf("%d\n", resp/2);
	}
	
	return 0;
}
