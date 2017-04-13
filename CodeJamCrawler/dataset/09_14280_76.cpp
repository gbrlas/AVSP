#include <stdio.h>

char pattern[] = " welcome to code jam";
char text[501];
int dp[21];

int main(){
    int T, cc;
    scanf(" %d ", &T);
    for(cc = 1; cc <= T; ++cc){
	fgets(text, sizeof(text), stdin);

	int i, j;
	dp[0] = 1;
	for(i = 1; i < 20; ++i)
	    dp[i] = 0;

	for(i = 0; text[i]; ++i){
	    for(j = 19; j > 0; --j)
		if(text[i] == pattern[j]){
		    dp[j] += dp[j - 1];
		    if(dp[j] >= 10000)
			dp[j] %= 10000;
		}
	}

	printf("Case #%d: %04d\n", cc, dp[19]);
    }

    return 0;
}
