#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[4][5];
char xwin[100] = "X won";
char owin[100] = "O won";
char draw[100] = "Draw";
char notfinish[100] = "Game has not completed";

void main()
{
	freopen("c:\\a_input_large.in", "r", stdin);
	freopen("c:\\a_output_large.txt", "w", stdout);

	int count = 0;

	scanf("%d", &count);


	for(int i = 0; i<count; i++)
	{
		// ют╥б
		for(int j =0 ; j < 4; j++)
		{
			scanf("%s", data[j]);
		}
		int dummy;
		scanf("%d", &dummy);

		char result[100];
		int oo = 0;
		int xx = 0;
		int dot = 0;
		for(int x=0; x < 4; x++)
		{
			oo = 0;
			xx = 0;
			for(int y=0; y<4; y++)
			{
				if(data[y][x] == 'X')
					xx++;
				else if(data[y][x] == 'O')
					oo++;
				else if(data[y][x] == 'T')
				{
					oo++;
					xx++;
				}
				else
					dot++;
			}
			if(oo==4 || xx==4)
					break;
			
		}
		
		
		if(oo!=4 && xx!=4)
		{
			

			for(int y=0; y < 4; y++)
			{
				oo = 0;
				xx = 0;
				for(int x=0; x<4; x++)
				{
					if(data[y][x] == 'X')
						xx++;
					else if(data[y][x] == 'O')
						oo++;
					else if(data[y][x] == 'T')
					{
						oo++;
						xx++;
					}
					else
						dot++;
				}
				if(oo==4 || xx==4)
					break;
			}
		}

		if(oo!=4 && xx!=4)
		{
			oo = 0;
			xx = 0;
			for(int x=0; x<4; x++)
			{
				if(data[x][x] == 'X')
					xx++;
				else if(data[x][x] == 'O')
					oo++;
				else if(data[x][x] == 'T')
				{
					oo++;
					xx++;
				}
				else
					dot++;
			}

		}
		if(oo!=4 && xx!=4)
		{
			oo = 0;
			xx = 0;
			for(int x=0; x<4; x++)
			{
				if(data[3-x][x] == 'X')
					xx++;
				else if(data[3-x][x] == 'O')
					oo++;
				else if(data[3-x][x] == 'T')
				{
					oo++;
					xx++;
				}
				else
					dot++;
			}

		}

		if(oo==4)
			strcpy(result, owin);
		else if(xx==4)
			strcpy(result, xwin);
		else if(dot >0)
			strcpy(result, notfinish);
		else
			strcpy(result, draw);

		//printf("%s\n%s\n%s\n%s\n", data[0], data[1],data[2],data[3]);
		printf("Case #%d: %s\n", i+1, result);

	}






}