#include <iostream>
#include <cmath>
using namespace std;

int r, t;


int main(void) {
	int T;
	cin >> T;
	for (int ti=1; ti<= T; ++ti) {
		cin >> r >> t;
		int ans = sqrt((2*r-1)*(2*r-1)+8*t) - 2*r+1;
		cout << "Case #" << ti << ": " << ans/4 << endl;
	}

	return 0;
}