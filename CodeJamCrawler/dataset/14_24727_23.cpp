#include<stdio.h>
int tcn,tc;
int a[510][510];
int b[1010][4];
int n,m,p;
int ans;
int cpable(int x,int y,int vx,int vy){
	if(x<0||y<0||x>=m||y>=n)return 0;
	if(a[x][y]==1)return 0;
	if(x==m-1)return 1;
	a[x][y]=1;
	if(cpable(x+vy,y-vx,vy,-vx))return 1;
	if(cpable(x+vx,y+vy,vx,vy))return 1;
	if(cpable(x-vy,y+vx,-vy,vx))return 1;
	return 0;
}
int main(){
	int i,j,k;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d%d",&n,&m,&p);
		for(i=0;i<p;i++){
			scanf("%d%d%d%d",&b[i][0],&b[i][1],&b[i][2],&b[i][3]);
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				a[i][j]=0;
			}
		}
		for(i=0;i<p;i++){
			for(j=b[i][1];j<=b[i][3];j++){
				for(k=b[i][0];k<=b[i][2];k++){
					a[j][k]=1;
				}
			}
		}
		ans=0;
		for(i=0;i<n;i++){
			ans+=cpable(0,i,1,0);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
}