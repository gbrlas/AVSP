#include<stdio.h>
#include<algorithm>
using namespace std;
int tqn,tqi,k,i,j,d[111111],l[111111],c[111111],n,ans,L[111111];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=0;tqi<tqn;tqi++){
		scanf("%d",&n);                                             
		for(i=1;i<=n;i++){scanf("%d%d",&d[i],&l[i]);c[i]=0;L[i]=l[i]*(i==1);}
		scanf("%d",&k);
		c[1]=1;ans=0;L[1]=min(L[1],d[1]);
		for(i=1;i<=n;i++)if(c[i])for(j=i+1;j<=n;j++)if(d[j]-d[i]<=L[i]){
			c[j]=1;
			L[j]=max(L[j],min(l[j],d[j]-d[i]));
		}
		for(i=1;i<=n;i++)if(c[i]==1&&k-d[i]<=L[i])ans=1;
		printf("Case #%d: ",tqi+1);
		if(!ans)puts("NO");else puts("YES");
	}
	return 0;
}