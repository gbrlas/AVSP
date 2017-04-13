#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
string sei="welcome to code jam";
int dp[25][510];
int main()
{
	int i,j,k,n;vector <int> out;scanf("%d\n",&n);
	for(i=0;i<n;i++){
		string s;getline(cin,s);
		for(j=0;j<25;j++) for(k=0;k<510;k++) dp[j][k]=0;
		dp[0][0]=1;
		for(k=0;k<s.size();k++) for(j=0;j<20;j++){
//			cout<<j<<' '<<k<<' '<<dp[j][k]<<'\n';
			if(s[k]==sei[j]) dp[j+1][k+1]=(dp[j+1][k+1]+dp[j][k])%10000;
			dp[j][k+1]=(dp[j][k+1]+dp[j][k])%10000;
		}
		out.pb(dp[19][s.size()]);
	}
	for(i=0;i<n;i++){
		cout<<"Case #"<<i+1<<": ";
		for(j=0;j<4;j++){
			cout<<out[i]/1000;out[i]%=1000;out[i]*=10;
		}
		cout<<'\n';
	}

//	for(i=0;i<n;i++) cout<<out[i]<<'\n';
	return 0;
}
