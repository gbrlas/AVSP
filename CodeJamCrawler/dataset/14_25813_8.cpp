#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>

#define LL long long
#define MP make_pair
#define inf 1123123123
#define ii pair<int,int>
using namespace std;
LL n,i,j,a,b,c,d;

void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int main(){
LL t,z;
	OPEN();
	scanf("%lld",&t);
	for(z=1;z<=t;z++){
		scanf("%lld/%lld",&a,&b);
		if(a==0){
			printf("Case #%lld: impossible\n",z);
			continue;
		}
		LL tmp=__gcd(a,b);
		a/=tmp;
		b/=tmp;
		if(__builtin_popcount(b)!=1){
			printf("Case #%lld: impossible\n",z);
			continue;
		}
		else{
			int ans=0,k=0;
			while(b>0){
				if(a%2==0)	ans++;
				else ans=0;
				k++;
				a/=2;
				b/=2;
			}
			//cout<<k<<" "<<ans<<endl;
			//if(k-1!=ans) ans++;
			printf("Case #%lld: %d\n",z,ans);
		}
	}
	return 0;
}