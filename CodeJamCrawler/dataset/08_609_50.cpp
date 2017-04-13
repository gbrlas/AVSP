#include <cstdio>
#include <map>
#include <string>
using namespace std;

int dp[1001][100];

char eng[101][101];
char buf[101];
int main() {
	int s,q,cases;
	scanf("%d\n",&cases);
	for(int ct=1;ct<=cases;ct++) {
	scanf("%d\n",&s);
	for(int i=0;i<s;i++) {
		gets(eng[i]);
	}
	memset(dp,-1,sizeof(dp));
	scanf("%d\n",&q);
	if(q==0) {
		printf("Case #%d: 0\n",ct);
		continue;
	}
	gets(buf);
	for(int j=0;j<s;j++) {
		if(strcmp(buf,eng[j])!=0) {
			dp[1][j]=0;
		}
	}

	for(int i=2;i<=q;i++) {
		gets(buf);
		for(int j=0;j<s;j++) {
			if(strcmp(buf,eng[j])!=0) {
				if(dp[i-1][j]!=-1) {
					if(dp[i][j]==-1) {
						dp[i][j]=dp[i-1][j];
					}else{
						dp[i][j]=min(dp[i][j],dp[i-1][j]);
					}
				}else{
					int tt=99999;
					for(int k=0;k<s;k++) {
						if(k!=j&&dp[i-1][k]!=-1) {
							tt=min(tt,dp[i-1][k]);
						}
					}
					if(tt<9999)
					if(dp[i][j]==-1) {
						dp[i][j]=tt+1;
					}else{
						dp[i][j]=min(dp[i][j],tt+1);
					}
				}
			}else{
				dp[i][j]=-1;
			}
		}
	}
	int ans=999999;
	for(int i=0;i<s;i++)
		if(dp[q][i]>-1)
		ans=min(ans,dp[q][i]);
	printf("Case #%d: %d\n",ct,ans);
	}
	return 0;
}
				

