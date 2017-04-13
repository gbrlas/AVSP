#include<stdio.h>
int S;
void solve(){
	int i,N,x,mi=(1<<30),xo=0;
	S=0;
	scanf("%d",&N);
	for(i=0;i<N;++i){
		scanf("%d",&x);
		xo^=x;
		S+=x;
		if(mi>x)
			mi=x;
	}
	if(xo)
		S=-1;
	else
		S-=mi;
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;++i){
		solve();
		if(S==-1)
			printf("Case #%d: NO\n",i);
		else
			printf("Case #%d: %d\n",i,S);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
