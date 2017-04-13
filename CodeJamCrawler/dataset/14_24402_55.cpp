#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	int t;
	cin >> t;

	for(int k = 0; k < t; ++k) {

		double c, f, x;

		cin >> c >> f >> x;

		int n = 0;

		double time_ = 0;

		while(x / (2.0 + n*f) > c / (2.0 + n*f) + x / (2.0 + (n+1)*f)) {
			time_ += c / (2.0 + n*f);
			++n;
		}

		time_ += x / (2.0 + n*f);


		cout << "Case #" << k+1 << ": ";
		cout.setf(ios::fixed);
		cout.precision(7);
		cout << time_ << endl;
	}

	return 0;

}