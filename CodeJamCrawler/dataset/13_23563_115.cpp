#include <iostream>

using namespace std;

int main() {
	string board[4];
	int T, i, j;
	bool lineWin, columnWin, ascendingWin, descendingWin, full;
	char lineChar, columnChar, ascendingChar, descendingChar;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		full = true;

		for(i = 0; i < 4; i++) 
			cin >> board[i];
	
		for(i = 0; i < 4; i++) {
			lineChar = board[i][0];
			columnChar = board[0][i];
			if (lineChar == 'T') 
				lineChar = board[i][1];
			if (columnChar == 'T') 
				columnChar = board[1][i];
			lineWin = true;
			columnWin = true;
			for(j = 0; j < 4; j++) {
				if(board[i][j] != lineChar && board[i][j] != 'T') lineWin = false;
				if(board[j][i] != columnChar && board[j][i] != 'T') columnWin = false;
				if(board[i][j] == '.' || board[j][i] == '.') full = false;
			}
			if(lineWin && lineChar != '.') {
				cout << lineChar << " won" << endl;
				break;
			}
			if(columnWin && columnChar != '.') {
				cout << columnChar << " won" << endl;
				break;
			}
		}
		if((lineWin && lineChar != '.') || (columnWin && columnChar != '.')) {
			continue;
		}

		
		descendingChar = board[0][0];
		ascendingChar = board[3][0];
		descendingWin = true;
		ascendingWin = true;
		if(descendingChar == 'T')
			descendingChar = board[1][1];
		if(ascendingChar == 'T')
			ascendingChar = board[2][1];
		for(i = 1; i < 4; i++) {
			if(board[i][i] != descendingChar && board[i][i] != 'T') descendingWin = false;
			if(board[3-i][i] != ascendingChar && board[3-i][i] != 'T') ascendingWin = false;
		}
		if(descendingWin && descendingChar != '.') {
			cout << descendingChar << " won" << endl;
			continue;
		}
		if(ascendingWin && ascendingChar != '.') {
			cout << ascendingChar << " won" << endl;
			continue;
		}

		if (!full) {
			cout << "Game has not completed" << endl;
		} else {
			cout << "Draw" << endl;
		}
	}
	return 0;
}

