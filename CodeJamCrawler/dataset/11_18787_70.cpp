#include<stdio.h>
int N,sol[110];
inline int modul(int x){
	if(x<0)
		return -x;
	return x;
}
void solve(){
	int i,poz,p0=1,t0=0,p1=1,t1=0,d;
	char P;
	scanf("%d",&N);
	sol[0]=0;
	for(i=1;i<=N;++i){
		scanf(" %c%d",&P,&poz);
		if(P=='O'){
			d=modul(poz-p0);
			if(sol[i-1]-t0>d)
				d=0;
			else
				d-=sol[i-1]-t0;
			sol[i]=sol[i-1]+d+1;
			t0=sol[i];
			p0=poz;
		}
		else{
			d=modul(poz-p1);
			if(sol[i-1]-t1>d)
				d=0;
			else
				d-=sol[i-1]-t1;
			sol[i]=sol[i-1]+d+1;
			t1=sol[i];
			p1=poz;
		}
	}
}
int main(){
	freopen("d.i","r",stdin);
	freopen("d.o","w",stdout);
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;++i){
		solve();
		printf("Case #%d: %d\n",i,sol[N]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
