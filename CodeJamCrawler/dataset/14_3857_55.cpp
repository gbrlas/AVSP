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

ll a,b,i,j,n,m,k,p,q,l,r,temp,t[2010],tt[2010],T,ans,len,C;
double x[1005],y[1005];
int main(){
	// IN 
	// OUT
	sll(T);C=1;
	while(T--){
		printf("Case #%lld: ",C++);
		sll(n);a=b=0;
		rep(i,n){scanf("%lf",&x[i]);}
		rep(i,n){scanf("%lf",&y[i]);}
		sort(x,x+n),sort(y,y+n);\
		i=0;
		for (int k=n-1;k>=0;k--){
			if (x[k+i] < y[k])
			i++;
		}
		j = 0;
		for (int k=n-1;k>=0;k--){
			if (x[k] > y[k+j])
			j++;
		}
		printf("%lld %lld\n", n-i, j);
	}
	return 0;
}














