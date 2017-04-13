#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,K,s[16][25],min;
bool cross[16][16];

void DFS(int n, int c, int color[]) {
	int i,j;

	if(c >= min)
		return;
	if(n == N) {
		min <?= c;
		return;
	}	
	for(i=0; i<=c; i++) {
		for(j=0; j<n; j++)
			if(cross[n][j] && color[j] == i)
				break;
		if(j >= n) {
			color[n] = i;
			DFS(n+1, c>?(i+1), color);
			color[n] = -1;
		}
	}
}
			

int main() {
	int T,cas=1,i,j,k,color[16];
	
	freopen("testC.in", "r", stdin);
	freopen("testC.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(i=0; i<N; i++)
			for(j=0; j<K; j++)
				scanf("%d", &s[i][j]);
		memset(cross, 0, sizeof(cross));
		for(k=1; k<K; k++)
			for(i=0; i<N; i++)
				for(j=0; j<N; j++)
					if(i == j)
						continue;
					else {
						if((long long)(s[i][k-1]-s[j][k-1])*(s[i][k]-s[j][k]) <= 0) {
							cross[i][j] = 1;
	//						printf("%d %d\n", i, j);
						}
					}
	/*	printf("\n");
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++)
				printf("%d ", cross[i][j]);
			printf("\n");
		}
		printf("\n"); */
		min = 10000;
		memset(color, 0xff, sizeof(color));
		DFS(0, 0, color);
		printf("Case #%d: %d\n", cas++, min); 
	}
	return 0;
}
			
		
