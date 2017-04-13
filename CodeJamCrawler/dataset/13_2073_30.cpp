#include <stdio.h>
using namespace std;

main()
{
	int TC, T = 0, i, j, ganado, terminado;
	char t[10][10], cur;
	scanf("%d", &TC);
	while (T++ < TC) {
		printf("Case #%d: ", T);
		for (i = 0; i < 4; i++)
			scanf("%s", t[i]);

		// diagonal izq-der
		cur = 0;
		for (i = 0; i < 4; i++)
			if (t[i][i] != '.' && t[i][i] != 'T') {
				cur = t[i][i];
				break;
			}
		for (ganado = 1, i = 0; i < 4; i++)
			if (cur != t[i][i] && t[i][i] != 'T') {
				ganado = 0;
				break;
			}
		if (cur == 0)
			ganado = 0;

		// diagonal der-izq
		if (ganado == 0) {
			cur = 0;
			for (i = 0; i < 4; i++)
				if (t[i][3 - i] != '.' && t[i][3 - i] != 'T') {
					cur = t[i][3 - i];
					break;
				}
			for (ganado = 1, i = 0; i < 4; i++)
				if (cur != t[i][3 - i] && t[i][3 - i] != 'T') {
					ganado = 0;
					break;
				}
			if (cur == 0)
				ganado = 0;
		}

		// verticales
		if (ganado == 0) {
			for (int k = 0; k < 4 && ganado == 0; k++) {
				cur = 0;
				for (i = 0; i < 4; i++)
					if (t[i][k] != '.' && t[i][k] != 'T') {
						cur = t[i][k];
						break;
					}
				for (ganado = 1, i = 0; i < 4; i++)
					if (t[i][k] != cur && t[i][k] != 'T') {
						ganado = 0;
						break;
					}
				if (cur == 0)
					ganado = 0;
			}
		}

		// horizontales
		if (ganado == 0) {
			for (int k = 0; k < 4 && ganado == 0; k++) {
				cur = 0;
				for (i = 0; i < 4; i++)
					if (t[k][i] != '.' && t[k][i] != 'T') {
						cur = t[k][i];
						break;
					}
				for (ganado = 1, i = 0; i < 4; i++)
					if (t[k][i] != cur && t[k][i] != 'T') {
						ganado = 0;
						break;
					}
				if (cur == 0)
					ganado = 0;
			}
		}

		// impresion
		if (ganado)
			if (cur == 'X')
				printf("X won\n");
			else
				printf("O won\n");
		else {
			terminado = 1;
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++)
					if (t[i][j] == '.') {
						terminado = 0;
						break;
					}
				if (terminado == 0)
					break;
			}
			if (terminado)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
		}
	}
	return 0;
}
