#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[501];
int index[1000000];

void Print(int num, FILE* file, char* a)
{
	fprintf(file, "Case #%d: %s\n", num+1, a);
}

int power10(int size)
{
	int i = 0, total = 1;
	if(size == 0)
		return 1;
	for(i = 1; i < size; i++)
	{
		total *= 10;
	}
	return total;
}

int main()
{
	int TotalCount, i, j, index, X, Y;
	long result;
	char a[2];
	FILE* input, *output;
	input = fopen("B-small-attempt1.in", "r");
	output = fopen("B-small-attempt1.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		index = 0;
		memset(temp, 0, 501);
		fscanf(input, "%d %d", &X, &Y);
		if(X > 0)
		{
			a[0] = 'W';
			a[1] = 'E';
		}
		else
		{
			a[0] = 'E';
			a[1] = 'W';
		}
		if(X < 0)
			X = -X;
		for(j = 0; j < X; j++)
		{
			memcpy(&temp[index], a, 2);
			index += 2;
		}
		if(Y > 0)
		{
			a[0] = 'S';
			a[1] = 'N';
		}
		else
		{
			a[0] = 'N';
			a[1] = 'S';
		}
		if(Y < 0)
			Y = -Y;
		for(j = 0; j < Y; j++)
		{
			memcpy(&temp[index], a, 2);
			index += 2;
		}
		Print(i, output, temp);
	}
	fclose(input);
	fclose(output);
	return 0;
}
