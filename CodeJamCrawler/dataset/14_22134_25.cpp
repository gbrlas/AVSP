#include <cstdio>
#include <cstdlib>
using namespace std;
int T;
double C,F,X;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		double p=2,ti=0;
		scanf("%lf%lf%lf",&C,&F,&X);
		while(X/p>C/p+X/(p+F)){
			ti+=C/p;
			p+=F;
		}
		ti+=X/p;
		printf("Case #%d: %.7f\n",t,ti);
	}
	//system("pause");
}
