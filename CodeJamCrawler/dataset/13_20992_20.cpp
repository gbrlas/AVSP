#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n, i, j, k, flag = 0, dotflag = 0;
	char str[5][5];
	scanf("%d\n", &n);
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < 4; j++)
			scanf("%s\n",str[j]);
		flag = dotflag = 0;
		//for(j = 0; j < 4; j++)
		//	printf("%s\n",str[j]);
		for(j = 0; j < 4; j++)
			for(k = 0; k < 4; k++)
				if(str[j][k] == '.')
					dotflag = 1;
		for(k = 0; k < 4; k++)
		{
			for(j = 1; j < 4; j++)
				if( (str[k][j] != str[k][j-1] && str[k][j] != 'T') || str[k][j] == '.')
					break;
			if(j == 4)
			{
				printf("Case #%d: %c won\n", i, (str[k][0] != 'T')?str[k][0]:str[k][1]);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			for(k = 0; k < 4; k++)
			{
				for(j = 1; j < 4; j++)
					if((str[j][k] != str[j-1][k] && str[j][k] != 'T') || str[j][k] == '.')
						break;
				if(j == 4)
				{
					printf("Case #%d: %c won\n", i, (str[0][k] != 'T')?str[0][k]:str[1][k]);
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0)
		{
			for(k = 1; k < 4; k++)
				if((str[k][k] != str[k-1][k-1] && str[k][k] != 'T') || str[k][k] == '.')
					break;
			if(k == 4)
			{
				printf("Case #%d: %c won\n", i, (str[0][0] != 'T')?str[0][0]:str[1][1]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			for(k = 1, j = 2; k < 4; k++, j--)
				if((str[k][j] != str[k-1][j+1] && str[k][j] != 'T') || str[k][j] == '.')
					break;
			if(k == 4)
			{
				printf("Case #%d: %c won\n", i, (str[0][3] != 'T')?str[0][3]:str[1][2]);
				flag = 1;
			}
		}
		if(flag == 0 && dotflag == 0)
			printf("Case #%d: Draw\n", i);
		else if(flag == 0 && dotflag == 1)
			printf("Case #%d: Game has not completed\n", i);
		scanf("\n");
	}
	return 0;
}
