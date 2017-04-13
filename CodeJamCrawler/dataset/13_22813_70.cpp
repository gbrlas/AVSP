#include <iostream>
#include <fstream>
using namespace std;

#define BOARD_SIZE 4
#define to1D(x, y) ((x) + (y) * (BOARD_SIZE + 1))

long long board[2], nPiece;

bool hasWon(int i) {
	// \	/
	long w = board[i] & (board[i] >> (BOARD_SIZE + 2));
	w &= w >> (2 * (BOARD_SIZE + 2));
	// -	/
	long x = board[i] & (board[i] >> 1);
	x &= x >> (2 * 1);
	// /	/
	long y = board[i] & (board[i] >> BOARD_SIZE);
	y &= y >> (2 * BOARD_SIZE);
	// |	/
	long z = board[i] & (board[i] >> (BOARD_SIZE + 1));
	z &= z >> (2 * (BOARD_SIZE + 1));
	return (w | x | y | z) != 0;
}

int main() {
	ifstream cin;
	cin.open("in.txt");
	ofstream cout;
	cout.open("out.txt");
	string line;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		// initialize
		nPiece = 16;
		board[0] = board[1] = 0;
		// input
		for (int y = 0; y < 4; ++y) {
			cin >> line;
			for (int x = 0; x < 4; ++x) {
				if (line[x] == 'X')
					board[0] |= (1 << to1D(x, y));
				else if (line[x] == 'O')
					board[1] |= (1 << to1D(x, y));
				else if (line[x] == 'T')
					board[0] |= (1 << to1D(x, y)), board[1] |= (1 << to1D(x, y));
				else
					nPiece--;
			}
		}
		// result
		cout << "Case #" << (i + 1) << ": ";
		if (hasWon(0) && !hasWon(1))
			cout << "X won";
		else if (!hasWon(0) && hasWon(1))
			cout << "O won";
		else if ((hasWon(0) && hasWon(1)) || nPiece == 16)
			cout << "Draw";
		else
			cout << "Game has not completed";
		cout << endl;
	}
	return 0;
}
