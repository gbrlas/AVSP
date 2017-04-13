#include "stdio.h"

enum ResultType_t
{
	TICTACTOE_NO_WINNER = 0,
	TICTACTOE_X_WON = 1,
	TICTACTOE_O_WON = 2
};

ResultType_t solve(char** board)
{
	// Check vertical
	for (int x = 0; x < 4; ++x) {
		char current_ch = board[x][0];
		if (current_ch == '.') {
			continue;
		}

		int y;
		if (current_ch == 'T') {
			current_ch = board[x][1];
			if (current_ch == '.') {
				continue;
			}

			for (y = 2; y < 4; ++y) {
				char next_ch = board[x][y];
				if (next_ch != current_ch) {
					break;
				}
			}
		} else {
			for (y = 1; y < 4; ++y) {
				char next_ch = board[x][y];
				if (next_ch != current_ch && next_ch != 'T') {
					break;
				}
			}
		}

		if (y == 4) {
			return current_ch == 'X' ? TICTACTOE_X_WON : TICTACTOE_O_WON;
		}
	}

	// Check horizontal
	for (int y = 0; y < 4; ++y) {
		char current_ch = board[0][y];
		if (current_ch == '.') {
			continue;
		}

		int x;
		if (current_ch == 'T') {
			current_ch = board[1][y];
			if (current_ch == '.') {
				continue;
			}

			for (x = 2; x < 4; ++x) {
				char next_ch = board[x][y];
				if (next_ch != current_ch) {
					break;
				}
			}
		} else {
			for (x = 1; x < 4; ++x) {
				char next_ch = board[x][y];
				if (next_ch != current_ch && next_ch != 'T') {
					break;
				}
			}
		}

		if (x == 4) {
			return current_ch == 'X' ? TICTACTOE_X_WON : TICTACTOE_O_WON;
		}
	}

	// Check diagonal 1
	char current_ch = board[0][0];
	if (current_ch != '.') {
		int i;
		if (current_ch == 'T') {
			current_ch = board[1][1];
			if (current_ch != '.') {
				for (i = 2; i < 4; ++i) {
					char next_ch = board[i][i];
					if (next_ch != current_ch) {
						break;
					}
				}
			} else {
				i = 0;
			}
		} else {
			for (i = 1; i < 4; ++i) {
				char next_ch = board[i][i];
				if (next_ch != current_ch && next_ch != 'T') {
					break;
				}
			}
		}

		if (i == 4) {
			return current_ch == 'X' ? TICTACTOE_X_WON : TICTACTOE_O_WON;
		}
	}

	// Check diagonal 2
	current_ch = board[0][3];
	if (current_ch != '.') {
		int i;
		if (current_ch == 'T') {
			current_ch = board[1][2];
			if (current_ch != '.') {
				for (i = 2; i < 4; ++i) {
					char next_ch = board[i][3 - i];
					if (next_ch != current_ch) {
						break;
					}
				}
			} else {
				i = 0;
			}
		} else {
			for (i = 1; i < 4; ++i) {
				char next_ch = board[i][3 - i];
				if (next_ch != current_ch && next_ch != 'T') {
					break;
				}
			}
		}

		if (i == 4) {
			return current_ch == 'X' ? TICTACTOE_X_WON : TICTACTOE_O_WON;
		}
	}
	return TICTACTOE_NO_WINNER;
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		fprintf(stderr, "Program requires 2 arguments, expected: %s infile outfile\n", argv[0]);
		return 1;
	}

	FILE* infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "Could not read infile: %s\n", argv[1]);
		return 1;
	}

	FILE* outfile = fopen(argv[2], "w");
	if (outfile == NULL) {
		fprintf(stderr, "Could not read outfile: %s\n", argv[2]);
		return 1;
	}

	char** board = new char*[4];
	for (int i = 0; i < 4; ++i) {
		board[i] = new char[4];
	}

	int T;
	fscanf(infile, "%d", &T);
	for (int i = 1; i <= T; ++i) {
		bool incomplete = false;
		fgetc(infile);
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				char ch = fgetc(infile);
				board[j][k] = ch;
				if (ch == '.') {
					incomplete = true;
				}
			}
			fgetc(infile);
		}

		ResultType_t res = solve(board);
		switch (res) {
			case TICTACTOE_X_WON:
				fprintf(outfile, "Case #%d: X won\n", i);
				break;
			case TICTACTOE_O_WON:
				fprintf(outfile, "Case #%d: O won\n", i);
				break;
			case TICTACTOE_NO_WINNER:
				if (incomplete) {
					fprintf(outfile, "Case #%d: Game has not completed\n", i);
				} else {
					fprintf(outfile, "Case #%d: Draw\n", i);
				}
				break;
		}
	}

	for (int i = 0; i < 4; ++i) {
		delete[] board[i];
	}
	delete board;

	fclose(outfile);
	fclose(infile);
	return 0;
}
