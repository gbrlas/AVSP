#include <string>
#include <cmath>
#include <iostream>

using namespace std;

bool ck(unsigned long long x) {
	unsigned long long tmp = 0, tmp1=x;
	while (x) {
		tmp *= 10;
		tmp += x%10;
		x /= 10;
	}
	if (tmp1==tmp) return 1;
	return 0;
}

int main(void) {
	int t;
	unsigned long long a, b, xa, xb, c;
	unsigned long long x;
	unsigned long long tms;
	cin >> t;
	for (int ti=1; ti<=t; ++ti) {
		tms = 0;
		cin >> a >> b;
		xa = sqrt(a-1)+1;
		xb = sqrt(b);
		for (c=xa; c<=xb; ++c) {
			if (!ck(c)) continue;
			if (ck(c*c)) ++tms;
		}
		cout << "Case #" << ti << ": " <<tms << endl;
	}
}