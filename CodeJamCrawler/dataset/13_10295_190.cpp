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
int key[23];
vector <int> tiene[23];
char memo[1<<20];
int n,k;
int dp[1<<20];
char go(int mask,map<int,int> tengo){
	
	if(mask==0)return 1;

	if(memo[mask]!=-1)return memo[mask];
	
	char res=0;

	f(i,0,n){
		if(res==1)break;
		if(mask&(1<<i) && tengo[ key[i] ] > 0){

			tengo[ key[i] ]--;
		   
			f(j,0,tiene[i].size())
				tengo[tiene[i][j]]++;	
			
			res=go(mask-(1<<i),tengo);
			if(res==1){
				dp[mask]=i;
			}
			//falta recuperar el camino
			tengo[ key[i] ]++;
			f(j,0,tiene[i].size())
				tengo[tiene[i][j]]--;	
		}
	}
	return memo[mask]=res;

}

void recu(int mask){
	if(mask==0)return ;
	cout<<" "<<dp[mask]+1;
	mask=mask-(1<<dp[mask]);
	recu(mask);
}
int main(){
	int cases;
	cin>>cases;
	int kk,val;
	f(t,1,cases+1){
		cin>>k>>n;
		clr(memo,-1);
		f(i,0,n)tiene[i].clear();

		map<int,int> te;
		te.clear();
		f(i,0,k){
			cin>>val;
			te[val]++;
		}

		f(i,0,n){
			cin>>key[i];
			cin>>kk;
			f(j,0,kk){
				cin>>val;
				tiene[i].pb(val);
			}
		}
		int m=(1<<n);
		m--;
		int res=go(m,te);
		cout<<"Case #"<<t<<":";
		if(res==1){
			recu(m);
			cout<<endl;
		}
		else cout<<" IMPOSSIBLE"<<endl;
	}
	return 0;
}
