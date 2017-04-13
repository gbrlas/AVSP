#include <stdio.h>
#include <math.h>

const double EPS=1.0e-10;
const double FINF=1.0e10;

double ex[100],ey[100],er[100];
int en;
bool mark[110];
double ans;


double f(int a,int b){
	double dx=ex[a]-ex[b];
	double dy=ey[a]-ey[b];
	return (er[a]+er[b]+sqrt(dx*dx+dy*dy))/2;
}

inline double max(double a,double b){
	if(a>b)
		return a;
	else
		return b;
}

inline double minn(double &a,double b){
	if(b<a)
		a=b;
}

int main(){
	int i,j,k,l,m,n;
	int ecase,ecount;
	scanf("%d",&ecase);
	for(ecount=1;ecount<=ecase;ecount++){
		scanf("%d",&en);
		for(i=0;i<en;i++)
			scanf("%lf%lf%lf",&ex[i],&ey[i],&er[i]);
		if(en==1)
			ans=er[0];
		else if(en==2)
			ans=max(er[0],er[1]);
		else{
			ans=FINF;
			minn(ans, max(er[0], f(1, 2)));
			minn(ans, max(er[1], f(0, 2)));
			minn(ans, max(er[2], f(0, 1)));
		}
		printf("Case #%d: %lf\n",ecount,ans);
	}
	return 0;
}
