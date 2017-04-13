#include<stdio.h>
const int dx[]={0,0,1,1};
const int dy[]={0,1,0,1};
char nr[60][60];
int R,C,T;
int fill(int x,int y){
	int xx,yy,ok=0;
	for(int i=0;i<4;++i){
		xx=x+dx[i];
		yy=y+dy[i];
		if(nr[xx][yy]=='#' && (1<=xx && xx<=R) && (1<=yy && yy<=C)){
			if(!i || i==3)
				nr[xx][yy]='/';
			if(i==1 || i==2)
				nr[xx][yy]='\\';
		}
		else
			ok=1;
	}
	return ok;
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int t,i,j,ok;
	scanf("%d",&T);
	for(t=1;t<=T;++t){
		scanf("%d%d",&R,&C);
		printf("Case #%d:\n",t);
		ok=1;
		fgets(nr[1]+1,10,stdin);
		for(i=1;i<=R;++i)
			fgets(nr[i]+1,C+10,stdin);
		for(i=1;i<=R && ok;++i){
			for(j=1;j<=C && ok;++j){
				if(nr[i][j]=='#')
					if(fill(i,j)){
						printf("Impossible\n");
						ok=0;
					}
			}
		}
		if(ok){
			for(i=1;i<=R;++i){
				for(j=1;j<=C;++j)
					printf("%c",nr[i][j]);
				printf("\n");
			}
		}
	}
	
	return 0;
}
