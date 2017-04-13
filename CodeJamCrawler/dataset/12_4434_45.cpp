#include <stdlib.h>
#include <stdio.h>

#define MYDEBUG			1

int T;
int score[102][102];
int N[102], S[102], p[102], Mnum[102];	//Mnum is result.

int main(void)
{
	int i, j;
	int NeedSur;
	FILE *fp;

	//output file
	fp = fopen("result.txt", "w");

	freopen("B-large.in", "r", stdin);
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("a.txt", "r", stdin);

	scanf("%d", &T);

	for(i = 0; i < T; i++)
	{
		scanf("%d", &N[i]);	//num of googlers
		scanf("%d", &S[i]);	//num of surprise
		scanf("%d", &p[i]);	//best result threshold

		Mnum[i] = 0;
		NeedSur = 0;	//number that needs surprise

		for(j = 0; j < N[i]; j++)
		{
			scanf("%d", &score[i][j]);	

			if(p[i] >= 2)
			{
				if(score[i][j] >= 3 * p[i] - 2)	//8+7+7, min w/o surprise, i.e. 3p - 2
				{
					Mnum[i]++;
				}
				else if(score[i][j] <= 3 * p[i] - 5)				//7+7+5, max even w surprise--still impossible
				{
					continue;
				}
				else	//20 or 21, i.e. 3p - 4 or 3p - 3
				{
					NeedSur++;	
				}
			}
			else if(p[i] == 1)	
			{
				if(score[i][j] >= 1)	//3*1-2, min w/o surprise, i.e. 3p - 2
				{
					Mnum[i]++;
				}		
			}
			else	//p[i] == 0
			{
				Mnum[i]++;
			}
		}

		if(NeedSur <= S[i])
		{
			Mnum[i] += NeedSur;
		}
		else
		{
			Mnum[i] += S[i];
		}

		fprintf(fp, "Case #%d: %d\n", i + 1, Mnum[i]);

	}


	fclose(fp);
	fclose(stdin);
	

	return 0;
}