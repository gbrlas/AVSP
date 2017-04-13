#include <cstdio>

#define REP(i,n) for (int i = 0; i < n; i++)

const char answers[2][2][32] = {
	{ "Game has not completed", "O won"},
	{ "X won", "Draw"}
};

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		int rows[3][4];
		int cols[3][4];
		int diag[3][2];

		REP (k, 3) {
			REP (y, 4) rows[k][y] = 0;
			REP (x, 4) cols[k][x] = 0;
			REP (d, 2) diag[k][d] = 0;
		}

		bool draw = true;

		REP (y, 4) REP (x, 4) {
			char c;
			scanf(" %c", &c);
			int k;
			if (c == 'X') {
				k = 0;
			} else if (c == 'O') {
				k = 1;
			} else if (c == 'T') {
				k = 2;
			} else {
				draw = false;
				continue;
			}
			rows[k][y]++;
			cols[k][x]++;
			if (x == y) diag[k][0]++;
			if (x == 3-y) diag[k][1]++;
		}

		bool won[2];

		REP (k, 2) {
			won[k] = false;
			REP (y, 4) if (rows[k][y] == 4 || (rows[k][y] == 3 && rows[2][y] == 1)) won[k] = true;
			REP (x, 4) if (cols[k][x] == 4 || (cols[k][x] == 3 && cols[2][x] == 1)) won[k] = true;
			REP (d, 2) if (diag[k][d] == 4 || (diag[k][d] == 3 && diag[2][d] == 1)) won[k] = true;
		}

		if (!won[0] && !won[1]) {
			won[0] = won[1] = draw;
		}

		printf("Case #%d: %s\n", i, answers[won[0]][won[1]]);
	}
	return 0;
}

