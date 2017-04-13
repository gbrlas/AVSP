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
//ll cuad()

bool es(ll rr,ll tt,ll mid){
	if((2*rr+2*mid-1)> tt/mid)
		return false;
	return true;
}
ll puede(ll rr,ll tt){
	ll low=0;
	ll hi=tt;
	ll mid ;
	
	if(es(rr,tt,tt))return tt;
	 mid=0;
	int cont=0;
	while(hi>=low && cont<100){
		//cout<<low<<" d "<<hi<<endl;
		mid=(hi+low)/2;
		//cout<<"mid "<<mid<<endl;
		//cout<<es(rr,tt,mid)<<endl;
		if(es(rr,tt,mid))
			low=mid;
		else
			hi=mid;
		cont++;
	}
	if(es(rr,tt,hi))mid=hi;
	else if(es(rr,tt,low))mid=low;
	return mid;
}
int main(){
	int cases;
	cin>>cases;

	f(t,1,cases+1){
	cin>>r>>tengo;
	/*
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
	*/
	ll res=puede(r,tengo);
	cout<<"Case #"<<t<<": ";

	cout<<res<<endl;
	}


}
