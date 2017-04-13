#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const double zero=1e-6;

char M[1010][1010];
double S[1010][1010],XS[1010][1010],YS[1010][1010];
int n,m,d;

bool ok( int l ){
	for ( int i=l; i<=n; ++i )
		for ( int j=l; j<=m; ++j ){
			double sumx=XS[i][j]-XS[i-l][j]-XS[i][j-l]+XS[i-l][j-l]-M[i][j]*i-M[i-l+1][j]*(i-l+1)-M[i][j-l+1]*i-M[i-l+1][j-l+1]*(i-l+1);
			double sumy=YS[i][j]-YS[i-l][j]-YS[i][j-l]+YS[i-l][j-l]-M[i][j]*j-M[i-l+1][j]*j-M[i][j-l+1]*(j-l+1)-M[i-l+1][j-l+1]*(j-l+1);
			double sumw=S[i][j]-S[i-l][j]-S[i][j-l]+S[i-l][j-l]-M[i][j]-M[i-l+1][j]-M[i][j-l+1]-M[i-l+1][j-l+1];
			/*if (l==5 && i==6 && j==6 )
				printf("%.4lf %.4lf %.4lf\n",sumx,sumy,sumw);*/
			if ( fabs(sumx*2-(i+i-l+1)*sumw)<zero && fabs(sumy*2-(j+j-l+1)*sumw)<zero ) return true;
		}
	return false;
}

int main(){
	int test=0;
	scanf("%d",&test);
	for ( int T=1; T<=test; ++T ){
		printf("Case #%d: ", T);
		scanf("%d %d %d",&n,&m,&d);
		for (int i=1; i<=n; ++i )
			for ( int j=1; j<=m; ++j ){
				char x;
				scanf(" %c",&x);
				M[i][j]=x-'0';
				S[i][j]=M[i][j]+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
				XS[i][j]=M[i][j]*i+XS[i-1][j]+XS[i][j-1]-XS[i-1][j-1];
				YS[i][j]=M[i][j]*j+YS[i-1][j]+YS[i][j-1]-YS[i-1][j-1];
			}
		int ans=0;
		for ( int k=min(n,m); k>2; --k )
			if ( ok(k) ){
				ans=k; break;
			}
		if ( ans )
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
}
