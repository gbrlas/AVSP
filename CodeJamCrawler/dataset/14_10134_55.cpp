#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		double c, f, x;
		cin >> c;
		cin >> f;
		cin >> x;
		bool found = false;
		double rate = 2.0;
		double r = 0;
		double lr = x / rate;
		double rr = 0;
		while (true) {
			double secs = c / rate;
			rate += f;
			double secs_all = x / rate;
			r += secs;
			rr = r + secs_all;
			if (rr > lr) {
				r = lr;
				break;
			}
			lr = rr;
		}
		cout << "Case #" << t << ": ";
		printf("%.7f", r);
		cout << endl;
	}
}
