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

ll a,b,i,j,n,m,k,p,q,l,r,temp,t[4],T,ans,len,C;

int main(){
	//IN 
	//OUT
	sll(T);C=1;
	while(T--){
		printf("Case #%lld: ",C++);
		sll(n);
		rep(i,4)rep(j,4){if(i==n-1)sll(t[j]);else scanf("%*d");}
		sort(t,t+4);
		sll(m);ans=0;len=0;
		rep(i,4)rep(j,4){
			if(i==m-1){
				sll(temp);
				if(binary_search(t,t+4,temp)){
					len++;ans=temp;
				}
			}
			else scanf("%*d");
		}
		
		if(!len){
			printf("Volunteer cheated!\n");
		}
		else if(len==1){
			printf("%lld\n", ans);
		}
		else if(len>1){
			printf("Bad magician!\n");
		}
	}
	return 0;
}














