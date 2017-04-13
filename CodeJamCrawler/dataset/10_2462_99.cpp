#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int g[2000];
long long next[2000],num[2000];
int i,j,k,l,o,p,n,m;

void makenext(int i){
	long long q,w;
	for (q=i,num[i]=0;;){
		if (num[i]+g[q]>p||(q==i&&num[i]!=0)) {
			next[i]=q;
			//cout<<i<<' '<<next[i]<<' '<<num[i]<<endl;
			return;
		}
		num[i]+=g[q];
		q++;
		if (q==n) q=0;
	}
}

int main(){
	int TT;
	scanf("%d",&TT);
	for (int T=1;T<=TT;T++){
		cout<<"Case #"<<T<<": ";
		scanf("%d%d%d",&m,&p,&n);
		for (i=0;i<n;i++) scanf("%d",&g[i]);
		for (i=0;i<n;i++) makenext(i);
		long long ans,ci,cj,ck;
		ans=0;
		i=0;
		for (;m;m--){
			ans+=num[i];
			i=next[i];
		}
		cout<<ans<<endl;
	}
    return 0;
}
