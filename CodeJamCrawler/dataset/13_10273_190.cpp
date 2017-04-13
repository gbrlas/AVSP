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
int gras[110][110];
int memo[103][103][103][103];
int n,m;
int go(int x1,int y1,int x2,int y2){
	if(x1>=x2 && y2>=y2)return 1;
	if(memo[x1][x2][y1][y2]!=-1)return memo[x1][x2][y1][y2];
	int res=0;
	//filas
	f(i,x1,x2+1){
		if(res==1)break;
		bool igual=true;
		f(j,y1+1,y2+1)if(gras[i][y1]!=gras[i][j])igual=false;
		if(igual){
			if(go(x1,i-1,y1,y2)==1 && go(i+1,x2,y1,y2)==1)
				res=1;
		}
	}

	//columnas
	f(i,y1,y2+1){
		if(res==1)break;
		bool igual=true;
		f(j,x1+1,x2+1)if(gras[x1][i]!=gras[j][i])igual=false;
		if(igual){
			if(go(x1,x2,y1,i-1)==1 && go(x1,x2,i+1,y2)==1)
				res=1;
		}
	}

	return memo[x1][x2][y1][y2]=res;

}
bool pode1(int x,int y ){
	f(i,1,n+1)if(gras[i][y]>gras[x][y])return false;
	return true;
}
bool pode2(int x,int y){
	f(j,1,m+1)if(gras[x][j] > gras[x][y])return false;
	return true;
}
int main(){
	int cases;
	cin>>cases;
	f(t,1,cases+1){
		cin>>n>>m;

		f(i,1,n+1)f(j,1,m+1)cin>>gras[i][j];
		//clr(memo,-1);
		//int res=go(1,1,n,m);
		bool res=true;
		f(i,1,n+1)f(j,1,m+1){
			if(!res)break;
			 if(!pode1(i,j) && !pode2(i,j))
				 res=false;
		}
		cout<<"Case #"<<t<<": ";	
		if(res)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
