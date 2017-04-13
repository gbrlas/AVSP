#include <cstdio>

char bd[5][5];
char map[37];

int main(void) {
	int T;
	int tmp;
	int finished;
	scanf("%d", &T);
	//'X'=9 'O'=0 'T'=5
	map[36] = 'X';
	map[0] ='O';
	map[32] = 'X';
	map[5] = 'O';

	for (int ti=1; ti<=T; ++ti) {
		scanf("%s", bd[0]);
		scanf("%s", bd[1]);
		scanf("%s", bd[2]);
		scanf("%s", bd[3]);
		finished = 1;
		for (;;) {
		for (int i=0; i<4; ++i) {
			tmp = 0;
			for (int j=0; j<4; ++j) {
				tmp += bd[i][j]-'O';
			}
			if (tmp<0) {
				finished = 0;
				tmp = 1;
			}	
			if (map[tmp]) break;
		}
		if (map[tmp]) break;

		for (int j=0; j<4; ++j) {
			tmp = 0;
			for (int i=0; i<4; ++i) {
				tmp += bd[i][j]-'O';
			}
			if (tmp<0) {
				finished = 0;
				tmp = 1;
			}
			if (map[tmp]) break;
		}
		if (map[tmp]) break;

		tmp = 0;
		for (int i=0; i<4; ++i) {
			tmp += bd[i][i]-'O';
		}
		if (tmp<0) {
			finished = 0;
			tmp = 1;
		}
		if (map[tmp]) break;

		tmp = 0;
		for (int i=0; i<4; ++i) {
			tmp += bd[i][3-i]-'O';
		}
		if (tmp<0) {
			finished = 0;
			tmp = 1;
		}
		break;
		}
		if(map[tmp]=='O') {
			printf("Case #%d: O won\n", ti);
		} else if (map[tmp] == 'X') {
			printf("Case #%d: X won\n", ti);
		}else if (finished) {			
			printf("Case #%d: Draw\n", ti);
		}else {			
			printf("Case #%d: Game has not completed\n", ti);
		}
	}
	return 0;
}