#include <stdio.h>

int main() {
					//y * x
	int resultBoard[100][100];

	int T;
	scanf("%d", &T);

	int N, M;	//N - height (number of rows),   M - width (number of colls)
	for (int nr=1; nr<=T; nr++) {
		
		scanf("%d %d", &N, &M);
		for (int n=0; n<N; n++)
			for (int m=0; m<M; m++) {
				scanf("%d", &resultBoard[n][m]);
				//freshBoard[n][m] = 100;
			}

		bool possible = true;
		for (int n=0; n<N; n++) {	//rows
			for (int m=0; m<M; m++) {	//colls

				bool possibleVertical = true;
				bool possibleHorizontal = true;

				int myVal = resultBoard[n][m];
				//dla danego punktu testujemy pionowa linie
				for (int y=0; y<N; y++)
					if (myVal < resultBoard[y][m]) {
						possibleVertical = false;
						break;
					}

				//dla danego punktu testujemy pozioma linie
				for (int x=0; x<M; x++)
					if (myVal < resultBoard[n][x]) {
						possibleHorizontal = false;
						break;
					}

				if (!(possibleHorizontal || possibleVertical)) {
					possible = false;
					break;
				}
			}
			if (!possible)
				break;
		}

		printf("Case #%d: %s\n", nr, (possible ? "YES" : "NO") );
	}


	getchar();getchar();
	return 0;
}