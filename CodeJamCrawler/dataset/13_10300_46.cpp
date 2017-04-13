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
ll r,tengo;
int main(){
	int cases;
	cin>>cases;

	f(t,1,cases+1){
	cin>>r>>tengo;
	bool pode=true;
	ll r1=r,r2=r+1;
	ll res=0;
		while(1){
			pode=true;
			//cout<<"ad"<<endl;
			//cout<<r1<<" "<<r2<<endl;
			ll cant=r2*r2-r1*r1;
			//cout<<cant<<endl;
			if(cant<=tengo){
				res++;
				pode=true;
				tengo-=cant;
			}
			else
				break;
			
			r1+=2;
			r2+=2;
		}
	cout<<"Case #"<<t<<": ";
	//poner re
	cout<<res<<endl;
	}


}
