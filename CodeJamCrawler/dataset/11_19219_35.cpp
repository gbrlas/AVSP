#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		vector<string> g(n);
		vector<double> wp(n, 0.0);
		vector<vector<double> > wpi(n);
		for (int i = 0; i < n; ++i) {
			cin >> g[i];
			
			int w = 0;
			int l = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == '0') {
					++l;
				} else if (g[i][j] == '1') {
					++w;
				}
			}
			
			wp[i] = 1.0*w/(w + l);
			wpi[i].resize(n, 0.0);
			for (int j = 0; j < n; ++j) {
				if (g[i][j] == '0') {
					wpi[i][j] = 1.0*w/(w + l - 1);
				} else if (g[i][j] == '1') {
					wpi[i][j] = 1.0*(w - 1)/(w + l - 1);
				}
			}
		}
		
		vector<double> owp(n, 0.0);
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] != '.') {
					owp[i] += wpi[j][i];
					++cnt;
				}
			}
			if (cnt > 0) {
				owp[i] /= cnt;
			}
		}
		
		cout << "Case #" << test << ":" << endl;
		for (int i = 0; i < n; ++i) {
			double oowp = 0.0;
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (g[i][j] != '.') {
					oowp += owp[j];
					++cnt;
				}
			}
			if (cnt > 0) {
				oowp /= cnt;
			}
			
			cout.precision(15);
			cout << 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp << endl;
		}
	}
}
