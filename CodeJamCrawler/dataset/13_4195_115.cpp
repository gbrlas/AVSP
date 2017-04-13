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

int CountFrom(int len)
{
	int result;
	if(len % 2 == 0)
	{
		result = power((len/2)-1,2) + 1; 
	}
	else
	{
		result = power(len/2,2) + len/2 + 2;
	}
	return result;
}

int main()
{
	int TotalCount, j, index;
	char temp[15];
	long double k1;
	int count = 0;
	unsigned long long k, k2, i, tempk;
	unsigned long long tempA, tempB;
	unsigned long long arr[39];
	FILE* input, *output;
	k = 100;
	arr[0] = 1; arr[1] = 4; arr[2] = 9; arr[3] = 121; arr[4] = 484;
	index = 5;
	while(k < 100000000)
	{
		for(i = k; i < 3*k; i++)
		{
			if(i%10 == 2 || i%10 == 1)
			{
				k2 = pow((long double)i, 2);
				tempk = k2;
				memset(temp, 0, 15);
				j = 0;
				while(tempk > 0)
				{
					temp[j] = tempk % 10 + 48;
					tempk /= 10;
					j++;
				}
				if(IsPalindrome(temp))
				{
					memset(temp, 0, 15);
					j = 0;
					tempk = i;
					while(tempk > 0)
					{
						temp[j] = tempk % 10 + 48;
						tempk /= 10;
						j++;
					}
					if(IsPalindrome(temp))
					{
						arr[index] = k2;
						index++;
					}
				}
			}
		}
		k *= 10;
	}
	input = fopen("C-large-1.in", "r");
	output = fopen("C-large-1.out", "w");
	fscanf(input, "%d", &TotalCount);
	for(i = 0; i < TotalCount; i++)
	{
		count = 0;
		fscanf(input, "%I64u %I64u\n", &tempA, &tempB);
		for(j = 0; j < 39; j++)
		{
			if(tempA <= arr[j] && tempB >= arr[j])
				count++;
		}
		Print(i, output, count);
	}
	fclose(input);
	fclose(output);
	return 0;
}
