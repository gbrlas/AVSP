#include <stdio.h>

#define MAX 10

int T;
char map[MAX][MAX];

int isCompleted()
{
	// Check whether game complete or not
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (map[i][j] == '.')
			return 0;
	return 1;
}

int won(char c)
{
	int dir[][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
	for (int d = 0; d < 4; d++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int count = 0;
				for (int k = 0; k < 4; k++)
				{
					int y = i + k*dir[d][0];
					int x = j + k*dir[d][1];
				
					if (0 <= y && y < 4 && 0 <= x && x < 4)
					{
						if (map[y][x] == c || map[y][x] == 'T')
							count += 1;
					}
				}
				if (count == 4)
				{
					return 1;
				}
			}
		}	
	}		
	return 0;			
}

int main()
{
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	// Input 
	scanf ("%d\n", &T);
	
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf ("%s", map[i]);			
		}
	//	for (int i = 0; i < 4; i++)
	//		printf ("%s\n", map[i]);
//		if (isCompleted() == 0)
//		{
			//printf ("x?=%d o?=%d com?=%d\n", won('X'), won('O'), isCompleted());
//		}	
		
		int x_won = won('X');
		int o_won = won('O');
		int complete = isCompleted();
		printf ("Case #%d: ", (t+1));
		if (x_won && o_won)
			printf ("Draw");
		else if (x_won)
			printf ("X won");
		else if (o_won)
			printf ("O won");
		else if (complete)
			printf ("Draw");
		else
			printf ("Game has not completed");
		printf ("\n");
	}
	return 0;
}