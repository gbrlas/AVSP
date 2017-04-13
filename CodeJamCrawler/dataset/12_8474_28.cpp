#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
int cases;
#define maxn 1003
int n;
vector <int> adj[maxn];
int memo[1003][1003];
int caminos(int a,int b){
	if(a==b)return 1;
	if(memo[a][b]!=-1)return memo[a][b];
	int res=0;
	f(i,0,adj[a].size()){
		res+=caminos(adj[a][i],b);
		if(res>=2)
			res=2;
	}
	if(res>=2)
		res=2;
	return memo[a][b]=res;
}
int main(){
	cin>>cases;
	f(t,1,cases+1){
		cin>>n;
		clr(memo,-1);
		f(i,0,n)adj[i].clear();
		int m,b;
		f(i,0,n){
			cin>>m;
			f(j,0,m){
				cin>>b;
				adj[i].pb(b-1);
			}
		}

		bool es=false;
		f(i,0,n){
			if(es)break;
			f(j,0,n){
			if(es)break;
			if(i!=j)if(caminos(i,j)>=2)es=true;
			
			}
		}
		cout<<"Case #"<<t<<":";
		if(es)cout<<" Yes"<<endl;
		else cout<<" No"<<endl;
	}
}
