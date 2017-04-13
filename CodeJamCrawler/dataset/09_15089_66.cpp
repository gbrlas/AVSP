#include<iostream>
#include<string>
using namespace std;
int dp[501][30];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int N;
	cin>>N;
	string tmp="welcome to code jam";
	int n=tmp.length();
	string q;
	getline(cin,q);
	for(int ind=1;ind<=N;ind++)
	{
		memset(dp,0,sizeof(dp));
		string str;
		getline(cin,str);
		for(int i=0;i<str.length();i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[i+1][j+1]=dp[i][j+1];
				if(str[i]==tmp[j])
				{
					if(j)dp[i+1][j+1]+=dp[i][j];
					else dp[i+1][j+1]++;
				}
				dp[i+1][j+1]%=10000;
			}
		}
		cout<<"Case #"<<ind<<": ";
		int res=dp[str.length()][tmp.length()];
		if(res<1000)cout<<"0";
		if(res<100)cout<<"0";
		if(res<10)cout<<"0";
		cout<<res<<endl;
	}
	return 0;
}