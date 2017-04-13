#include <stdio.h>

static char map[5][5];
enum RESULT {XWIN, OWIN, DRAW, NOTFINISH};
const char* result[] = {
	"X won", "O won", "Draw", "Game has not completed"
};

int judge_row(int r)
{
	int sum, j;
	sum = 0;
	for (j = 0; j < 4; j++) {
		sum += map[r][j];
	}
	if (sum == 4 || sum == 33) return OWIN;
	else if (sum == 480 || sum == 390) return XWIN;
	else return DRAW;
}

int judge_col(int c)
{
	int sum, i;
	sum = 0;
	for (i = 0; i < 4; i++) {
		sum += map[i][c];
	}
	if (sum == 4 || sum == 33) return OWIN;
	else if (sum == 480 || sum == 390) return XWIN;
	else return DRAW;
}

int judge_zig(void)
{
	int sum = 0;
	sum += map[0][0] + map[1][1] + map[2][2] + map[3][3];
	if (sum == 4 || sum == 33) return OWIN;
	else if (sum == 480 || sum == 390) return XWIN;
	else return DRAW;
}

int judge_zag(void)
{
	int sum = 0;
	sum += map[0][3] + map[1][2] + map[2][1] + map[3][0];
	if (sum == 4 || sum == 33) return OWIN;
	else if (sum == 480 || sum == 390) return XWIN;
	else return DRAW;
}

int main(void)
{
	int T, i, j, c, pf, res;
	scanf("%d", &T);
	for (c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		for (i = 0; i < 4; i++) {
			scanf("%s", map[i]);
			for (j = 0; j < 4; j++) {
				if (map[i][j] == 'X') map[i][j] = 120;
				else if (map[i][j] == 'O') map[i][j] = 1;
				else if (map[i][j] == '.') map[i][j] = 20;
				else map[i][j] = 30;
			}
		}
		res = DRAW;
		pf  = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (map[i][j] == 20) pf = 1;
				res = judge_row(i);
				if (res != DRAW) break;
				res = judge_col(j);
				if (res != DRAW) break;
			}
			if (res != DRAW) break;
		}
		res = (res == DRAW ? judge_zig() : res);
		res = (res == DRAW ? judge_zag() : res);
		if (res == DRAW) {
			res = pf ? NOTFINISH : res;
		}
		printf("%s\n", result[res]);
	}
	return 0;
}

