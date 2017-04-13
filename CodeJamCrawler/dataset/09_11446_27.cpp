#include <iostream>
#include <sstream>

using namespace std;

int a[100];
char s[100];
char vis[11][50000000];
//bool  dp[11][10000000];
bool ok(int b,int n)
{
	if(vis[b][n] == -2)
		return vis[b][n] = 0;
	
	if(vis[b][n]!=-1)
		return vis[b][n];
	vis[b][n] = -2;
	int k=0;
	if(n==1)
		return vis[b][n] = 1;
	
	int x = n;
	while(n)
	{
		k+= (n%b)*(n%b);
		n/=b;
	}
	return vis[b][x] = ok(b,k);
 }
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out_large.txt","wt",stdout);
	memset(vis,-1,sizeof(vis));
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
				cerr<<t<<endl;
				printf("Case #%d: %d\n",t++,i);
				break;
			}
		}
	}
	return 0;
}
