#include<stdio.h>
char S[1000];
double nr[510][510];
int R,C,D,K;
bool merge(int L){
	double i,j,x,y;
	double solx,soly,cx,cy;
	int xx,yy;
	for(i=1;i+L-1<=R;++i){
		for(j=1;j+L-1<=C;++j){
			cx=i-1+((double)L)/2;
			cy=j-1+((double)L)/2;
			solx=soly=0;
			for(x=i;x<i+L;++x){
				for(y=j;y<j+L;++y){
					if(x==i && y==j)
						continue;
					if(x==i && y==j+L-1)
						continue;
					if(x==i+L-1 && y==j)
						continue;
					if(x==i+L-1 && y==j+L-1)
						continue;
					xx=(int)x;
					yy=(int)y;
					solx+=(x-cx-0.5)*nr[xx][yy];
					soly+=(y-cy-0.5)*nr[xx][yy];
				}
			}
			if(solx==0 && soly==0)
				return true;
		}
	}
	return false;
}
void solve(){
	int u;
	u=R<C?R:C;
	/*while(p<u){
		mij=(p+u)/2;
		if(merge(mij))
			p=mij;
		else
			u=mij-1;
	}*/
	for(K=u;K>=3;--K)
		if(merge(K))
			return;
	K=0;
}
int main(){
	freopen("blade.in","r",stdin);
	freopen("blade.out","w",stdout);
	int i,j,T,tt;
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt){
		scanf("%d%d%d",&R,&C,&D);
		fgets(S+1,10,stdin);
		for(i=1;i<=R;++i){
			fgets(S+1,1000,stdin);
			for(j=1;j<=C;++j){
				nr[i][j]=((double)D+S[j]-'0');
			}
		}
		solve();
		if(K)
			printf("Case #%d: %d\n",tt,K);
		else
			printf("Case #%d: IMPOSSIBLE\n",tt);
	}
	
	return 0;
}
