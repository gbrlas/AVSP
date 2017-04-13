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
int memo[13][13];
int E,R,N;
int v[13];
int go(int pos,int ener){
	if(pos>=N)return 0;
	if(memo[pos][ener]!=-1)return memo[pos][ener];
	int res=0;
	f(i,0,ener+1)
		res=max(res,v[pos]*i+go(pos+1,min(E,ener-i+R)));
	
	return memo[pos][ener]=res;
}
int main(){
	int cases;
	cin>>cases;
	f(t,1,cases+1){
	cin>>E>>R>>N;
	f(i,0,N)cin>>v[i];
	clr(memo,-1);
	int res=go(0,E);
	cout<<"Case #"<<t<<": ";
	cout<<res<<endl;
	}
	return 0;
}
