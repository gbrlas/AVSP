#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

double C,F,X;
int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%lf%lf%lf",&C,&F,&X);
		double now=2, ans=X/now, tt=0;
		for (int i=1; i<=500000; ++i){
			tt=tt+C/now; now=now+F;
			if (tt+X/now+1e-8<ans) ans=tt+X/now;
		}
		printf("Case #%d: %.7f\n", T, ans);
	}
}
