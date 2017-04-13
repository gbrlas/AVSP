//============================================================================
// Name        : Qual_B.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double rate, cost, delta, goal;
	int nc;
	cin >> nc;
	for(int cid=1;cid<=nc;++cid) {
		rate = 2.0;
		cin >> cost >> delta >> goal;
		double ans = 0;
		while(1) {
			double newRate = rate+delta;
			double t1 = goal/rate, t2 = cost/rate + goal/newRate;
			if(t1<t2) {
				ans += t1;
				break;
			} else {
				ans += cost/rate;
				rate = newRate;
			}
		}
		printf("Case #%d: %.7f\n", cid, ans);
	}
	return 0;
}
