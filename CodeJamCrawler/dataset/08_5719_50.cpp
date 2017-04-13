#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int nq,ns;
string eng[100];
map<string,int> m;
int arr[1000];
int dp[100][1000];

int f(int last,int curq)	{
	
	if(curq == nq) return 0;

	if(dp[last][curq]!=-1) return dp[last][curq];

	if(arr[curq]!=last) return dp[last][curq]=f(last,curq+1);

	int ans=100000;
	for(int i=0;i<ns;i++)	{
		if(arr[curq]==i) continue;
		ans = min(ans,f(i,curq+1)+1);
	}

	return dp[last][curq]=ans;
}

int main()	{

	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	int n,i,c,sz;
	string s;

	cin>>n;

	for(c=1;c<=n;c++)	{
		
		cin>>ns;
		m.clear();
		sz=0;
		getline(cin,s);
		for(i=0;i<ns;i++) {
			getline(cin,s);
			m[s]=sz++;
		}

		cin>>nq;
		getline(cin,s);
		for(i=0;i<nq;i++) {
			getline(cin,s);
			arr[i] = m[s];
		}

		memset(dp,-1,sizeof(dp));

		int ans=100000;
		for(i=0;i<ns;i++) ans=min(ans,f(i,0));

		cout<<"Case #"<<c<<": "<<ans<<endl;

	}
	
	return 0;
}