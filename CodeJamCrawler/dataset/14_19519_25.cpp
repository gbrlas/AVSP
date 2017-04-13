#include <stdio.h>
double sol, time, C, F, X, K, T;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int runs, tn;
	for (scanf("%d",&tn), runs = 1; runs <= tn; runs++) {
		scanf("%lf%lf%lf",&C,&F,&X);
		K = 2;
		T = 0;
		sol = 1000000000;
		bool sw = 1;
		for (int farm = 0; sw; farm++) {
			time = T + X/K;
			if (sol > time) sol = time;
			else sw = 0;
			T += C/K;
			K += F;
		}
		printf("Case #%d: %.7lf\n",runs,sol);
	}
	fcloseall();
	return 0;
}