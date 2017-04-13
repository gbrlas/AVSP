#include<iostream>
#include<string>
#include<vector>
using namespace std;

string p="welcome to code jam",s;
int dp[500][20];

int f(int ind1, int ind2)	{
	if(ind2==p.size()) return 1;
	if(ind1==s.size()) return 0;
	if(dp[ind1][ind2]!=-1)
		return dp[ind1][ind2];
	int ans=0;
	if(s[ind1]==p[ind2])	
		ans += f(ind1+1, ind2+1);
	ans += f(ind1+1, ind2);
	
	return dp[ind1][ind2]=ans%10000;
}

int main()	{
	
	freopen("3_small.in","rt",stdin);
	freopen("3_small.out","wt",stdout);
	
	int t;
	cin>>t;
	
	getline(cin,s);
	
	for(int tc=1;tc<=t;tc++)	{
	
		getline(cin,s);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %04d\n",tc,f(0,0)%10000);	
	}
	
	return 0;
}
