#include <stdio.h>

// google code jam 2013, qualification round, problem B
// israel leiva - april 13th
int main(void){
	int T, tc = 0, N, M, i, j, k, min;
	int lawn[100][100];
	short pattern;
	
	scanf("%d\n", &T);
	while(T){
		tc++;
		
		scanf("%d %d\n", &N, &M);
		printf("Case #%d: ", tc);
		
		min = 100;
		
		// read input and save the min
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				scanf("%d", &lawn[i][j]);
				if(lawn[i][j] < min)
					min = lawn[i][j];
			}
		}

		
		// the min is the last cutting so it's the only one who
		// should keep the pattern
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				pattern = 1;
				if(lawn[i][j] == min){
					pattern = 0;
					// check for pattern
					
					// rows
					for(k = 0; k < M; k++)
						if(lawn[i][k] != min)
							break;
						
					if(k == M)
						pattern = 1;
					
					// columns
					if(!pattern){
						for(k = 0; k < N; k++)
							if(lawn[k][j] != min)
								break;
					
						if(k == N)
							pattern = 1;
					}
								
					// if the number does not belong to any pattern then it's not a valid cutting	
					if(!pattern)
						break;
				}
			}
			if(!pattern)
				break;
		}
		
		if(!pattern)
			printf("NO\n");
		else
			printf("YES\n");
		

		
		T--;
	}
}
