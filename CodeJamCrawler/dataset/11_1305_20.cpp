#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin>>t;
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		cin>>n;
		vector< vector< int > > v(n);
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			v[i].resize(n);
			for (int j = 0; j < n; ++j) {
				if (s[j] == '.') {
					v[i][j] = -1;
				} else {
					v[i][j] = s[j] - '0';
				}
			}
		}
		vector< double > wp(n);
		for (int i = 0; i < n; ++i) {
			int ct = 0, wct = 0;
			for (int j = 0; j < n; ++j) {
				if (v[i][j] >= 0) {
					++ct;
				}
				if (v[i][j] > 0) {
					++wct;
				}
			}
			wp[i] = double(wct) / double(ct);
		}
		vector< double > owp(n);
		for (int i = 0; i < n; ++i) {
			int ct = 0;
			double wct = 0.0;
			for (int j = 0; j < n; ++j) {
				if (v[i][j] >= 0) {
					int wpc = 0, wpt = 0;
					for (int k = 0; k < n; ++k) {
						if (k != i) {
							if (v[j][k] >= 0) {
								++wpc;
							}
							if (v[j][k] > 0) {
								++wpt;
							}
						}
					}
					++ct;
					wct += double(wpt) / double(wpc);
				}
			}
			owp[i] = double(wct) / double(ct);
		}
		vector< double > oowp(n);
		for (int i = 0; i < n; ++i) {
			int ct = 0;
			double wct = 0.0;
			for (int j = 0; j < n; ++j) {
				if (v[i][j] >= 0) {
					++ct;
					wct += owp[j];
				}
			}
			oowp[i] = double(wct) / double(ct);
		}
		cout<<"Case #"<<tt<<":"<<endl;
		vector< double > ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
			cout<<fixed<<setprecision(7)<<ans[i]<<endl;
		}
	}
    return 0;
}
