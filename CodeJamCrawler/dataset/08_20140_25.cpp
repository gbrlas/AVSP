#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <sstream>

using namespace std;

#define LL long long 
#define PII pair<int,int> 
#define VI vector<int> 
#define VPII vector<PII> 
#define eps 1e-9
#define inf int(1000000000)
#define nmax 20000
int test,t,dp[nmax][2],g[nmax],c[nmax],l[nmax],i,j,n,m,val,ans,le,ri;



int main()
{
	freopen("c:/input.txt","r",stdin);
	freopen("c:/output.txt","w",stdout);
	cin>>test;
	for ( t = 1; t <= test; t++)
	{	
			ans = 1000000;
			cout<<"Case #"<<t<<": ";
			scanf("%d%d",&m,&val);
			for (i = 0; i <= m; i++) 
			{
				g[i] = l[i] = -1;
				dp[i][0] = dp[i][1] = 1000000;
			}
			for (i = 1; i <= (m-1) / 2; i++)
			{
				scanf("%d%d",&g[i],&c[i]);
			}

			

			for (i = (m-1)/2 + 1; i <= m; i++)
			{
				scanf("%d",&l[i]);
				dp[i][l[i]] = 0;
			}
			
		
			for (i = m; i >= 1; i--)
			{
				if (i*2 > m) continue; 

				le = i*2;
				ri = i*2 + 1;
				
				if (g[i] == 0)
				{
					dp[i][0] = min(dp[i][0] , dp[le][0] + dp[ri][0]);

					dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][0]);

					dp[i][1] = min(dp[i][1], dp[le][0] + dp[ri][1]);

					dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][1]);

					if (c[i])
					{
						dp[i][0] = min(dp[i][0] , dp[le][1] + dp[ri][0] + 1) ;

						dp[i][0] = min(dp[i][0], dp[le][0] + dp[ri][0] + 1) ;

						dp[i][0] = min(dp[i][0], dp[le][0] + dp[ri][1] + 1);

						dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][1] + 1);	

					}

				} else
				{
					dp[i][0] = min(dp[i][0] , dp[le][1] + dp[ri][0]);

					dp[i][0] = min(dp[i][0], dp[le][0] + dp[ri][0]);

					dp[i][0] = min(dp[i][0], dp[le][0] + dp[ri][1]);

					dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][1]);	
					if (c[i])
					{
						dp[i][0] = min(dp[i][0] , dp[le][0] + dp[ri][0] + 1);

						dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][0] + 1);

						dp[i][1] = min(dp[i][1], dp[le][0] + dp[ri][1] + 1);

						dp[i][1] = min(dp[i][1], dp[le][1] + dp[ri][1] + 1);

					}
				}

				
			}
			if (dp[1][val] == 1000000) cout<<"IMPOSSIBLE"<<endl; else cout<<dp[1][val]<<endl;
	
	}
	return 0;
}