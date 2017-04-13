#include <cstdio>
#include <iostream>
using namespace std;
#define Mod 10000
int dp[505][20];
char a[1000];
char b[] = "welcome to code jam";
int M = (int)strlen(b);
int N;
int f(int i,int j)
{
	if(j==M)
		return 1;
	if(i>=N || j>M)
		return 0;
	int &x = dp[i][j];
	if(x!=-1)
		return x;
	int r = 0;
	if(a[i] == b[j])
		r = f(i+1,j+1);
	r+= f(i+1,j);

	return x = r%Mod;
}
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC;
	scanf("%d ",&TC);
	for(int t=1;t<=TC;++t)
	{
		gets(a);
		N = (int)strlen(a);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %04d\n",t,f(0,0));
	}
	return 0;
}