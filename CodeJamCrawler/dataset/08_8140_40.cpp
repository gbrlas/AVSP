#include<stdio.h>
#include<string.h>
#define maxn 3000
#define maxint 999999999


bool p[maxn][maxn];

bool output[maxn];

int q[maxn],last[maxn];

int i,j,n,m;

int make(){
	bool changed;
	int ans=0;
	memset(output,0,sizeof(output));
	do{
		changed=0;
		for(i=1;i<=m;i++)if(q[i]==0){
			if(last[i]==0)return -1;
			for(j=1;j<=m;j++){
				if(last[j]==last[i])q[j]=maxint;
				if(p[last[i]][j])q[j]--;
			}
			changed=1;
			ans++;
			output[last[i]]=1;
		}
	}while(changed);
	return ans;
}

int main(){
	int nn,ii,t,x,y;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d:",ii);
		scanf("%d %d",&n,&m);
		memset(last,0,sizeof(last));
		memset(q,0,sizeof(q));
		memset(p,0,sizeof(p));
		for(i=1;i<=m;i++){
			scanf("%d",&t);
			while(t--){
				scanf("%d %d",&x,&y);
				if(y==0)p[x][i]=1,q[i]++;
				else last[i]=x;
			}
		}
		int temp=make();
		if(temp<0){
			printf(" IMPOSSIBLE\n");
		}else {
			for(i=1;i<=n;i++)if(output[i])printf(" 1");
			else printf(" 0");
			printf("\n");
		}
	}
	return 0;
}

