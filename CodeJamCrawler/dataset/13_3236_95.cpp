#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,m,n;
int cnt=0;
int fie[101][101];
bool used[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


void cutx(int x,int k){
	bool f=false;
	bool ff=false;
	for(int i=1;i<=n;i++){
		if(fie[x][i]==k)f=true;
		if(fie[x][i]>k)ff=true;
	}
	if(f && !ff){
		for(int i=1;i<=n;i++){
			fie[x][i]=-1;
		}
	}
}

void cuty(int y,int k){
	bool f=false;
	bool ff=false;
	for(int i=1;i<=m;i++){
		if(fie[i][y]==k)f=true;
		if(fie[i][y]>k)ff=true;
	}
	if(f && !ff){
		for(int i=1;i<=m;i++){
			fie[i][y]=-1;
		}
	}
}

bool C(int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(fie[j][i]==k)return false;
		}
	}
	return true;
}

int main(void){
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		memset(fie,-1,sizeof(fie));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)scanf("%d",&fie[j][i]);
		}
		bool f=true;
		for(int k=1;k<=100;k++){
			if(!f)break;
			for(int i=1;i<=m;i++)cutx(i,k);
			for(int i=1;i<=n;i++)cuty(i,k);
			if(!C(k))f=false;
		}
		if(f)printf("Case #%d: YES\n",test);
		else printf("Case #%d: NO\n",test);
		
	}
	return 0;
}