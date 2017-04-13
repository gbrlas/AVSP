#include <iostream>

using namespace std;

int main() {
	double C, F, X;
	int T;
	cin>>T;
	for (int k = 1; k <= T; k++) {
		cin>>C>>F>>X;
		double tt = 0;
		double cs = 2;
		while(1) {
			double ct = X / cs;
			double nt = C / cs + X / (cs + F); 
			if (nt < ct) {
				tt += C/cs;
				cs += F;
			} else {
				tt += ct;
				break;
			}
		}
		printf("Case #%d: %.7lf\n",k, tt);
	}
}