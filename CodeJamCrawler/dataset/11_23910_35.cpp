#include<cstdio>
#include<algorithm>
using namespace std;

int n;
double d;

const int N = 202;
int P[N],V[N];
double eps=1e-8;

double mabs(double x){
	if(x>0) return x;
	return -x;
}

bool check(double t){
	double left = -1e9;
	for(int i=0; i<n; i++){
		for(int j=0; j<V[i]; j++){
			double pos = P[i], newpos;
			newpos = max(left+d, pos-t);
			if((i>0 || j>0) && mabs(pos-newpos)>t+eps) {
				return false;
			}
			left = newpos;
		}
	}
	return true;
}

void solve(){
	scanf("%d %lf",&n,&d);
	double L=0, R=0;
	for(int i=0; i<n; i++){
		scanf("%d %d",&P[i], &V[i]);
		R+=V[i]*d*2;
	}
	double mid;
	while(R-L>eps){
		mid = (L+R)/2.;
		if(check(mid)) R=mid;
		else L=mid;
	}
	printf("%.8lf\n",(L+R)/2.);
}

main(){
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: ", i);
		solve();
	}
}
