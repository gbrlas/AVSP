#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define REP(i,n) for(int i=0,_n=(n);i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_n=(b);i<=_n;i++)

char x[550];
char a[25];
int dp[550][25],lena,lenb;
bool vis[550][25];

int code(int pos, int jam){
	if(jam==lena)return 1;
	if(pos>=lenb)return 0;
	
	if(vis[pos][jam]!=0)return dp[pos][jam];
	
	FOR(i,pos,lenb-1){
		if(x[i]==a[jam])dp[pos][jam]+=code(i+1,jam+1);
		dp[pos][jam]%=10000;
	}
	
	vis[pos][jam]=1;
	return dp[pos][jam];	
}

int main(){
	strcpy(a,"welcome to code jam");
	lena=strlen(a);
	int n;
	scanf("%d\n",&n);
	REP(i,n){
		gets(x);
		lenb=strlen(x);
	
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		
		__int64 res=code(0,0);
		printf("Case #%d: ",i+1);
		res%=10000;
		printf("%I64d",res/1000);
		res%=1000;
		printf("%I64d",res/100);
		res%=100;
		printf("%I64d",res/10);
		res%=10;
		printf("%I64d\n",res);

	}

return 0;
}
