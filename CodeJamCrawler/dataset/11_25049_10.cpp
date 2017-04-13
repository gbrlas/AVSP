#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

const int maxn=16;
int t,n,c[maxn],ans,sum;

void dfs(int a,int b,int sa,int sb,int dep)
{
	if(dep==n+1){
		if(a==b&&sa!=sum&&sb!=sum) 
			ans=max(ans,max(sa,sb));
		return;
	}
	dfs(a^c[dep],b,sa+c[dep],sb,dep+1);
	dfs(a,b^c[dep],sa,sb+c[dep],dep+1);
}

int main()
{
	scanf("%d",&t);
	fostream output;
	output.open("ansout.out");
	for(int ca=1;ca<=t;ca++){
		scanf("%d",&n); sum=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&c[i]);
			sum+=c[i];
		}
		ans=0;
		dfs(0,0,0,0,1);	
		//if(ans==0) printf("Case #%d: NO\n",ca);
		//else printf("Case #%d: %d\n",ca,ans);
		if(ans==0) output<<"Case #"<<ca<<": NO\n";
		else output<<"Case #"<<ca<<": "<<ans<<endl;
	}

}
