#include <stdio.h>

// google code jam 2013, qualification round, problem A
// israel leiva - april 13th
int main(void){
	short win, incomplete, next_diag;
	int T, tc = 0, i, j;
	char b[4][4], isym, winner;
	scanf("%d\n", &T);
	while(T){
		tc++;
		printf("Case #%d: ", tc);

		win = incomplete = next_diag = 0;

		// read input
		for(i=0; i<4; i++){
			for(j=0; j<4; j++)
				scanf("%c", &b[i][j]);
			scanf("\n");
		}

		// check rows
		for(i=0; i<4; i++){
			// row begins empty?
			if(b[i][0] == '.'){
				// go to next row
				incomplete = 1;
				continue;
			// row begins with special character?
			}else if(b[i][0] == 'T'){
				isym = b[i][1];
				if(isym == '.'){
					incomplete = 1;
					continue;
				}
				if(isym == b[i][2] && isym == b[i][3]){
					win = 1;
					winner = isym;
					break;
				}else if(b[i][2] == '.' || b[i][3] == '.'){
					incomplete = 1;
				}
			}else{
				// row begins with X or O?
				isym = b[i][0];
				if((isym == b[i][1] || b[i][1] == 'T') && (isym == b[i][2] || b[i][2] == 'T' ) && (isym == b[i][3] || b[i][3] == 'T')){
					win = 1;
					winner = isym;
					break;
				}else if(b[i][1] == '.' || b[i][2] == '.' || b[i][3] == '.'){
					incomplete = 1;
				}
			}
		}
		
		// check columns
		if(!win){
			for(i=0; i<4; i++){
				// column begins empty?
				if(b[0][i] == '.'){
					// go to next column
					incomplete = 1;
					continue;
				// column begins with special character?
				}else if(b[0][i] == 'T'){
					isym = b[1][i];
					if(isym == '.'){
						incomplete = 1;
						continue;
					}
					if(isym == b[2][i] && isym == b[3][i]){
						win = 1;
						winner = isym;
						break;
					}else if(b[2][i] == '.' || b[3][i] == '.'){
						incomplete = 1;
					}
				}else{
					// column begins with X or O?
					isym = b[0][i];
					if((isym == b[1][i] || b[1][i] == 'T') && (isym == b[2][i] || b[2][i] == 'T' ) && (isym == b[3][i] || b[3][i] == 'T')){
						win = 1;
						winner = isym;
						break;
					}else if(b[1][i] == '.' || b[2][i] == '.' || b[3][i] == '.'){
						incomplete = 1;
					}
				}
			}
		}
		
		
		// check diagonals
		
		// main diagonal
		// begins empty?
		if(!win){
			if(b[0][0] == '.'){
				// go to next diagonal
				incomplete = 1;
				next_diag = 1;
			// diagonal begins with special character?
			}else if(b[0][0] == 'T' && !next_diag){
				isym = b[1][1];
				if(isym == '.'){
					incomplete = 1;
					next_diag = 1;
				}
				if(isym == b[2][2] && isym == b[3][3] && !next_diag){
					win = 1;
					winner = isym;
				}else if(b[2][2] == '.' || b[3][3] == '.'){
					incomplete = 1;
				}
			}else{
				// diagonal begins with X or O?
				isym = b[0][0];
				if((isym == b[1][1] || b[1][1] == 'T') && (isym == b[2][2] || b[2][2] == 'T' ) && (isym == b[3][3] || b[3][3] == 'T')){
					win = 1;
					winner = isym;
				}else if(b[1][1] == '.' || b[2][2] == '.' || b[3][3] == '.'){
					incomplete = 1;
				}
			}
		}

		next_diag = 0;

		// inverted diagonal
		// begins empty?
		if(!win){
			if(b[0][3] == '.'){
				// go to next diagonal
				incomplete = 1;
				next_diag = 1;
			// diagonal begins with special character?
			}else if(b[0][3] == 'T' && !next_diag){
				isym = b[1][2];
				if(isym == '.'){
					incomplete = 1;
					next_diag = 1;
				}
				if(isym == b[2][1] && isym == b[3][0] && !next_diag){
					win = 1;
					winner = isym;
				}else if(b[2][1] == '.' || b[3][0] == '.'){
					incomplete = 1;
				}
			}else{
				// diagonal begins with X or O?
				isym = b[0][3];
				if((isym == b[1][2] || b[1][2] == 'T') && (isym == b[2][1] || b[2][1] == 'T' ) && (isym == b[3][0] || b[3][0] == 'T')){
					win = 1;
					winner = isym;
				}else if(b[1][2] == '.' || b[2][1] == '.' || b[3][0] == '.'){
					incomplete = 1;
				}
			}
		}
		
		if(win)
			printf("%c won\n", winner);
		else if(!win && !incomplete)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
		T--;
	}
	return 0;
}
