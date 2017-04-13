#include <iostream>
#include <iomanip>
#include <vector>

typedef long long int in;

using namespace std;

void testcase() {
	double C,F,X;
	cin >> C >> F >> X;
	// cout << "C " << C << " F " << F << " X " << X << endl;
	double R = 2.0;
	double opt = X/R;
	double T = 0;
	for(in i=0; i<X; i++) {
		double t = C/R;
		R+=F;
		T+=t;
		if(opt > T+X/R) {
			opt = T+X/R;
			// cout << "opt " << opt << endl;
		}
	}
	cout << opt;
}

int main() {
	in T;
	cin >> T;
	cout << setprecision(7) << fixed;
	for(int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		testcase();
		cout << endl;
	}
}