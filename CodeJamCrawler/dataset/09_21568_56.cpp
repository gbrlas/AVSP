#include <stdio.h>
#include <string.h>
#include <memory.h>

#define NMAX 30

int T;

int		leng;
char	data[NMAX];

int		flag[NMAX];
int		check[NMAX];

char	sort[NMAX];

char	ans[NMAX];
int		check2[NMAX];

int		sign;

void init()
{
	leng = 0;
	memset(data, 0, sizeof(data));
	memset(flag, 0, sizeof(flag));
	memset(check, 0, sizeof(check));
	memset(check2, 0, sizeof(check2));
	memset(sort, 0, sizeof(sort));
	memset(ans, 0, sizeof(ans));
}

void call(int D)
{
	if(D == leng)
	{
		if(sign == 1)
		{
			sign = 0;
		}
		else
		{
			sign = 2;
		}
		return;
	}

	int i, j;
	
	for(i = 0; i < leng; i ++)
	{
		if(sign == 1)
		{
			i = flag[D];
		}

		if(check2[i])
			continue;

		check2[i] = 1;
		ans[D] = sort[i];

		call(D + 1);

		check2[i] = 0;

		if(sign == 2)
			return;

		while(sort[i] == sort[i+1])	i++;
	}
}

void process()
{
	int i, j;
	int temp;
	
	for(i = 0; i < leng; i ++)
		sort[i] = data[i];

	for(i = 0; i < leng; i ++)
	{
		for(j = i + 1; j < leng; j ++)
		{
			if(sort[j] < sort[i])
			{
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}

	for(i = 0; i < leng; i ++)
	{
		for(j = 0; j < leng; j ++)
		{
			if(check[j])
				continue;
			if(data[i] == sort[j])
			{
				check[j] = 1;
				flag[i] = j;
				break;
			}
		}
	}

	sign = 1;

	call(0);

	if(!strcmp(data, ans))
	{
		for(i = 0; i < leng; i ++)
		{
			ans[i] = sort[i];
		}
		for(i = leng; i >= 2; i --)
		{
			ans[i] = ans[i - 1];
		}
		ans[1] = '0';
		leng ++;
	}

	int min, ff;

	if(ans[0] == '0')
	{
		min = 9999;
		for(i = 0; i < leng; i ++)
		{
			if(ans[i] < min && ans[i] != '0')
			{
				min = ans[i];
				ff = i;
			}
		}
		for(i = ff; i > 0; i --)
		{
			ans[i] = ans[i - 1];
		}
		ans[0] = min;
	}
}

int main()
{
	int i, j;

	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);
	
	for(i = 0; i < T; i ++)
	{
		init();

		fscanf(in, "%s", &data);
		leng = strlen(data);

		process();

		fprintf(out, "Case #%d: %s\n", i+1, ans);
	}

	fclose(in);
	fclose(out);
	return 0;
}
