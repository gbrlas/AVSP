#include<stdio.h>
#define maxn 11000
#define maxint 11000


int p[maxn][2],q[maxn];

int C[maxn];

int i,j,n,m;

inline void prepare(){
	for(i=m+1;i<=n;i++){
		p[i][q[i]]=0;
		p[i][1-q[i]]=maxint;
	}
}

int mymax(int a,int b){return a>b?a:b;};

int mymin(int a,int b){return a<b?a:b;}

inline void make(){
	int l,r,k,temp;
	for(i=m;i;i--){
		l=i*2;r=l+1;
		if(C[i]==0){
			if(q[i]==0){
				k=0;
				p[i][k]=p[l][k]+p[r][k];
				p[i][1-k]=mymin(p[l][1-k]+p[r][1-k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]));
			}else {
				k=1;
				p[i][k]=p[l][k]+p[r][k];
				p[i][1-k]=mymin(p[l][1-k]+p[r][1-k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]));
			}
		}else {
			if(q[i]==0){
				k=0;
				p[i][k]=p[l][k]+p[r][k];
				
					temp=mymin(p[l][k]+p[r][k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]))+1;
				if(temp<p[i][k])p[i][k]=temp;
				p[i][1-k]=mymin(p[l][1-k]+p[r][1-k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]));
			
			}else {
				k=1;
				p[i][k]=p[l][k]+p[r][k];
				
					temp=mymin(p[l][k]+p[r][k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]))+1;
				
				if(temp<p[i][k])p[i][k]=temp;
				p[i][1-k]=mymin(p[l][1-k]+p[r][1-k],mymin(p[l][k]+p[r][1-k],p[l][1-k]+p[r][k]));
			
			}
		}
		if(p[i][0]>n)p[i][0]=maxint;
		if(p[i][1]>n)p[i][1]=maxint;
	}
}


int main(){
	//freopen("a.txt","r",stdin);
	int ii,nn,a,b;
	scanf("%d",&nn);
	for(ii=1;ii<=nn;ii++){
		printf("Case #%d: ",ii);
		scanf("%d %d",&n,&a);
		m=(n-1)/2;
		for(i=1;i<=m;i++){
			scanf("%d %d",&q[i],&C[i]);
		}
		for(i=m+1;i<=n;i++)scanf("%d",&q[i]);
		prepare();
		make();
		if(p[1][a]<=n)
		printf("%d\n",p[1][a]);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}