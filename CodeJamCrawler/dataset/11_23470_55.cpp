#include <stdio.h>
#include <stdlib.h>
#define MAXN 100


int action_count(int *botA, int comA, int *botB, int comB, char *cmd, int ncom)
{
	int turn = 0;
	int posA = 1, posB = 1;
	int act = 0, bct = 0;
	int i;
	int aturn, bturn;
	
	i = 0;
	while(i < ncom)
	{
		aturn = 0;
		bturn = 0;
		if(cmd[i] == 'O')
		{
			if(botA[act] == posA)
			{
				i++;
				act++;
				aturn = 1;
			}
		}
		else
		{
			if(botB[bct] == posB)
			{
				i++;
				bct++;
				bturn = 1;
			}
		}
		
		if(act < comA && aturn == 0)
		{
			if(botA[act] > posA)
				posA++;
			else if(botA[act] < posA)
				posA--;
		}
		if(bct < comB && bturn == 0)
		{
			
			if(botB[bct] > posB)
				posB++;
			else if(botB[bct] < posB)
				posB--;
			
		}
		turn++;
	}
	return turn;
}

int main(int argc, char *argv[])
{
	int N, T, i, j, oc, bc;
	char bot;
	int button;
	int O[MAXN], B[MAXN];
	char cmd[MAXN];
	
	fscanf(stdin, "%i", &T);
	for(i=0; i < T; i++)
	{
		fscanf(stdin, "%i", &N);
		oc = 0, bc = 0;
		for(j=0; j < N; j++)
		{
			fscanf(stdin, " %c %i", &bot, &button);
			if(bot == 'O')
			{
				O[oc] = button;
				oc++;
			}
			else
			{
				B[bc] = button;
				bc++;
			}
			cmd[j] = bot;
		}
		printf("Case #%i: %i\n", i+1, action_count(O, oc, B, bc, cmd, N));
	}
	return 0;
}
