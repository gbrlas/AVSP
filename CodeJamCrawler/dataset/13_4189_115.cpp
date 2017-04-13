#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Print(int num, FILE* file, int a)
{
	fprintf(file, "Case #%d: %d\n", num+1, a);
}

int IsPalindrome(char* number)
{
	int Is = 1, i, len;
	len = strlen(number);
	for(i = 0; i < (len / 2); i++)
	{
		if(number[i] != number[len - 1 - i])
		{
			Is = 0;
			break;
		}
	}
	return Is;
}

int IsSqrt(unsigned long k)
{
	unsigned long k2;
	long double k1;
	char temp[15];
	memset(temp, 0, 15);
	k1 = (long double)k;
	k2 = (unsigned long)sqrtl(k1);
	if((sqrtl(k1) - k2) == 0)
	{
		itoa(k2, temp, 10);
		if(IsPalindrome(temp))
		{
			return 1;
		}
	}
	return 0;
}

int power(int len, int powernum)
{
	int i, p = 1;
	if(len == 0)
		return 1;
	for(i = 0; i < len; i++)
	{
		p *= powernum;
	}
	return p;
}

int main()
{
	int TotalCount, i, j, len;
	int count;
	char tempA[4], tempB[4];
	int tempaa, tempbb;
	int arr[5] = {1, 4, 9, 121, 484};
	FILE* input, *output;
	input = fopen("C-small-attempt2.in", "r");
	output = fopen("C-small-attempt2.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		count = 0;
		fscanf(input, "%d %d", &tempaa, &tempbb);
		for(j = 0; j < 5; j++)
		{
			if(tempaa<= arr[j] && tempbb >= arr[j])
			{
				count++;
			}
		}

		Print(i, output, count);
	}
	fclose(input);
	fclose(output);

	return 0;
}
