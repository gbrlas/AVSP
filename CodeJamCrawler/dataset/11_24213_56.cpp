#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

bool check[1000005];

long long gcd(long long x, long long y) {
	if (x % y == 0)
		return y;
	return gcd(y, x %y);
}

int main() {
	ifstream cin("C-small.in");
	ofstream cout("output.txt");
	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i < 1000001; i += 2) {
		if (!check[i]) {
			prime.push_back(i);
			for (int j = i * 3; j < 1000001; j += i + i) {
				check[j] = true;
			}
		}
	}
	int t;
	cin >> t;
	rep(tc, t) {
		long long n;
		cin >> n;
		cout << "Case #" << tc + 1 << ": ";
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		int s = 1;
		for (int i = 0; i < prime.size(); ++i) {
			long long temp = n;
			int c = 0;
			while (temp >= prime[i]) {
				temp /= prime[i];
				c++;
			}
			if (c > 1)
				s += c - 1;
		}
		cout << s << endl;
	}
}