#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
int T;
cin >> T;
for(int i = 1; i<=T; i++) {
	long double X, C, F, ans = 0, n;
	cin >> C >> F >> X;
	n = (X / C) - (2 / F) - 1;
	n = ceil(n);
	if(n<0)
		n = 0;
	for(int j = 0; j<n; j++) {
		ans += C / ((long double)2 + ((long double)j*F));
	}
	ans += X / ((long double)2 + (n*F));
	std::cout << std::fixed;
	cout << "Case #" << i << ": " << std::setprecision(7) << ans << endl;
}
}