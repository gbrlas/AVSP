#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;

struct Point {int x, y, r;} a[100];
int task, cs=0, n;
double ret;

double calc( Point a, Point b ){
	return ( sqrt( sqr(a.x-b.x)+sqr(a.y-b.y) )+a.r+b.r)*0.5;
}

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	for( scanf("%d", &task); task--; ){
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r );
		if ( n==1 ){
			ret = a[0].r;
		}else
		if ( n==2 ){
			ret = max( a[0].r, a[1].r );
		}else{
			ret = max( (double)a[2].r, calc( a[0], a[1] ) );
			ret <?= max( (double)a[1].r, calc( a[0], a[2] ) );
			ret <?= max( (double)a[0].r, calc( a[1], a[2] ) );
		}
		printf("Case #%d: %.6lf\n", ++cs, ret);
	}
	return 0;
}
