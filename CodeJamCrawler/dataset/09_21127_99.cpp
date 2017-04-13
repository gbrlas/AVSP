#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const char w[20]="welcome to code jam";

char s[1000];
int dp[1000][20];
int task, ret;

int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n", &task);
	for (int tt=1; tt<=task; tt++){
		gets( s );
		ret = 0;
		memset( dp, 0, sizeof(dp) );
		for (int i=0; s[i]; i++){
			for (int j=0; j<=min( i, 18 ); j++)
			if ( s[i]==w[j] ){
				if ( j==0 ){
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = 0;
				for (int x=0; x<i; x++)
					(dp[i][j] += dp[x][j-1])%=10000;
			}
			ret = (ret+dp[i][18])%10000;
		}
		printf("Case #%d: %04d\n", tt, ret);
	}
	return 0;
}
