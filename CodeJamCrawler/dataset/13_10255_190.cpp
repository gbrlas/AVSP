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
string arr[4];
int gana(char c){
	f(i,0,4){
		int ig=0;
		f(j,0,4)if(arr[i][j]==c || arr[i][j]=='T')ig++;

		if(ig==4)return 1;

		ig=0;
		f(j,0,4)if(arr[j][i]==c || arr[j][i]=='T') ig++;
		if(ig==4)return 1;

	}
	int ig=0;
	f(i,0,4) if(arr[i][i]==c || arr[i][i]=='T')ig++;
	if(ig==4)return 1;

	ig=0;
	f(i,0,4)if(arr[i][3-i]==c || arr[i][3-i]=='T')ig++;
	if(ig==4)return 1;
	return 0;
}
int main(){
	int cases;
	cin>>cases;
	f(t,1,cases+1){
		f(i,0,4)cin>>arr[i];
		int p=0,x=1,o=0;
		f(i,0,4)f(j,0,4)
			if(arr[i][j]=='.')p++;
		x=gana('X');
		o=gana('O');
		cout<<"Case #"<<t<<": ";
		if(x==0 && o==0){
			if(p)cout<<"Game has not completed"<<endl;
			else cout<<"Draw"<<endl;
		}
		else {
			if(x==1)cout<<"X won"<<endl;
			else cout<<"O won"<<endl;
		}
	}	
}
