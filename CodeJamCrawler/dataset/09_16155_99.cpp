#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N,cas=1,i,j,dp[501][3],len;
	char seq[501];

//	freopen("testC.in", "r", stdin);
//	freopen("testC.out", "w", stdout);	
	scanf("%d", &N);
	getchar();
	while(1) {
		gets(seq);
		len = strlen(seq);
		memset(dp, 0, sizeof(dp));
		for(i=0; i<=len; i++) {
			switch(seq[i]) {
				case 'w':
					dp[i][0] += 1;
					break;
				case 'e':
					for(j=0; j<len; j++) {
						if(seq[j] == 'w')
							dp[i][0] += dp[j][0];
						if(seq[j] == 'm')
							dp[i][1] += dp[j][0];
						if(seq[j] == 'd')
							dp[i][2] += dp[j][0];
					}
					break;
				case 'l':
					for(j=0; j<len; j++)
						if(seq[j] == 'e')
							dp[i][0] += dp[j][0];
					break;
				case 'c':
					for(j=0; j<len; j++) {
						if(seq[j] == 'l')
							dp[i][0] += dp[j][0];
						if(seq[j] == ' ')
							dp[i][1] += dp[j][1];
					}
					break;
				case 'o':
					for(j=0; j<len; j++) {
						if(seq[j] == 'c') {
							dp[i][0] += dp[j][0];
							dp[i][2] += dp[j][1];
						}
						if(seq[j] == 't')
							dp[i][1] += dp[j][0];
					}
					break;
				case 'm':
					for(j=0; j<len; j++) {
						if(seq[j] == 'o')
							dp[i][0] += dp[j][0];
						if(seq[j] == 'a')
							dp[i][1] += dp[j][0];
					}
					break;
				case ' ':
					for(j=0; j<len; j++) {
						if(seq[j] == 'e') {
							dp[i][0] += dp[j][1];
							dp[i][2] += dp[j][2];
						} 
						if(seq[j] == 'o')
							dp[i][1] += dp[j][1];
					}
					break;
				case 't':
					for(j=0; j<len; j++) 
						if(seq[j] == ' ')
							dp[i][0] += dp[j][0];
					break;
				case 'd':
					for(j=0; j<len; j++)
						if(seq[j] == 'o')
							dp[i][0] += dp[j][2];
					break;
				case 'j':
					for(j=0; j<len; j++)
						if(seq[j] == ' ')
							dp[i][0] += dp[j][2];
					break;
				case 'a':
					for(j=0; j<len; j++)
						if(seq[j] == 'j')
							dp[i][0] += dp[j][0];
					break;
				case '\0':
					for(j=0; j<len; j++)
						if(seq[j] == 'm')
							dp[i][0] += dp[j][1];
					break;
			}
			for(j=0; j<3; j++)
				dp[i][j] %= 10000;
		}
		printf("Case #%d: %04d\n", cas, dp[len][0]);
		if(cas == N)
			break;
		cas++;
	}
}
		
						
					
