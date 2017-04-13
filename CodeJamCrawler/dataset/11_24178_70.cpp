#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("C-small.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int n;
		cin >> n;
		int sum = 0, mn = 10000000, xor = 0;
		for (int i = 0; i < n; ++i) {
			int c;
			cin >> c;
			sum += c;
			if (mn > c) mn = c;
			xor ^= c;
		}
		cout << "Case #" << tc + 1 << ": ";
		if (xor == 0) {
			cout << sum - mn << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}