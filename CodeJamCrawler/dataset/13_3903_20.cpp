//============================================================================
// Name        : codejam1.cpp
// Author      : sanket sudake
// Version     :
// Copyright   : GNU GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include<algorithm>
#include <queue>

using namespace std;
void printsol(int op, int k) {
	switch (op) {
	case 1:
		cout << "Case #" << k + 1 << ": X won" << endl;
		break;
	case 2:
		cout << "Case #" << k + 1 << ": O won" << endl;
		break;
	case 3:
		cout << "Case #" << k + 1 << ": Draw" << endl;
		break;
	case 4:
		cout << "Case #" << k + 1 << ": Game has not completed" << endl;
		break;
	default:
		cout << "Case #" << k + 1 << ": Case not found" << endl;
		break;
	}
}
int solve(char tic[4][4], int k) {
	for (int i = 0; i < 4; i++) {
		if ((tic[i][0] == tic[i][1] || tic[i][0] == 'T' || tic[i][1] == 'T')
				&& (tic[i][1] == tic[i][2] || tic[i][1] == 'T'
						|| tic[i][2] == 'T')
				&& (tic[i][2] == tic[i][3] || tic[i][2] == 'T'
						|| tic[i][3] == 'T') && tic[i][0] != '.'
				&& tic[i][1] != '.' && tic[i][2] != '.' && tic[i][3] != '.') {
			if (tic[i][0] == 'X' || tic[i][1] == 'X') {
				printsol(1, k);
			} else
				printsol(2, k);
			return 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		if ((tic[0][i] == tic[1][i] || tic[0][i] == 'T' || tic[1][i] == 'T')
				&& (tic[1][i] == tic[2][i] || tic[1][i] == 'T'
						|| tic[2][i] == 'T')
				&& (tic[2][i] == tic[3][i] || tic[2][i] == 'T'
						|| tic[3][i] == 'T') && tic[0][i] != '.'
				&& tic[1][i] != '.' && tic[2][i] != '.' && tic[3][i] != '.') {
			if (tic[0][i] == 'X' || tic[1][i] == 'X') {
				printsol(1, k);
			} else
				printsol(2, k);
			return 0;
		}
	}
	if ((tic[0][0] == tic[1][1] || tic[0][0] == 'T' || tic[1][1] == 'T')
			&& (tic[1][1] == tic[2][2] || tic[1][1] == 'T' || tic[2][2] == 'T')
			&& (tic[2][2] == tic[3][3] || tic[2][2] == 'T' || tic[3][3] == 'T')
			&& tic[0][0] != '.' && tic[1][1] != '.' && tic[2][2] != '.'
			&& tic[3][3] != '.') {
		if (tic[0][0] == 'X' || tic[1][1] == 'X') {
			printsol(1, k);
		} else
			printsol(2, k);
		return 0;
	}
	if ((tic[0][3] == tic[1][2] || tic[0][3] == 'T' || tic[1][2] == 'T')
			&& (tic[1][2] == tic[2][1] || tic[1][2] == 'T' || tic[2][1] == 'T')
			&& (tic[2][1] == tic[3][0] || tic[2][1] == 'T' || tic[3][0] == 'T')
			&& tic[0][3] != '.' && tic[1][2] != '.' && tic[2][1] != '.'
			&& tic[3][0] != '.') {
		if (tic[0][3] == 'X' || tic[1][2] == 'X')
			printsol(1, k);
		else
			printsol(2, k);
		return 0;
	}
	return -1;
}
int main() {
	char tic[4][4];
	int testcase;
	cin >> testcase;
	bool flag;
	for (int k = 0; k < testcase; k++) {
		flag = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> tic[i][j];
				if (tic[i][j] == '.'){
					flag = true;
				}
			}
		if (solve(tic, k) == -1) {
			if (flag)
				printsol(4, k);
			else
				printsol(3, k);

		}
	}
	return 0;
}
