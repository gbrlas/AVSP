#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define HEIGHT 4
#define WIDTH 4

typedef struct _data *Data;

typedef struct _data {
	char board[HEIGHT][WIDTH];
} data;

void getBoard(Data d);
char *getOutput(Data d);
int checkHorizontal(Data d, char player);
int checkVertical(Data d, char player);
int checkDiagonal(Data d, char player);
int boardFull(Data d);
void printBoard(Data d);

int main(int argc, char *argv[]) {
	int numCases, curCase;
	scanf("%d\n", &numCases);
	Data d = malloc(sizeof(data));

	for (curCase = 1; curCase <= numCases; curCase++) {
		getBoard(d);
		//printBoard(d);
		printf("Case #%d: %s\n", curCase, getOutput(d));
		if (curCase != numCases) 
			getchar();
	}
	return 0;
}

void printBoard(Data d) {
	int x;
	int y;
	for (y = HEIGHT-1; y >= 0; y--) {
		for (x = 0; x < WIDTH; x++) {
			printf("%c", d->board[y][x]);
		}
		printf("\n");
	}
}

void getBoard(Data d) {
	int height;
	int width;
	char curChar;
	for (height = HEIGHT-1; height >= 0; height--) {
		for (width = 0; width < WIDTH; width++) {
			d->board[height][width] = (curChar = getchar());
			//printf("%c", d->board[height][width]);
		}
		getchar();
	}
}

char *getOutput(Data d) {
	if (checkHorizontal(d, 'X') || checkVertical(d, 'X') || checkDiagonal(d, 'X'))
		return "X won";
	else if (checkHorizontal(d, 'O') || checkVertical(d, 'O') || checkDiagonal(d, 'O'))
		return "O won";
	else if (boardFull(d))
		return "Draw";
	return "Game has not completed";
}

int checkHorizontal(Data d, char player) {
	int x;
	int y;
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH; x++) {
			if (d->board[y][x] != player && d->board[y][x] != 'T')
				break;
			if (x == (WIDTH-1))
				return TRUE;
		}
	}
	return FALSE;
}

int checkVertical(Data d, char player) {
	int x;
	int y;
	for (x = 0; x < WIDTH; x++) {
		for (y = 0; y < HEIGHT; y++) {
			if (d->board[y][x] != player && d->board[y][x] != 'T')
				break;
			if (y == (HEIGHT-1)) 
				return TRUE;
		}
	}
	return FALSE;
}

int checkDiagonal(Data d, char player) {
	int x = 0;
	int y = 0;
	while (x != WIDTH) {
		if (d->board[y][x] != player && d->board[y][x] != 'T')
			break;
		x++;
		y++;
	}
	if (x == WIDTH) 
		return TRUE;
	y = HEIGHT-1;
	x = 0;
	while (x != WIDTH) {
		if (d->board[y][x] != player && d->board[y][x] != 'T')
			break;
		x++;
		y--;
	}
	if (x == WIDTH) 
		return TRUE;
	return FALSE;
}

int boardFull(Data d) {
	int x;
	int y;
	for (x = 0; x < WIDTH; x++) {
		for (y = 0; y < HEIGHT; y++) {
			if (d->board[y][x] == '.')
				return FALSE;
		}
	}
	return TRUE;
}


