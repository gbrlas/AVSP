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
typedef long long lint;
vector <int> ca,cl;
int dp[110][110];
int dfs(int a,int b){
	if(dp[a][b]>-1) return dp[a][b];
	if(b-a==1) return 0;
	int i,ret=200000000;
	for(i=a+1;i<b;i++){
		ret=min(ret,ca[b]-(ca[a]+2)+dfs(a,i)+dfs(i,b));
	}
//	cout<<a<<' '<<b<<' '<<ret<<'\n';
	return dp[a][b]=ret;
}
int main()
{
	int i,j,k,n;vector <int> out;cin>>n;
	for(i=0;i<n;i++){
		int a,b,c;cin>>a>>b;ca=cl;ca.pb(0);
		for(j=0;j<b;j++){
			cin>>c;ca.pb(c);
		}
		ca.pb(a+1);sort(ca.begin(),ca.end());
		for(j=0;j<110;j++) for(k=0;k<110;k++) dp[j][k]=-1;
		out.pb(dfs(0,b+1));
	}
	for(i=0;i<n;i++) cout<<"Case #"<<i+1<<": "<<out[i]<<'\n';
	return 0;
}
