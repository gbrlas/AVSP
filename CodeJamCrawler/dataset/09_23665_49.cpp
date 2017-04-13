#include <stdio.h>
#include <algorithm>

using namespace std;


int en,ek;
int flow[1000][1000];
int capa[1000][1000];
bool used[1000];

class D{
	public:
	int k[1000];
	bool operator < (const D &r) const{
		int i;
		for(i=0;i<ek-1;i++)
			if(k[i]!=r.k[i])
				return k[i]<r.k[i];
	}
};

D einfo[1000];

inline bool inter(int a,int b,int c,int d){
	if(a==c || b==d)
		return true;
	else if(a>c && b<d)
		return true;
	else if(a<c && b>d)
		return true;
	else
		return false;
}

inline bool over(int a,int b){
	int i;
	for(i=0;i<ek-1;i++)
		if(inter(einfo[a].k[i],einfo[a].k[i+1],einfo[b].k[i],einfo[b].k[i+1]))
			return true;
	return false;
}

bool dfs(int n){
	if(n==2*en+1)
		return true;
	else{
		int i;
		used[n]=true;
		for(i=0;i<2*en+2;i++)
			if(used[i]==false)
				if(flow[n][i]<capa[n][i])
					if(dfs(i)){
						flow[n][i]++;
						flow[i][n]--;
						return true;
					}
		return false;
	}
}

bool do_flow(){
	int i;
	for(i=0;i<2*en+2;i++)
		used[i]=false;
	return dfs(0);
}


int main(){
	int ecase,ecount;
	scanf("%d",&ecase);
	for(ecount=1;ecount<=ecase;ecount++){
		int i,j;
		scanf("%d%d",&en,&ek);
		for(i=0;i<en;i++){
			for(j=0;j<ek;j++)
				scanf("%d",&einfo[i].k[j]);
		}
		sort(einfo,einfo+en);
		for(i=0;i<2*en+2;i++)
			for(j=0;j<2*en+2;j++)
				capa[i][j]=flow[i][j]=0;
		for(i=1;i<=en;i++)
			capa[0][i]=1;
		for(i=en+1;i<=2*en;i++)
			capa[i][2*en+1]=1;
		for(i=0;i<en;i++)
			for(j=i+1;j<en;j++)
				if(!over(i,j))
					capa[i+1][en+1+j]=1;
		int ans=en;
		while(do_flow())
			ans--;
		printf("Case #%d: %d\n",ecount,ans);
	}

	return 0;
}
