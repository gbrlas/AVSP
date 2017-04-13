#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cout << "Case #" << test << ": ";

		long long n, p;
		cin >> n >> p;

		if (p == 1) {
			cout << 0 << " " << 0 << endl;
		} else if (p == (1 << n)) {
			cout << ((1 << n) - 1) << " " << ((1 << n) - 1) << endl;
		} else {
			long long g = 0;
			long long c = 0;

			long long p1 = 1;
			long long p2 = 1 << (n - 1);
			long long posg = p2;
			long long posc = p1;
			do {
				if (posg < p) {
					g += p1 << 1;
				}
				if (posc < p) {
					c += p2;
				}
				p2 >>= 1;
				p1 <<= 1;
				posg += p2;
				posc += p1;
			} while (p2 > 0);

			cout << g << " " << c << endl;
		}
	}
}
