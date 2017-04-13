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
ll todos[10000010];
int tam;
string cad;
int ct;

bool pal(ll num){
	stringstream os;
	os<<num;
	cad=os.str();
	tam=cad.size();
	f(i,0,tam/2)if(cad[i]!=cad[tam-1-i])return false;
	return true;
}
int main(){
	int cases;
	ct=0;
	for(ll i=1;i<=10000010;i++){
			if(pal(i) && pal(i*i)){
				todos[ct++]=i*i;
			}
	}
	
	cin>>cases;
	ll A,B;
	
	//cout<<ct<<endl;
	//cout<<"fin"<<endl;
	f(t,1,cases+1){
		cin>>A>>B;
		int res=0;
		f(i,0,ct)if(todos[i]>=A && todos[i]<=B)res++;
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}

