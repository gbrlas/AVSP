#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char board[4][5];
int compFlag;
int oxFlag; // 0 = O, 1 = X

int checkVertical();
int checkHorizontal();
int checkDiag1();
int checkDiag2();

int main () {
	int N;
	int caseNum;


	FILE *ifp, *ofp;
	ifp = fopen("A-small-attempt0.in", "r");
	ofp = fopen("output.txt", "w");

	fscanf(ifp, "%d", &N);
	//scanf("%d", &N);
	
	for (caseNum = 1; caseNum <= N; ++caseNum) {
		compFlag = 1;
		oxFlag = 0;
		int i, j;
		for (i = 0; i < 4; ++i) {
			//scanf("%s", board[i]);
			fscanf(ifp, "%s", board[i]);
		}
		for (i = 0; i < 4; ++i) {
			for (j = 0; j < 4; ++j) {
				if (board[i][j] == '.') compFlag = 0;
				break;
			}
		}

		if (checkVertical() ||
			checkHorizontal() ||
			checkDiag1() ||
			checkDiag2()) {
			if (oxFlag) fprintf(ofp, "Case #%d: X won\n", caseNum);
			else fprintf(ofp, "Case #%d: O won\n", caseNum);
		}
		else {
			if (compFlag) fprintf(ofp, "Case #%d: Draw\n", caseNum);
			else fprintf(ofp, "Case #%d: Game has not completed\n", caseNum);
		}
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}

int checkVertical() {
	//printf("Vertical\n");
	int i, j;
	char temp;
	for (i = 0; i < 4; ++i) {
		temp = board[i][0];
		j = 1;
		if (temp == 'X') oxFlag = 1;
		else if (temp == 'O') oxFlag = 0;
		else if (temp == '.') {j = 5;}
		else if (temp == 'T') {
			++j;
			temp = board[i][1];
			if (temp == 'X') oxFlag = 1;
			else if (temp == 'O') oxFlag = 0;
			else if (temp == '.') {j = 5;}
		}

		while (j < 4) {
			if (temp != board[i][j] && 
				'T' != board[i][j]) {
				if (board[i][j])
				j = 5;
			}
			++j;
		}
		if (j == 4) return 1;
	}
	return 0;
}

int checkHorizontal() {
	//printf("Horizontal\n");
	int i, j;
	char temp;
	for (i = 0; i < 4; ++i) {
		temp = board[0][i];

		j = 1;
		if (temp == 'X') oxFlag = 1;
		else if (temp == 'O') oxFlag = 0;
		else if (temp == '.') j = 5;
		else if (temp == 'T') {
			++j;
			temp = board[1][i];
			if (temp == 'X') oxFlag = 1;
			else if (temp == 'O') oxFlag = 0;
			else if (temp == '.') j = 5;
		}

		while (j < 4) {
			if (temp != board[j][i] && 
				'T' != board[j][i]) {
				oxFlag = -1;
				j = 5;
			}
			++j;
		}
		if (j == 4) return 1;
	}
	return 0;
}

int checkDiag1() {
	//printf("Diag1\n");
	int i = 1;
	char temp = board[0][0];
	if (temp == 'X') oxFlag = 1;
		else if (temp == 'O') oxFlag = 0;
		else if (temp == '.') return 0;
		else if (temp == 'T') {
			i = 2;
			temp = board[1][1];
			if (temp == 'X') oxFlag = 1;
			else if (temp == 'O') oxFlag = 0;
			else if (temp == '.') return 0;
	}
	while (i < 4) {
		if (temp != board[i][i] &&
			'T' != board[i][i]) {
			i = 5;
		}
		++i;
	}
	if (i == 4) return 1;
	return 0;
}

int checkDiag2() {
	//printf("Diag2\n");
	int i = 1;
	char temp = board[0][3];
	if (temp == 'X') oxFlag = 1;
		else if (temp == 'O') oxFlag = 0;
		else if (temp == '.') return 0;
		else if (temp == 'T') {
			i = 2;
			temp = board[1][2];
			if (temp == 'X') oxFlag = 1;
			else if (temp == 'O') oxFlag = 0;
			else if (temp == '.') return 0;
	}
	while (i < 4) {
		if (temp != board[i][3-i] &&
			'T' != board[i][3-i]) {
			i = 5;
		}
		++i;
	}
	if (i == 4) return 1;
	return 0;
}