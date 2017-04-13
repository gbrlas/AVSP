#include <iostream>
using namespace std;

int t,n;
int a[30],ans;

void dfs(int usr1,int usr2,int infact,int i){
	if (i==n+1){
		if (usr1!=usr2||usr1==0) return;
		if (infact>ans) ans=infact;
		return;
	}
	dfs(usr1^a[i],usr2,infact+a[i],i+1);
	dfs(usr1,usr2^a[i],infact,i+1);
}

int main(){
	scanf("%d",&t);
	for (int ti=1;ti<=t;ti++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		dfs(0,0,0,1);
		if (ans==0) printf("Case #%d: NO\n",ti);
		else printf("Case #%d: %d\n",ti,ans);
	}
}
