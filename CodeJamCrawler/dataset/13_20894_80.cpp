#include <stdio.h>

int main() {
			  //y * x
	char board [4][5];

	int games;
	scanf("%d", &games);

	for (int nr=1; nr<=games; nr++) {
		
		for (int i=0; i<4; i++)
			scanf("%s", &board[i]);

		//printf("A: %s; %s; %s; %s\n", board[0], board[1], board[2], board[3]);

		//count vertical:
		int sx = 0, so = 0;
		bool win=false, dot=false;

		for (int swap=0; swap<2; swap++) {	//0 = vertical, 1 = horizontal

			//dot = false;
			for (int i=0; i<4; i++) {	//rows

				sx = 0;
				so = 0;
				for (int j=0; j<4; j++) {	//cols
				
					switch ( swap==0 ? board[i][j] : board[j][i] ) {
						case 'X':
							sx++; break;
						case 'O':
							so++; break;
						case 'T':
							sx++; so++; break;
						case '.':
							dot = true;
					}
				}
				if (sx==4 || so==4) {
					win = true;
					break;
				}
			}
			if (win)
				break;
		}

		//count diagonal:
		if (!win) {

			for (int swap=0; swap<2; swap++) {	//0 = vertical, 1 = horizontal

				sx = 0;
				so = 0;
				for (int i=0; i<4; i++) {	//rows

					for (int j=0; j<4; j++) {	//cols
				
						if ((swap == 0 && i == j) || (swap == 1 && i == 3-j))  {

							switch ( board[i][j] ) {
								case 'X':
									sx++; break;
								case 'O':
									so++; break;
								case 'T':
									sx++; so++; break;
							}
						}
					}
					if (sx==4 || so==4) {
						win = true;
						break;
					}
				}
				if (win)
					break;
			}

		}

		printf("Case #%d: ", nr);
		if (win)
			printf("%c won\n", (sx==4? 'X' : 'O'));
		else
			if (dot)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
	}


	getchar();getchar();
	return 0;
}