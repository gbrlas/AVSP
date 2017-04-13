#include <stdio.h>
#include <stdlib.h>



int find(int** matrix1, int answer1, int** matrix2, int answer2)
{
	int* row1 = matrix1[answer1];
	int* row2 = matrix2[answer2];
	int result = 0;
	for(int i=0;i<4;++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			
			if(row1[i]==row2[j])
			{
				if (result!=0)
				{
					return -1;
				}
				result = row1[i];
				break;
			}
		}
	}
	return result;
}

int main()
{
	int size = 0;
	scanf("%d",&size);
	for(int tmp=1;tmp<=size;tmp++)
	{
		int answer1;
		scanf("%d",&answer1);

		int ** matrix1 = malloc(4*sizeof(int *));
		for (int i = 0; i < 4; ++i)
		{
			matrix1[i] = malloc(4*sizeof(int));
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d",&(matrix1[i][j]));


			}
		}
		int answer2;
		scanf("%d",&answer2);
		int ** matrix2 = malloc(4*sizeof(int *));
		for (int i = 0; i < 4; ++i)
		{
			matrix2[i] = malloc(4*sizeof(int));
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d",&(matrix2[i][j]));

			}
		}
		int result = find(matrix1,answer1-1,matrix2,answer2-1);

		if (result==0)
		{
			printf("Case #%d: Volunteer cheated!\n", tmp);
		}
		else if (result==-1)
		{
			printf("Case #%d: Bad magician!\n", tmp);
		}
		else
		{
			printf("Case #%d: %d\n", tmp,result);
		}
		for(int i=0;i<4;i++)
		{
			free(matrix1[i]);
			free(matrix2[i]);
		}
		free(matrix1);
		free(matrix2);
	}
	return 0;
}