#include <cstdio>

double c[50][50];
double f[50];
int n, tc;

int main(){
	for ( int i=0; i<=40; i++ ){
		c[i][0]=1; c[i][i]=1;
		for ( int j=1; j<i; j++ )
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	int test=0;
	int T=0;
	scanf("%d", &test);
	while ( test-- ){
		scanf("%d %d", &n, &tc);
		f[0]=0;
		for ( int i=1; i<=n; i++ ){
			double sum=0;
			for ( int j=1; j<=i && j<=tc; j++ )
				sum+=(f[i-j]+1)*(c[i][j]*c[n-i][tc-j]/c[n][tc]);
			double p=c[n-i][tc]/c[n][tc];
			f[i]=(sum+p)/(1-p);
		}
		printf("Case #%d: %.7lf\n", ++T, f[n]);
	}
}
