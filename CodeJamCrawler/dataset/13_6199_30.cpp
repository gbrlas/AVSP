//============================================================================
// Name        : Tic-Tac-Toe-Tomek.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int OwinX(char c0, char c1, char c2, char c3) {
	int sum = c0 + c1 + c2 + c3;
	if (sum == 352 || sum == 348)
		return -1;
	else if (sum == 316 || sum == 321)
		return 1;
	else
		return 0;

}
bool complete(const string *line) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (line[i][j] == '.')
				return false;
	return true;
}
int main() {
	int case_num;
	cin >> case_num;
	string line[4];

	for (int i = 0; i < case_num; i++) {
		int owinx = 0;
		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < 4; j++)
			cin >> line[j];
		// for each line
		for (int j = 0; j < 4; j++)
			owinx += OwinX(line[j][0], line[j][1], line[j][2], line[j][3]);
		// for each row
		for (int j = 0; j < 4; j++)
			owinx += OwinX(line[0][j], line[1][j], line[2][j], line[3][j]);
		// for 2 diagonal
		owinx += OwinX(line[0][0], line[1][1], line[2][2], line[3][3]);
		owinx += OwinX(line[0][3], line[1][2], line[2][1], line[3][0]);

		if (owinx > 0) {
			cout << "O won" << endl;
		}
		else if (owinx < 0)
			cout << "X won" << endl;
		else {
			if (!complete(line))
				cout << "Game has not completed" << endl;
			else
				cout << "Draw" << endl;
		}
	}
	return 0;
}
