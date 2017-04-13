#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[1000003];
int index[1000000];

void Print(int num, FILE* file, int a)
{
		fprintf(file, "Case #%d: %d\n", num+1, a);

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
	int TotalCount, i, j, len, size, tempint, X, Y;
	long result;
	FILE* input, *output;
	input = fopen("A-small-attempt0.in", "r");
	output = fopen("A-small-attempt0.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		size = 0;
		memset(temp, 0, 1000003);
		fscanf(input, "%s %d", temp, &size);
		len = strlen(temp);
		/*
		for(j = len-1; temp[j] != ' '; j--)
		{
			size += (temp[j] - 48) * power10(len-1-j);
			temp[j] = NULL;
		}
		temp[j] = NULL;
		len = strlen(temp);
		*/
		tempint = 0;
		for(j = len-1; j >= 0; j--)
		{
			if(temp[j] == 'a' || temp[j] == 'e' || temp[j] == 'i' || temp[j] == 'o' || temp[j] == 'u')
				tempint = 0;
			else
				tempint++;
			index[j] = tempint;
		}
		X = 0; Y = len;
		result = 0;
		for(j = 0; j < len; j++)
		{
			if(index[j] >= size)
			{
				X = j - X + 1;
				Y = len - j - size + 1;
				result += X*Y;
				X = j+1;
			}
		}
		Print(i, output, result);
	}
	fclose(input);
	fclose(output);
	return 0;
}
