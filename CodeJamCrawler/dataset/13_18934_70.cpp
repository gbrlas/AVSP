#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int solve()
{
	int i, i2;
	int flag = 0;
	int s[4][5], s2[4][5];

	
	for(i = 0; i < 4; i++)
	{
		for(i2 = 0; i2 < 5; i2++)
		{
			s[i][i2] = fgetc(stdin);
//			printf("%d ", s[i][i2]);
			if(s[i][i2] == 'T')
			{
				s[i][i2] = 'X';
				s2[i][i2] = 'O';
			}else{
				s2[i][i2] = s[i][i2];
			}
			if(s[i][i2] == '.')
			{
				flag = 1;
			}
		}
	}

	fgetc(stdin);


	//X‚ªŸ‚¿‚©‚Ç‚¤‚©
	for(i = 0; i < 4; i++)
	{
		for(i2 = 0; i2 < 4; i2++)
		{
			if(s[i][i2] != 'X')
			{
				break;
			}
		}
		if(i2 == 4)
		{
			return 0;
		}
	}

	for(i = 0; i < 4; i++)
	{
		for(i2 = 0; i2 < 4; i2++)
		{
			if(s[i2][i] != 'X')
			{
				break;
			}
		}
		if(i2 == 4)
		{
			return 0;
		}
	}

	for(i = 0; i < 4; i++)
	{
		if(s[i][i] != 'X')
		{
			break;
		}
	}
	if(i == 4)
	{
		return 0;
	}
	for(i = 0; i < 4; i++)
	{
		if(s[i][3- i] != 'X')
		{
			break;
		}
	}
	if(i == 4)
	{
		return 0;
	}
	//O‚ªŸ‚¿‚©‚Ç‚¤‚©
	for(i = 0; i < 4; i++)
	{
		for(i2 = 0; i2 < 4; i2++)
		{
			if(s2[i][i2] != 'O')
			{
				break;
			}
		}
		if(i2 == 4)
		{
			return 1;
		}
	}

	for(i = 0; i < 4; i++)
	{
		for(i2 = 0; i2 < 4; i2++)
		{
			if(s2[i2][i] != 'O')
			{
				break;
			}
		}
		if(i2 == 4)
		{
			return 1;
		}
	}

	for(i = 0; i < 4; i++)
	{
		if(s2[i][i] != 'O')
		{
			break;
		}
	}
	if(i == 4)
	{
		return 1;
	}
	for(i = 0; i < 4; i++)
	{
		if(s2[i][3- i] != 'O')
		{
			break;
		}
	}
	if(i == 4)
	{
		return 1;
	}
	//‚ ‚¢‚±‚©yet‚©
	if(flag == 0)
	{
		return 2;
	}else{
		return 3;
	}

	return -1;
}



void main()
{
	int i;
	int m;
	char s[10];

//	scanf("%d", &m);
//	fflush(stdin);//ƒSƒ~
	fgets(s, 10, stdin);
	m = atoi(s);

	for(i = 0; i < m; i++)
	{
		switch(solve())
		{
			case 0:
				printf("Case #%d: X won\n", (i + 1));
				break;
			case 1:
				printf("Case #%d: O won\n", (i + 1));
				break;
			case 2:
				printf("Case #%d: Draw\n", (i + 1));
				break;
			case 3:
				printf("Case #%d: Game has not completed\n", (i + 1));
				break;
			default:
				printf("‚È‚ñ‚©‚¨‚©‚µ‚­‚ËH\n");
				break;
		}
	}
}