#include <stdio.h>

void solveTestcase();

int main()
{
	int T;
	int i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveTestcase();
	}
	
	return 0;
}

void solveTestcase()
{
	int pOrange = 1, pBlue = 1;
	char colors[100];
	int iOrange = 0, iBlue = 0;
	int oranges[100], blues[100];
	int i = 0;
	int N;
	int k;
	int t = 0;
	
	scanf("%d", &N);
	
	for (i=0; i<N; i++)
	{
		scanf(" %c %d", &colors[i], &k);
		if (colors[i] == 'O')
		{
			oranges[iOrange] = k;
			iOrange++;
		}
		else
		{
			blues[iBlue] = k;
			iBlue++;
		}
	}
	
	i = 0;
	iOrange = 0;
	iBlue = 0;
	
	while (N > 0)
	{
		if (colors[i] == 'O')
		{
			if (pOrange == oranges[iOrange])
			{
				iOrange++;
				i++;
				N--;
			}
			else if (pOrange < oranges[iOrange])
			{
				pOrange++;
			}
			else
			{
				pOrange--;
			}
			if (pBlue < blues[iBlue])
			{
				pBlue++;
			}
			else if (pBlue > blues[iBlue])
			{
				pBlue--;
			}
		}
		else
		{
			if (pBlue == blues[iBlue])
			{
				iBlue++;
				i++;
				N--;
			}
			else if (pBlue < blues[iBlue])
			{
				pBlue++;
			}
			else
			{
				pBlue--;
			}
			if (pOrange < oranges[iOrange])
			{
				pOrange++;
			}
			else if (pOrange > oranges[iOrange])
			{
				pOrange--;
			}
		}
		t++;
	}
	
	printf("%d\n", t);
}
