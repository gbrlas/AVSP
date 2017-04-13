#include <stdio.h>
#include <string.h>
#define M 200
int mat[M],tmat[M];
int n,m;
int g[M][M];
int hungry_aug(int i) {
	int v,j;
	for (j = 0 ; j < m; j++)
		if ( g[i][j] && tmat[j]==0) {
			tmat[j]=1;v=mat[j];mat[j]=i;
			if (v==-1 || hungry_aug(v)) return 1;
			mat[j]=v;
		}
		return 0;
}
int hungry() {
	int i,k=0;
	memset(mat,-1,sizeof(mat));
	for (i = 0; i < n; i++) {
		memset(tmat,0,sizeof(tmat));
		k+=hungry_aug(i);
	}
	return k;
}
int map[M][M];
bool below(int x,int y,int c)
{
	for(int i=0;i<c;i++)
		if(map[x][i]>=map[y][i]) return false;
	return true;
}
int main()
{
	int T,i,j,r,c;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf("%d",&map[i][j]);
		memset(g,0,sizeof(g));
		for(i=0;i<r;i++)
			for(j=0;j<r;j++) if(j!=i && below(j,i,c))
				g[j][i] = true;
		n = m = r;
		printf("Case #%d: %d\n",ca,r-hungry());
	}
	return 0;
}