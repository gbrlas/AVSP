#include<stdio.h>
#include<algorithm>
using namespace std;
int tqn,tqi,i,j,n,k,s,t,ret;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=0;tqi<tqn;tqi++){
		scanf("%d%d%d",&n,&s,&t);
		ret=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k<3*t-2&&k>=max(0,t-2)+max(0,t-2)+t&&s){
				--s;
				++ret;
			}else if(k>=3*t-2)++ret;
		}
		printf("Case #%d: %d\n",tqi+1,ret);
	}
	return 0;
}