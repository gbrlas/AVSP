#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

map< string , int > m;
int N,M;
int query[1005];
int server[105];
int dp[105][1005];
const int INF = 1000000;
int f(int,int);
int main()
{
	freopen("inA.in","rt",stdin);
	freopen("outA.out","wt",stdout);
	int TC,tc;
	int i;
	int ans;
	//char s[205];
	//scanf("%d",&TC);
	string s;
	//cin>>TC;
	getline(cin,s);
	stringstream iss;
	iss<<s<<" ";
	iss>>TC;
	for(tc=1;tc<=TC;tc++)
	{
		//scanf("%d",&n)
		m.clear();
		//cin>>N;
		iss.clear();
		getline(cin,s);
		//stringstream iss1(s);
		iss<<s<<" ";
		iss>>N;
		for(i=0;i<N;i++)
		{
			//scanf("%s",&s);
			getline(cin,s);
			m[s] = i;
			server[i] = m[s];
		}
		//cin>>M;
		//stringstream iss2(s);
		iss.clear();
		getline(cin,s);
		iss<<s<<" ";
		iss>>M;
		for(i=0;i<M;i++)
		{
			getline(cin,s);
			query[i] = m[s];
		}
		memset(dp,-1,sizeof(dp));
		ans = INF;
		for(i=0;i<N;i++)
			ans = min( f(0,i) , ans);
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
}
int f(int ind,int l)
{
	if(ind == M) return 0;
	if( dp[ind][l] != -1)
		return dp[ind][l];
	int i,r1=INF,r2=INF;
	if(server[l] == query[ind])
	{
		for(i=0;i<N;i++)
			if(i!=l)
				r1 = min( f(ind+1,i)+1 , r1);
	}
	else r2 = f(ind+1,l);

	return dp[ind][l] = min(r1,r2);

}
