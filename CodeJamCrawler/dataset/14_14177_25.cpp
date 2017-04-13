#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T;

	cin >> T;
	for(int t = 0; t < T; t++) {
		double C, F, X;
		cin >> C >> F >> X;
		double ans = 1e10;
		double hoge = 0;
		double cps = 2;

		while(1) {
			double tmp;
			tmp = hoge + X / cps;

			if(ans > tmp) {
				ans = tmp;
			}
			else
				break;

			hoge += C / cps;
			cps += F;
		}

		cout << "Case #" << t + 1 << ": ";
		printf("%.10f\n", ans);
	}
}
