/*
 * Name 	: GCJ Magic Trick
 * Author	: DeathEater (pushkar8723@gmail.com)
 */
#include <stdio.h>
int main(){
	int t, row1, row2, grid1[4][4], grid2[4][4], i, j, k, count, save;
	scanf("%d", &t);
	for(k = 1; k <= t; k++){
		scanf("%d", &row1);
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				scanf("%d", &grid1[i][j]);
		scanf("%d", &row2);
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				scanf("%d", &grid2[i][j]);
		count = 0;
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++) {
				if(grid1[row1-1][i] == grid2[row2-1][j]) {
					save = grid1[row1-1][i];
					count++;
				}
			}
		if(count == 0)
			printf("Case #%d: Volunteer cheated!\n", k);
		else if (count == 1)
			printf("Case #%d: %d\n", k, save);
		else
			printf("Case #%d: Bad magician!\n", k);
	}
	return 0;
}

