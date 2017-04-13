#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T;
	long double r, t, s1, s2, s;
	cin >> T;
	for(int i = 1; i<= T; i++) {
		cin >> r >> t;
		s1 = 1 - 2 * r;
		s1 /= 4;
		s2 = sqrt(4*(r*(r-1))+1+8*t);
		s2 /= 4;
		s = s1 + s2;
		cout << "Case #" << i << ": " << long(s) << endl;
	}
	return 0;
}
