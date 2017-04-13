#include<cstdio>

int n;
const int N = 101;
double wp[N], owp[N],rip[N],oowp[N];
char buf[N][N];
int won[N],played[N];
void solve(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s",buf[i]);
	}
	for(int i=0; i<n; i++){
		won[i]=played[i]=0;
		for(int j=0; j<n; j++){
			if(buf[i][j]=='1') won[i]++;
			if(buf[i][j]!='.') played[i]++;
		}
		wp[i]=1.*won[i]/played[i];
	}
	for(int j=0; j<n; j++){
		double l = 0, m = 0;
		for(int i=0; i<n; i++) if(buf[i][j]!='.'){
			int a = won[i], b=played[i];
			if(buf[i][j]=='1') a--;
			if(buf[i][j]!='.') b--;
			m++;
			l+=1.*a/b;
		}
		owp[j]=l/m;
	}
	for(int i=0; i<n; i++){
		double s=0,m=0;
		for(int j=0; j<n; j++) if(buf[i][j]!='.'){
			s+=owp[j]; m++;
		}
		oowp[i]=s/m;
	}
	for(int i=0; i<n; i++){
		//printf("%lf %lf %lf -> %lf\n",wp[i],owp[i],oowp[i],0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
		printf("%.8lf\n",0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
	}
}

main(){
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++){
		printf("Case #%d:\n", i);
		solve();
	}
}
