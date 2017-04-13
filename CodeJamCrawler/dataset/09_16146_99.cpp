#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000

const int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int T,H,W,map[100][100],basin[100][100],D;

int Flow(int n, int m) {
	int i,min=INF,move=-1,n2,m2;
		
	if(basin[n][m] != -1)
		return basin[n][m];
	for(i=0; i<4; i++) {
		n2 = n + dir[i][0];
		m2 = m + dir[i][1];
		if(n2 >= 0 && n2 < H && m2 >= 0 && m2 < W) {
			if(map[n2][m2] < min && map[n2][m2] < map[n][m]) {
				min = map[n2][m2];
				move = i;
			}
		}
	}
	if(move == -1) {
		basin[n][m] = D++;
		return basin[n][m];
	}
	else {
		basin[n][m] = Flow(n+dir[move][0], m+dir[move][1]);
		return basin[n][m];
	}
}
		
				

int main() {
	int i,j,cas=1;
	
//	freopen("testB.in", "r", stdin);
//	freopen("testB.out", "w", stdout);
	scanf("%d", &T);
	while(1) {
		scanf("%d%d", &H, &W);
		for(i=0; i<H; i++)
			for(j=0; j<W; j++)
				scanf("%d", &map[i][j]);
		memset(basin, 0xff, sizeof(basin));
		D = 0;
		for(i=0; i<H; i++)
			for(j=0; j<W; j++)
				basin[i][j] = Flow(i, j);
		printf("Case #%d:\n", cas);
		for(i=0; i<H; i++) {
			for(j=0; j<W; j++) {
				if(j != 0)
					printf(" ");
				printf("%c", basin[i][j]+'a');
			}
			printf("\n");
		}
		if(cas == T)
			break;
		cas++;
	}
	return 0;
}
	
