#include <stdio.h>

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		char d[4][5];
		scanf("%s%s%s%s", d[0], d[1], d[2], d[3]);
		int x = 0, o = 0, t = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (d[i][j] == 'X')
					++x;
				else if (d[i][j] == 'O')
					++o;
				else if (d[i][j] == 'T')
					++t;

		char c;
		if (x > o)
			c = 'X';
		else
			c = 'O';

		bool w = true;
		for (int i = 0; i < 4; ++i)
			if (d[i][i] != c && d[i][i] != 'T')
				w = false;
		if (w) {
			printf("Case #%d: %c won\n", tt, c);
			continue;
		}

		w = true;
		for (int i = 0; i < 4; ++i)
			if (d[i][3 - i] != c && d[i][3 - i] != 'T')
				w = false;
		if (w) {
			printf("Case #%d: %c won\n", tt, c);
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			w = true;
			for (int j = 0; j < 4; ++j)
				if (d[i][j] != c && d[i][j] != 'T')
					w = false;
			if (w) {
				printf("Case #%d: %c won\n", tt, c);
				break;
			}

			w = true;
			for (int j = 0; j < 4; ++j)
				if (d[j][i] != c && d[j][i] != 'T')
					w = false;
			if (w) {
				printf("Case #%d: %c won\n", tt, c);
				break;
			}
		}
		if (w)
			continue;

		if (x + o + t < 16)
			printf("Case #%d: Game has not completed\n",tt);
		else printf("Case #%d: Draw\n", tt);
	}
}
