#include<stdio.h>
int h[105][105];
int row[105],col[105];
#define max(x,y) ( (x)>(y)?(x):(y) )
int main(){
	int t,ca=1,i,j,n,m;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++){
		bool ans=true;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)row[i]=0;
		for(j=0;j<m;j++)col[j]=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&h[i][j]);
				row[i]=max(row[i],h[i][j]);
				col[j]=max(col[j],h[i][j]);
			}
		}
		for(i=0;ans && i<n;i++){
			for(j=0;ans && j<m;j++){
				if(h[i][j]!=row[i] && h[i][j]!=col[j]){
					ans=false;
					break;
				}
			}
		}
		if(ans)printf("Case #%d: YES\n",ca);
		else printf("Case #%d: NO\n",ca);
	}
	return 0;
}
