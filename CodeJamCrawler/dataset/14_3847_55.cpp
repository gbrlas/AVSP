#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "set"
#include "vector"
#include "queue"
#include "map"
#include "list"
#include "string"
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define line puts("");
#define IN freopen("i.txt","r",stdin);
#define OUT freopen("o.txt","w",stdout);
#define N 1000000
//lower_bound binary_search push_back insert

ll a,b,i,j,n,m,k,p,q,l,r,temp,T,ans,len,C;
double c,f,x,s,t,v,minn;

int main(){
	// IN 
	// OUT
	sll(T);C=1;
	while(T--){
		printf("Case #%lld: ",C++);
		scanf("%lf%lf%lf",&c,&f,&x);
		v=2;
		s=x/v;
		v+=f;
		t=(x/v)+(c/2);
		while(s>=t){
			s=t;
			t-=(x/v);
			t+=(c/v);
			v+=f;
			t+=(x/v);

		}
		printf("%.7lf\n", s);
	}
	return 0;
}














