#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int n;
double x[3],y[3],r[3];

double sqr( double x ){
	return x*x;
}

double dist( double x1, double y1, double x2, double y2 ){
	return sqrt( sqr(x1-x2)+sqr(y1-y2) );
}

int main(){
	int test=0;
	scanf("%d", &test);
	for ( int T=1; T<=test; T++ ){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		for ( int i=0; i<n; i++ )
			scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
		if ( n==1 )
			printf("%.6lf\n", r[0]);
		else
			if ( n==2 )
				printf("%.6lf\n", max( r[0], r[1] ));
			else{
				double ans=1000000;
				double tmp=max((dist(x[1],y[1],x[2],y[2])+r[1]+r[2])/2, r[0]);
				if ( tmp<ans ) ans=tmp;
				tmp=max((dist(x[0],y[0],x[2],y[2])+r[0]+r[2])/2, r[1]);
				if ( tmp<ans ) ans=tmp;
				tmp=max((dist(x[0],y[0],x[1],y[1])+r[0]+r[1])/2, r[2]);
				if ( tmp<ans ) ans=tmp;
				printf("%.6lf\n", ans);
			}
	}
}
