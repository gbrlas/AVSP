#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

double solve(double C, double F, double X) {
	double min = std::numeric_limits<double>::infinity();
	int farms = 0;

	while(true) {
		double t = 0;
		double production = 2;

		for(int i = 0; i < farms; i++) {
			t += C/production;
			production += F;
		}

		t += X/production;

		farms++;

		min = fmin(t, min);

		if(t > min) break;
	};

	return min;
}

int main() {
	int cases;
	cin >> cases;

	for(int current_case = 1; current_case <= cases; current_case++) {
		double C, F, X;
		cin >> C >> F >> X;
		double solution = solve(C, F, X);
		cout << "Case #" << current_case << ": "
		     << fixed << setprecision(7) << solution << endl;
	}

	return 0;
}