#include <iostream>
#include <fstream>
#include <limits>
#include <cmath>
using namespace std;

long double C, F, X;

long double getTime(long double x) {
	long double t1 = X / (2 + x * F);
	long double t2 = 0;
	for (int i = 0; i < x; ++i)
		t2 += C / (2 + i * F);
	return t1 + t2;
}

int main() {
	ofstream cout;
	cout.open("out.txt");
	int t;
	cin >> t;
	cout.precision(7);
	for (int i = 0; i < t; ++i) {
		cin >> C >> F >> X;
		long double ans = numeric_limits<long double>::infinity();
		for (int x = 0; x < X; ++x)
			ans = min(ans, getTime(x));
		cout << "Case #" << (i + 1) << ": " << fixed << ans << endl;
	}
	cout.close();
	return 0;
}
