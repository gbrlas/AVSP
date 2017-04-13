#include <iostream>
#include <sstream>

using namespace std;

int a[100];
char s[100];
char vis[11][10000000];
bool  dp[11][10000000];
bool ok(int b,int n)
{
	if(vis[b][n]==1)
		return dp[b][n];
	if(vis[b][n] == 2)
	{
		vis[b][n] = 1;
		return dp[b][n] = 0;
	}
	vis[b][n] = 2;
	int k=0;
	if(n==1)
	{
		vis[b][n]=1;
		return dp[b][n] = 1;
	}
	int x = n;
	while(n)
	{
		k+= (n%b)*(n%b);
		n/=b;
	}
	vis[b][x] = 1;
	return dp[b][x] = ok(b,k);
 }
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int TC,n,i,j;
	scanf("%d ",&TC);
	int t = 1;
	while(TC--)
	{
		gets(s);
		stringstream iss(s);
		n =0;
		while(iss>>a[n])++n;
		for(i=2; ; i++)
		{
			for(j=0;j<n;j++)
				if(!ok(a[j],i))
					break;
			if(j==n)
			{
				printf("Case #%d: %d\n",t++,i);
				break;
			}
		}
	}
	return 0;
}