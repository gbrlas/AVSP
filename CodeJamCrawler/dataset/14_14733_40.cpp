#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
struct node
{
	bool endpoint;
	int vec[26];
	node()
	{
		endpoint=false;
		for(int i=0;i<26;i++)
		{
			vec[i]=-1;
		}
	}
};
vector<node>nod[10];
void make(int id,int cur,string x,int len,int f)
{
	if(cur==len)
	{
		nod[f][id].endpoint=true;
		return;
	}
	int nxt=x[cur]-'A'; 
	if(nod[f][id].vec[nxt]!=-1)
	{
		make(nod[f][id].vec[nxt],cur+1,x,len,f);
	}
	else
	{
		nod[f][id].vec[nxt]=nod[f].size();
		nod[f].resize(nod[f].size()+1);
		make(nod[f][id].vec[nxt],cur+1,x,len,f);
	}
}
int main()
{
	int t;
	cin >> t;
	for(int cas = 1;cas<=t;cas++)
	{
		printf("Case #%d: ",cas);
		int m,n;
		cin >> m >> n;
		string a[10];
		for(int i=0;i<m;i++) cin >> a[i];
		int all = 1;
		for(int i=0;i<m;i++) all*=n;
		int res = 0, tot = 0 , d = 0;
		for(int i=0;i<all;i++)
		{
			int bel[10];
			int ch[10]={};
			int jj = i;
			for(int j=0;j<m;j++)
			{
				bel[j] = jj%n;
				ch[jj%n] ++;
				jj /= n;
			}
			int sum = 0;
			for(int j=0;j<n;j++) if(!ch[j]) goto nxt;
			for(int j=0;j<n;j++)
			{
				nod[j].clear();
				node x;
				nod[j].pb(x);
			}
			
			for(int j=0;j<m;j++)
			{
				make(0,0,a[j],a[j].size(),bel[j]);
			}
			for(int j=0;j<n;j++) sum+=nod[j].size();
			if(sum == res) tot++;
			if(sum > res) { tot = 1; res = sum;} nxt:;
		}
		cout << res << " " << tot << endl;
	}
}