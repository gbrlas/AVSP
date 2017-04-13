#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MYDEBUG			0

int T;
int Bound[55][2];
int Cnt[55];

void revolve(const char *st, char *nst, int loca, int len);

int main(void)
{

	int i, j, k, l;
	int len;

	char str1[13], str2[13], temp[13];
	FILE *fp;

	//output file
	fp = fopen("result.txt", "w");

	//freopen("C-large.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	//freopen("a.txt", "r", stdin);

	scanf("%d", &T);

	for(i = 0; i < T; i++)
	{
		Cnt[i] = 0;
		scanf("%d%d", &Bound[i][0], &Bound[i][1]);	
		//itoa(number, string, 10);		//10-base

#if MYDEBUG
		printf("%d %d\n", Bound[i][0], Bound[i][1]);
#endif
		//compare strings.
		for(j = Bound[i][0]; j < Bound[i][1]; j++)
		{
			for(k = j + 1; k <= Bound[i][1]; k++)
			{
				itoa(j, str1, 10);
				itoa(k, str2, 10);
				len = strlen(str1);	//str2 the same.

				for(l = 0; l < len; l++)
				{
					revolve(str1, temp, l, len);
					if(strcmp(temp, str2) == 0)
					{
						Cnt[i]++;
						break;
					}
				}
			}
		}

		fprintf(fp, "Case #%d: %d\n", i + 1, Cnt[i]);
		
	}

	fclose(fp);
	fclose(stdin);

#if 0
	i = 12345, j = 23451;
	itoa(i, str1, 10);
	itoa(j, str2, 10);
	revolve(str1, temp, 4, 5);
	printf("%d\n", strcmp(temp, str2));
#endif

	return 0;
}

//rotate right shift by loca 'bit'.
void revolve(const char *st, char *nst, int loca, int len)
{
	int i, j;

	if(loca == 0)
	{
		strcpy(nst, st);
	}

	j = 0;
	for(i = len - loca; i < len; i++)
	{
		*(nst + j) = *(st + i);
		j++;
	}
	//j = loca by now.
	for(i = 0; i < len - loca; i++)
	{
		*(nst + j) = *(st + i);
		j++;
	}

	*(nst + len) = '\0';

#if MYDEBUG
	printf("%s\n%s\n", st, nst);
#endif

}