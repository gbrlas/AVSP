#include <iostream>
#include <stdio.h>
#define REP(op,s,t) for (op=(s);op<=(t);op++) 
#define MXN 2010
using namespace std;
typedef long long LL;
long T,TP,r,k,n,i,j,pp;
long a[MXN],to[MXN];
LL ans,sz,sum[MXN];


int main(){
	scanf("%d",&T);
    REP(TP,1,T){
		scanf("%d%d%d",&r,&k,&n);
		REP(i,0,n-1) scanf("%d",&a[i]);
		REP(i,0,n-1){
			sz=a[i];j=i+1;
			pp=1;to[i]=i;sum[i]=a[i];
			while (++pp<=n&&sz+a[j%n]<=k){
				sz+=a[(j%n)];sum[i]=sz;to[i]=j%n;j=(j+1)%n;
			}
		}	
		ans=0;j=0;
		REP(i,1,r){
			ans+=sum[j];
			j=(to[j]+1)%n;
		}
		printf("Case #%d: %d\n",TP,ans);
	}
}
