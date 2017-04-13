#include<stdio.h>
int S;
char sol[110],c[50][3],d[50][2];
void solve(){
	int i,C,D,N,j,k,x,ok;
	S=0;
	scanf("%d",&C);
	for(i=0;i<C;++i)
		scanf(" %c%c%c",&c[i][0],&c[i][1],&c[i][2]);
	scanf("%d",&D);
	for(i=0;i<D;++i)
		scanf(" %c%c",&d[i][0],&d[i][1]);
	scanf("%d ",&N);
	for(i=1;i<=N;++i){
		scanf("%c",&sol[++S]);
		if(S==1)
			continue;
		ok=1;
		while(S>1 && ok){
			for(ok=0,k=0;!ok && k<C;++k){
				if((c[k][0]==sol[S] && c[k][1]==sol[S-1]) || (c[k][0]==sol[S-1] && c[k][1]==sol[S])){
					sol[--S]=c[k][2];
					ok=1;
				}
			}
		}
		ok=1;
		for(x=0;x<D && ok;++x){
			for(j=1;j<=S && ok;++j){
				for(k=j+1;k<=S && ok;++k){
					if((sol[j]==d[x][0] && sol[k]==d[x][1]) || (sol[j]==d[x][1] && sol[k]==d[x][0]))
						ok=0;
				}
			}
		}
		if(!ok)
			S=0;
	}
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;++i){
		solve();
		printf("Case #%d: [",i);
		if(S){
			printf("%c",sol[1]);
			for(int j=2;j<=S;++j)
				printf(", %c",sol[j]);
		}
		printf("]\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
