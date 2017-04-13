#include <stdio.h>
#include <string.h>

void read_dict(char Dict[5001][16], int D)
{
	int i;
	for (i = 0; i < D; i++) 
	{
		scanf("%s", Dict[i]);
	}
}

void copy_pattern(int pattern[5001], int new_pattern[5001], int count)
{
	int i;
	for (i = 0; i < count; i++) {
		pattern[i] = new_pattern[i];
	}
}

int main () 
{
	int i, j, k, x, nx, count;
	int L, D, N;
	char Dict[5001][16],testcase[260];
	int pattern[5001], new_pattern[5001];
	
	scanf("%d %d %d", &L, &D, &N);
	
	read_dict(Dict, D);
	
	for (i = 0; i < N; i++) 
	{
		scanf("%s", testcase);
		count = D;
		for (x=0; x<D; x++) {
			pattern[x] = x;
		}
		for (j = 0, k = 0; j < L; j++, k++) 
		{
			
			if (testcase[k] == '(') 
			{
				k++;
				nx = 0;
				while (testcase[k] != ')') 
				{
					for (x = 0; x < count; x++) 
					{
						//printf("Pattern[x]:%d Dict[pattern[x]][j]:%c testcase[k]:%c\n", pattern[x], Dict[pattern[x]][j], testcase[k]);
						if (Dict[pattern[x]][j] == testcase[k]) 
						{
							new_pattern[nx++] = pattern[x];
						}						
					}
					k++;
				}
				copy_pattern(pattern, new_pattern, nx);
				count = nx;
				//printf("\n");
			}
			else 
			{
				for (x = 0, nx=0; x < count; x++) 
				{
					//printf("Pattern[x]:%d Dict[pattern[x]][j]:%c testcase[k]:%c\n", pattern[x], Dict[pattern[x]][j], testcase[k]);
					if (Dict[pattern[x]][j] == testcase[k]) 
					{
						pattern[nx++] = pattern[x];
					}
				}
				count = nx;
			}

		}
		
		printf("Case #%d: %d\n", i+1, count);
	}
}