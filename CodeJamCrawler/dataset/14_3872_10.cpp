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
#define N 105
#define L 26
//lower_bound binary_search push_back insert

ll a,b,i,j,n,m[N][N],k,q,size[N],temp,T,ans,len[N],C,f[N][N];
char str[N][N];

int main(){
	// IN 
	// OUT
	sll(T);C=1;
	while(T--){
		printf("Case #%lld: ",C++);
		sll(n);clr(f,0);clr(size,0);
		rep(i,n){
			ss(str[i]);
			temp=strlen(str[i]);
			rep(j,temp){
				size[str[i][j]-'a']++;
			}
		}
		ans=0;
		rep(i,26){
			if(size[i]<n){ans=-1;break;}
		}
		clr(m,0);clr(size,0);
		vector<char> tt[N];
		rep(i,n){
			temp=strlen(str[i]);
			char t=str[i][0];
			ll c=1;
			rep(j,temp){
				if(t==str[i][j]){
					m[i][j]=c;
				}
				else{
					m[i][j]=++c;
					t=str[i][j];
				}
			}
			rep(j,temp){
				tt[i].push_back(str[i][j]);
			}
			tt[i].resize(distance(tt[i].begin(),unique (all(tt[i]))));
			if(i){
				if(ans!=c){
					ans=-1;break;
				}
			}
			size[i]=ans=c;
		}
		rep(i,n-1){
			if(tt[0]!=tt[i+1]){ans=-1;break;}
		}
		if(ans==-1){
			printf("Fegla Won\n");
		}
		else{
			ans=0;clr(len,0);
			rep(i,n){
				rep(j,size[i]){
					len[j]+=count(m[i],m[i]+N,j+1);
				}
			}
			rep(i,N){
				if(len[i]){
					len[i]/=n;
				}
			}
			rep(i,n){
				rep(j,size[i]){
					ans+=abs(len[j]-count(m[i],m[i]+N,j+1));
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}














