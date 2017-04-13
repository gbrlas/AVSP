#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
const double eps=1e-6;
double f[512][512];
double x[512][512];
double y[512][512];
double w[512][512];
int main(){
	int cases;
	scanf("%d",&cases);
	for(int T=1;T<=cases;++T){
		int R,C,D;
		scanf("%d%d%d",&R,&C,&D);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(f,0,sizeof(f));
		for(int i=1;i<=R;++i){
			for(int j=1;j<=C;++j){
				int ww;
				scanf("%1d",&ww);
				w[i][j]=ww+D;
				x[i][j]=x[i][j-1]+x[i-1][j]-x[i-1][j-1]+(ww+D)*i;
				y[i][j]=y[i][j-1]+y[i-1][j]-y[i-1][j-1]+(ww+D)*j;
				f[i][j]=f[i][j-1]+f[i-1][j]-f[i-1][j-1]+(ww+D);
			}
		}
		int ans=-1;
		for(int i=3;i<=R;++i){
			for(int j=3;j<=C;++j){
					for(int k=3;k<=i&&k<=j;++k){
							if(ans>=k)continue;
							double xx=x[i][j]-x[i-k][j]-x[i][j-k]+x[i-k][j-k];
							double yy=y[i][j]-y[i-k][j]-y[i][j-k]+y[i-k][j-k];
							double dd=f[i][j]-f[i-k][j]-f[i][j-k]+f[i-k][j-k];
							xx-=w[i][j]*i+w[i-k+1][j]*(i-k+1)+w[i][j-k+1]*i+w[i-k+1][j-k+1]*(i-k+1);
							yy-=w[i][j]*j+w[i-k+1][j]*j+w[i][j-k+1]*(j-k+1)+w[i-k+1][j-k+1]*(j-k+1);
							dd-=w[i][j]+w[i-k+1][j]+w[i][j-k+1]+w[i-k+1][j-k+1];
//							printf("(%d %d):",i,j);
//							printf("(%f,%f,%f)",xx,yy,dd);
							xx/=dd,yy/=dd;
//							printf("(%f,%f)\n",xx,yy);
							if(fabs(xx-i+(k-1)/2.0)<eps&&fabs(yy-j+(k-1)/2.0)<eps){
								ans=k;
							}
					}
			}
		}
		printf("Case #%d: ",T);
		if(ans!=-1)printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}


