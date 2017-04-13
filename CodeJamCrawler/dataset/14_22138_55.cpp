#include <iostream>
using namespace std;
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		long double c, f, x;
		cin >> c >> f >> x;
		
		int n = 0; //number of factories purchased
		long double current_rate = 2.;
		long double tn = 0.; //time to buy n factories
		long double besttime = tn + x/current_rate; //best current method of getting x cookies
		while (true) {
			//buy a factory
			tn += c/current_rate;
			n += 1;
			current_rate += f;
			long double alttime = tn + x/current_rate;
			if (alttime <= besttime) {
				besttime = alttime;
			} else {
				break;
			}
		}
		cout.precision(20);
		cout << "Case #" << (i+1) << ": " << besttime << endl;
	}
	return 0;
}
