#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define m 10000

string w="welcome to code jam";

int dp[100][1000];

int main()
{
	int n,r,res;
	int i,j,k;
	string s;
	cin>>n;
	getline(cin,s);
	for(r=0;r<n;r++)
	{
		getline(cin,s);
		res=0;
		for(i=0;i<100;i++)for(j=0;j<1000;j++)dp[i][j]=0;
		for(i=0;i<s.size();i++)
		{
			if(w[0]==s[i])dp[1][i+1]=(dp[1][i]+1)%m;else dp[1][i+1]=dp[1][i];
			for(j=1;j<w.size();j++)
			{
				if(w[j]==s[i])
				{
					dp[j+1][i+1]=(dp[j+1][i]+dp[j][i+1])%m;
				}else
				{
					dp[j+1][i+1]=dp[j+1][i];
				}
			}
		}
		/*for(j=0;j<=w.size();j++)
		{
			for(i=0;i<=s.size();i++)
			{
				cout<<dp[j][i]<<" ";
			}
			cout<<endl;
		}*/
		stringstream ss;
		ss<<dp[w.size()][s.size()];
		ss>>s;
		while(s.size()<4)s="0"+s;
		cout<<"Case #"<<r+1<<": "<<s<<endl;
	}
}
