#include <iostream>
#include <fstream>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	ifstream cin("C-small.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	rep(tc, t) {
		int n, l, h;
		cin >> n >> l >> h;
		int f[10000];
		rep(i, n) {
			cin >> f[i];
		}
		bool found = false;
		int mn;
		for (int i = l; i <= h; ++i) {
			bool inval = false;
			rep(j, n)
				if (f[j] % i != 0 && i % f[j] != 0) {
					inval = true;
					break;
				}
			if (!inval) {
				found = true;
				mn = i;
				break;
			}
		}
		cout << "Case #" << tc + 1 << ": ";
		if (found)
			cout << mn << endl;
		else
			cout << "NO" << endl;
	}
}