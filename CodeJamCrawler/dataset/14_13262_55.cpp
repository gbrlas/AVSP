#include <cstdio>
#include <vector>
using namespace std;


int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 0; casenum < testcase; ++casenum) {

		double c, f, x;
		double cps = 2;

		scanf("%lf%lf%lf", &c, &f, &x);

		double now = 0;

		while(true) {

			double t = c / cps;

			if(x / cps < t + x / (cps + f))
				break;

			cps += f;
			now += t;
		}

		double ans = now + x / cps;

		printf("Case #%d: %.8f\n", casenum + 1, ans);
	}

	return 0;
}