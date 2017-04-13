#include "stdio.h"

int nTests, nFills;
char arr[4][4];

enum{
	X_won,
	O_won,
	Draw,
	Game_Inc
};

const char * const res[] = {
"X won",
"O won",
"Draw",
"Game has not completed"
};

int solve(void)
{
	int i,opr, bFail=0;

	for(i=0 ; i<4 ; ++i)
	{
		int val = *(int*)(arr[i]);
		if(val)
		{
			char * ptr = arr[i];
			opr = ptr[0] & ptr[1] & ptr[2] & ptr[3];
			if(opr)
				goto Label_Won; 
		}
		else
		{
			bFail=1;
		}
	}
	
	if(bFail)
		return Game_Inc;

	opr = arr[0][0] & arr[1][1] & arr[2][2] & arr[3][3];
	if(opr)
		goto Label_Won; 

	opr = arr[0][3] & arr[1][2] & arr[2][1] & arr[3][0];
	if(opr)
		goto Label_Won; 

	for(i=0 ; i<4 ; ++i)
	{
		opr = arr[0][i] & arr[1][i] & arr[2][i] & arr[3][i];
		if(opr)
			goto Label_Won; 
	}

	if(nFills >= 16)
		return Draw;
		
	return Game_Inc;

Label_Won:
	if(opr&4)	return O_won;
	return X_won;
}

int main(void)
{
	int cTest,i,j;

	scanf("%d\n", &nTests);
	
	for(cTest=1 ; cTest<=nTests ; ++cTest)
	{
		nFills = 0;
		for(i=0 ; i<4 ; ++i)
		{
			char* ptr = arr[i];
			scanf("%c%c%c%c\n", &ptr[0], &ptr[1], &ptr[2], &ptr[3]);
			//printf("%c%c%c%c\n", ptr[0], ptr[1], ptr[2], ptr[3]);
			for(j=0 ; j<4 ; ++j)
			{
				if(ptr[j]=='.')
				{
					ptr[j] = 0;
				}
				else
				{
					ptr[j] &= 0x14;
					nFills++;
				}
				//printf("%d ", ptr[j]);
				/*
				switch(ch)
				{
					case 'X':	ch = 1;	nFills++; break;
					case 'O':	ch = 2;	nFills++; break;
					case 'T':	ch = 3;	nFills++; break;
					case '.':	ch = 0; break;
				}
				arr[i][j] = ch;*/
			}
			//printf("\n");		
		}
		
		i=solve();
		
		printf("Case #%d: %s\n", cTest, res[i]);
	}
	
	return 0;
}


/*

. 0010 1110
X 0101 1000
O 0100 1111
T 0101 0100

*/