#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Print(int num, FILE* file, int a)
{
	switch(a)
	{
	case 0:
		fprintf(file, "Case #%d: X won\n", num+1);
		break;
	case 1:
		fprintf(file, "Case #%d: O won\n", num+1);
		break;
	case 2:
		fprintf(file, "Case #%d: Draw\n", num+1);
		break;
	case 3:
		fprintf(file, "Case #%d: Game has not completed\n", num+1);
		break;
	}
}

int main()
{
	int TotalCount, i, j, k, q1, q2;
	char temp[5];
	int OCorrect[10], XCorrect[10], sum;
	FILE* input, *output;
	input = fopen("A-small-attempt1.in", "r");
	output = fopen("A-small-attempt1.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		memset(OCorrect, 0, sizeof(int) * 10);
		memset(XCorrect, 0, sizeof(int) * 10);
		sum = 0;
		q1 = 0; q2 = 3;
		for(j = 0; j < 4; j++)
		{
			fscanf(input, "%s", temp);
			for(k = 0; k < 4; k++)
			{
				if(temp[k] == 'T')
				{
					OCorrect[5+j]++;
					XCorrect[5+j]++;
					OCorrect[k]++;
					XCorrect[k]++;
					if(k == q1)
					{
						OCorrect[4]++;
						XCorrect[5]++;
					}
					else if(k == q2)
					{
						OCorrect[9]++;
						XCorrect[9]++;
					}
					sum++;
				}
				else if(temp[k] == 'X')
				{
					XCorrect[5+j]++;
					XCorrect[k]++;
					if(k == q1)
						XCorrect[4]++;
					else if(k == q2)
						XCorrect[9]++;
					sum++;
				}
				else if(temp[k] == 'O')
				{
					OCorrect[5+j]++;
					OCorrect[k]++;
					if(k == q1)
						OCorrect[4]++;
					else if(k == q2)
						OCorrect[9]++;
					sum++;
				}
			}
			q1++;
			q2--;
		}
		for(j = 0; j < 10; j++)
		{
			if(OCorrect[j] == 4)
			{
				Print(i, output, 1);
				break;
			}
			else if(XCorrect[j] == 4)
			{
				Print(i, output, 0);
				break;
			}
		}
		if(j == 10)
		{
			if(sum == 16)
				Print(i, output, 2);
			else
				Print(i, output, 3);
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}
