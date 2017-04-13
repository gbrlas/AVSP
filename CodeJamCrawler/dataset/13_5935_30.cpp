/*
 * test.c
 *
 *  Created on: Apr 13, 2013
 *      Author: vyshakhp
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *output;
int X,O,C,Y,Z;

void tester(int , char[4][4]);

int main()
{
	FILE *input;
	int tot=0;
	input=fopen("input.txt","r");
	output=fopen("output.txt","w");
	char string[10];

	char mat[4][4];

	fgets(string,10,input);
	tot= atoi(string);

	int count,row, col;
	char c;
	for(count=0; count<tot; count++)
	{
		row=0;
		while(row<4)
		{
			col=0;
			while((c=fgetc(input))!='\n')
			{
					mat[row][col]=c;
					col++;
			}
			row++;
		}
		C=0;
		tester(count+1,mat);
		//printf("\n");
		fgetc(input);
	}
	fclose(input);
	fclose(output);
	return 0;
}

	void tester(int testcase, char mat[4][4])
	{
		int i,j;
		for(i=0;i<4;i++)
		{
			X=0;O=0;Y=0;Z=0;
			for(j=0;j<4;j++)
			{
				switch(mat[i][j])
				{
					case 'X': X++; break;
					case 'O': O++; break;
					case '.': C++; break;
					case 'T': X++;O++;break;
				}

				switch(mat[j][i])
				{
					case 'X': Y++; break;
					case 'O': Z++; break;
					case '.': C++; break;
					case 'T': Y++;Z++;break;
				}
				//printf("%c",mat[i][j]);
			}
			//printf("\n");
			if(X==4||Y==4)
			{
				fprintf(output,"Case #%d: %s", testcase, "X won\n");
				return;
			}
			else if(O==4||Z==4)
			{
				fprintf(output,"Case #%d: %s", testcase, "O won\n");
				return;
			}
		}

		X=0;O=0;Y=0;Z=0;
		for(j=0,i=3;j<4;j++,i--)
		{
			switch(mat[j][j])
			{
				case 'X': X++; break;
				case 'O': O++; break;
				case '.': C++; break;
				case 'T': X++;O++;break;
			}

			switch(mat[i][j])
			{
				case 'X': Y++; break;
				case 'O': Z++; break;
				case '.': C++; break;
				case 'T': Y++;Z++;break;
			}
			//printf("%c",mat[i][j]);
		}
		//printf("\n");
		if(X==4||Y==4)
		{
			fprintf(output,"Case #%d: %s", testcase, "X won\n");
			return;
		}
		else if(O==4||Z==4)
		{
			fprintf(output,"Case #%d: %s", testcase, "O won\n");
			return;
		}


		if(C>0)
			fprintf(output,"Case #%d: %s", testcase, "Game has not completed\n");
		else
			fprintf(output,"Case #%d: %s", testcase, "Draw\n");
	}
