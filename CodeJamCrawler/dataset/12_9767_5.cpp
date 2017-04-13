#include<stdio.h>
#include<string.h>

int n,d[10000],l[10000],D,u[10000];
inline bool p(int a,int dis){
	int max=d[a]+dis;
	if(max>=D)
		return 1;
	for(int i=a+1;d[i]<=max && i<n;i++){
		int z=d[i]-d[a]<l[i]?d[i]-d[a]:l[i];
		if(z>u[i]){
			if(p(i,z)) return 1;
			u[i]=z;
		}
	}
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int ntest=1;ntest<=t;ntest++){
		memset(u,0,10000);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&d[i],&l[i]);
		scanf("%d",&D);
		if(p(0,d[0]))
			printf("Case #%d: YES\n",ntest);
		else
			printf("Case #%d: NO\n",ntest);
	}
	return 0;
}
