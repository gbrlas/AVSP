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
ll arr[23];
map<ll,int> esta;
int n;
int main(){
	cin>>cases;
	f(ii,0,cases){
		cin>>n;
		int r1=-1,r2=-1;
		f(i,0,n)cin>>arr[i];
	//	cout<<"fin"<<endl;
		esta.clear();
		f(mask,1,(1<<n)){
			ll s=0;
			f(i,0,n)if(mask&(1<<i))s+=arr[i];
			if(esta.count(s)){
				r1=esta[s];
				r2=mask;
				break;
			}
			else
				esta[s]=mask;
		}
		cout<<"Case #"<<ii+1<<":"<<endl;
		if(r1!=-1){
			bool pri=true;
			f(i,0,n)if(r1&(1<<i)){
				if(!pri)cout<<" ";
				pri=false;
				cout<<arr[i];
			}
			cout<<endl;
			pri=true;
			f(i,0,n)if(r2&(1<<i)){
				if(!pri)cout<<" ";
				pri=false;
				cout<<arr[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<"Impossible"<<endl;
		}
	}
   return 0;
}

