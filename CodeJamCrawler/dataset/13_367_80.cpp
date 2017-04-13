#include <stdio.h>

#define MAX_SIZE 4
#define X_PLAYER 'X'
#define O_PLAYER 'O'
#define SPECIAL_CHAR 'T'
#define EMPTY '.'

enum GAME_STATE {
	X_WON,
	O_WON,
	DRAW,
	NOT_COMPLETE
};

int noEmptyCell(char grid[][MAX_SIZE + 1])
{
	int row, col;

	for(row = 0; row < MAX_SIZE; row++)
		for(col = 0; col < MAX_SIZE; col++)
			if(grid[row][col] == EMPTY)
				return 0;

	return 1;
}

int checkRow(char grid[][MAX_SIZE + 1], char playerChar)
{
	int numSpecial, numPlayerChar, row, col;

	for(row = 0; row < MAX_SIZE; row++)
	{
		numSpecial = 0;
		numPlayerChar = 0;

		for(col = 0; col < MAX_SIZE; col++)
		{
			if(grid[row][col] == playerChar)
				numPlayerChar++;
			if(grid[row][col] == SPECIAL_CHAR)
				numSpecial++;
		}

		if(numPlayerChar == MAX_SIZE || (numPlayerChar == (MAX_SIZE - 1) && numSpecial == 1))
			return 1;
	}

	return 0;
}

int checkCol(char grid[][MAX_SIZE + 1], char playerChar)
{
	int numSpecial, numPlayerChar, row, col;

	for(col = 0; col < MAX_SIZE; col++)
	{
		numSpecial = 0;
		numPlayerChar = 0;

		for(row = 0; row < MAX_SIZE; row++)
		{
			if(grid[row][col] == playerChar)
				numPlayerChar++;
			if(grid[row][col] == SPECIAL_CHAR)
				numSpecial++;
		}

		if(numPlayerChar == MAX_SIZE || (numPlayerChar == (MAX_SIZE - 1) && numSpecial == 1))
			return 1;
	}

	return 0;
}

int checkDiagonal(char grid[][MAX_SIZE + 1], char playerChar)
{
	int numSpecial, numPlayerChar, row, col;

	/* Left diagonal */
	numSpecial = 0;
	numPlayerChar = 0;
	for(row = 0; row < MAX_SIZE; row++)
	{
		if(grid[row][row] == playerChar)
			numPlayerChar++;
		if(grid[row][row] == SPECIAL_CHAR)
			numSpecial++;
	} 
	if(numPlayerChar == MAX_SIZE || (numPlayerChar == (MAX_SIZE - 1) && numSpecial == 1))
		return 1;

	/* Right diagonal */
	numSpecial = 0;
	numPlayerChar = 0;
	for(row = 0; row < MAX_SIZE; row++)
	{
		col = MAX_SIZE - row - 1;
		
		if(grid[row][col] == playerChar)
			numPlayerChar++;
		if(grid[row][col] == SPECIAL_CHAR)
			numSpecial++;
	}
	if(numPlayerChar == MAX_SIZE || (numPlayerChar == (MAX_SIZE - 1) && numSpecial == 1))
		return 1;

	return 0;
}
int doesPlayerWin(char grid[][MAX_SIZE + 1], char playerChar)
{
	if(checkRow(grid, playerChar) || checkCol(grid, playerChar) || 
		checkDiagonal(grid, playerChar))
		return 1;

	return 0;
}
enum GAME_STATE getGameState(char grid[][MAX_SIZE + 1])
{
	if(doesPlayerWin(grid, X_PLAYER))
		return X_WON;

	if(doesPlayerWin(grid, O_PLAYER))
		return O_WON;

	if(noEmptyCell(grid))
		return DRAW;

	return NOT_COMPLETE;
}

int main(void)
{
	int T, i, caseId;
	char grid[MAX_SIZE][MAX_SIZE + 1], trash[MAX_SIZE + 1];
	enum GAME_STATE gameState;

	freopen("in.txt", "r", stdin);
	freopen("out.out", "w", stdout);

	scanf("%d", &T);
	gets(trash);
	caseId = 1;
	while(T)
	{
		for(i = 0; i < MAX_SIZE ; i++)
			gets(grid[i]);
		gets(trash);

		gameState = getGameState(grid);

		printf("Case #%d: ", caseId);
		switch(gameState)
		{
			case X_WON:
				printf("X won\n");
				break;
			case O_WON:
				printf("O won\n");
				break;
			case DRAW:
				printf("Draw\n");
				break;
			default:
				printf("Game has not completed\n");
		}

		T--;
		caseId++;
	}
	return 0;
}


