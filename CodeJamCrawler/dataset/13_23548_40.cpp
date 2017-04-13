#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAXN 100010
typedef  long long INT;

int judge(char str[]) {
	int idx = -1;
	if(str[0] == 'T') idx = 0;
	if(str[1] == 'T') idx = 1;
	if(str[2] == 'T') idx = 2;
	if(str[3] == 'T') idx = 3;
	if(idx >= 0) str[idx] = 'X';

	if(str[0] == 'X' && str[0] == str[1] && str[1] == str[2] 
		&& str[2] == str[3]) {
		if(idx >= 0) str[idx] = 'T';
		return 2;
	}
	
	if(str[0] == 'O' && str[0] == str[1] && str[1] == str[2] 
		&& str[2] == str[3]) {
		if(idx >= 0) str[idx] = 'T';
		return 0;
	}
	if(idx >= 0) {
		str[idx] = 'O';
		if(str[0] == 'X' && str[0] == str[1] && str[1] == str[2] 
		&& str[2] == str[3]) {
			if(idx >= 0) str[idx] = 'T';
			return 2;
		}
	
		if(str[0] == 'O' && str[0] == str[1] && str[1] == str[2] 
			&& str[2] == str[3]) {
			if(idx >= 0) str[idx] = 'T';
			return 0;
		}
	}

	if(idx >= 0) str[idx] = 'T';
	return 1;
}


int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
 	#endif
	
	char str[10][10];
	char tmp[10];
	int i,j;
	int T,t;
	while(scanf("%d",&T) == 1) {
		for(t = 1; t <= T; t++) {
			printf("Case #%d: ",t);
			for(i = 0; i < 4; i++)
				scanf("%s",str[i]);

			int rel = 1;
			for(i = 0; i < 4; i++) {
				rel = judge(str[i]);
				if(rel != 1)
					break;
			}
			
			if(rel == 1) {		
				for(i = 0; i < 4; i++) {
					tmp[0] = str[0][i]; tmp[1] = str[1][i];
					tmp[2] = str[2][i]; tmp[3] = str[3][i];
					rel = judge(tmp);
					if(rel != 1)
						break;
				}
			}

			if(rel == 1) {
				for(i = 0; i < 4; i++)
					tmp[i] = str[i][i];
				rel = judge(tmp);
				if(rel == 1) {
					tmp[0] = str[0][3]; tmp[1] = str[1][2];
					tmp[2] = str[2][1]; tmp[3] = str[3][0];
					rel = judge(tmp);
				}
			}

			if(rel == 1) {
				for(i = 0; i < 4; i++)
					for(j = 0; j < 4; j++)
						if(str[i][j] != 'X' && str[i][j] != 'O'
							&& str[i][j] != 'T') {
								rel = 3;
								break;
							}
			}

			if(rel == 0) printf("O won\n");
			else if(rel == 1) printf("Draw\n");
			else if(rel == 2) printf("X won\n");
			else if(rel == 3) printf("Game has not completed\n");



		
		
		}
	
	
	}

	
	
 	return 0;
}



