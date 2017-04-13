#include <iostream>
#include <iomanip>
using namespace std;

int solve(int test) {
	double c, f, x;
	cin >> c >> f >> x;

	double init[100000];
	init[0] = 1/2.0;
	for (int i = 1; i < 100000; i++)
		init[i] = init[i-1] + 1/(2.0+i*f);

	double min = x/2.0;
	for (int i = 0; i < 100000; i++) {
		double temp = c*init[i] + x/(2.0+(i+1)*f);
		if (temp < min) 
			min = temp;
	}
	cout << "Case #" << test << ": ";
	cout << setprecision(7) << fixed << min << endl;
	return 0;
}

int main() {
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
		solve(i + 1);
	return 0;
}
