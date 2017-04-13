#include <iostream>
#include <algorithm>

/*
	
	1 => X won
	2 => O won
	3 => Draw
	4 => Game has not completed

* * * * * * * */

const int X_won1 = 4 * 10000;
const int X_won2 = 3 * 10000 + 1000;

const int O_won1 = 4 * 10;
const int O_won2 = 3 * 10 + 1000;

bool Dots = false;

void readBoard (int *_b)
{
	Dots = false;
	for (int i = 0; i < 16; ++i) {
		char s; std::cin >> s;
		if (s == 'X') {
			_b[i] = 10000;
		} else if (s == 'O') {
			_b[i] = 10;
		} else if (s == '.') { 
			_b[i] = 0;
			Dots = true;
		} else if (s == 'T') { 
			_b[i] = 1000;			
		}
	}
}

int Check (int *_b)
{
	for (int i = 0; i < 16; i += 4) {
		int h = _b[i+0] + _b[i+1] + _b[i+2] + _b[i+3];
		if (h == X_won1 || h == X_won2) {
			return 1;
		}
		if (h == O_won1 || h == O_won2) {
			return 2;
		}
	}

	for (int i = 0; i < 4; ++i) {
		int v = _b[i+0] + _b[i+4] + _b[i+8] + _b[i+12];
		if (v == X_won1 || v == X_won2) {
			return 1;
		}
		if (v == O_won1 || v == O_won2) {
			return 2;
		}
	}

	int d1 = _b[ 0] + _b[ 5] + _b[10] + _b[15];
	int d2 = _b[ 3] + _b[ 6] + _b[ 9] + _b[12];

	if (d1 == X_won1 || d1 == X_won2 ||
		d2 == X_won1 || d2 == X_won2) {
		return 1;
	}

	if (d1 == O_won1 || d1 == O_won2 ||
		d2 == O_won1 || d2 == O_won2) {
		return 2;
	}

	return (Dots ? 4 : 3);
}


int main()
{
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		int board[16];
		readBoard(board);
		int r = Check(board);
		std::cout << "Case #" << i << ": ";
		if (r == 1) {
				std::cout << "X won\n";		
		} else if (r == 2) {
			std::cout << "O won\n";
		} else if (r == 3) {
			std::cout << "Draw\n";
		} else if (r == 4) {
			std::cout << "Game has not completed\n";
		}
	}

	return 0;
}