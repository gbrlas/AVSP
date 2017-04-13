/*
ID: BigGuava
PROG: C
LANG: C++
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>
#include <set>
#include <map>
#include <string>
using namespace std;

//#define LOCAL_JUDGE
//#define ___SMALL

#pragma warning(disable:4996 4101)



int main()
{
#ifdef LOCAL_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
#ifdef ___SMALL
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
#else
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
#endif

#endif

	int tot,i,j,k,m,n,a,b,c,d;
	char s[1000];
	int dp[1100][32];
	char *p="$welcome to code jam";

	gets(s);
	sscanf(s,"%d",&tot);
	for (a=1;a<=tot;a++) {
		printf("Case #%d: ",a);
		gets(s+1);
		n=strlen(s+1);

		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (i=1;i<=n;i++) {
			for (k=0;k<32;k++) dp[i][k]=dp[i-1][k];
			for (k=1;p[k];k++) if (p[k]==s[i]) {
				dp[i][k]+=dp[i-1][k-1];
			}
			for (k=0;k<32;k++) dp[i][k]%=10000;
		}

		printf("%04d\n",dp[n][19]);
	}

	return 0;
}	

/*

*/